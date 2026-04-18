#include "ImageLoader.h"

#include <stdexcept>
#include <cstring>
#include <algorithm>
#include <iostream>

// ---------------------------------------------------------------------------
// Construtor
// ---------------------------------------------------------------------------

ImageLoader::ImageLoader(const std::string &fileName)
{
    load(fileName);
}

// ---------------------------------------------------------------------------
// getGLFormat
// ---------------------------------------------------------------------------

unsigned int ImageLoader::getGLFormat() const
{
    switch (m_channels)
    {
    case 1:  return GL_LUMINANCE;
    case 2:  return GL_LUMINANCE_ALPHA;
    case 3:  return GL_RGB;
    case 4:  return GL_RGBA;
    default: throw std::runtime_error("ImageLoader: número de canais inválido");
    }
}

// ---------------------------------------------------------------------------
// Helpers de swap de bytes
// ---------------------------------------------------------------------------

unsigned short ImageLoader::swapShort(unsigned short v)
{
    return static_cast<unsigned short>(((v & 0x00FF) << 8) | ((v & 0xFF00) >> 8));
}

unsigned long ImageLoader::swapLong(unsigned long v)
{
    return ((v & 0x000000FFUL) << 24)
         | ((v & 0x0000FF00UL) <<  8)
         | ((v & 0x00FF0000UL) >>  8)
         | ((v & 0xFF000000UL) >> 24);
}

// ---------------------------------------------------------------------------
// readRow — descomprime ou lê verbatim uma linha de um canal
// ---------------------------------------------------------------------------

void ImageLoader::readRow(FILE *f,
                          unsigned char *buf,
                          int y, int z,
                          unsigned short type,
                          const std::vector<unsigned long> &rowStart,
                          const std::vector<unsigned long> &rowSize,
                          std::vector<unsigned char>       &tmpBuf) const
{
    const bool rle = ((type & 0xFF00) == 0x0100);

    if (rle)
    {
        const int idx = y + z * m_height;
        fseek(f, static_cast<long>(rowStart[idx]), SEEK_SET);
        fread(tmpBuf.data(), 1, rowSize[idx], f);

        const unsigned char *src = tmpBuf.data();
        unsigned char       *dst = buf;

        while (true)
        {
            const unsigned char pixel = *src++;
            int count = pixel & 0x7F;
            if (!count) break;

            if (pixel & 0x80)
            {
                // Cópia literal
                while (count--) *dst++ = *src++;
            }
            else
            {
                // Run-length
                const unsigned char rep = *src++;
                while (count--) *dst++ = rep;
            }
        }
    }
    else
    {
        // Verbatim
        const long offset = 512L
                          + static_cast<long>(y) * m_width
                          + static_cast<long>(z) * m_width * m_height;
        fseek(f, offset, SEEK_SET);
        fread(buf, 1, static_cast<std::size_t>(m_width), f);
    }
}

// ---------------------------------------------------------------------------
// load — lógica principal
// ---------------------------------------------------------------------------

void ImageLoader::load(const std::string &fileName)
{
    // --- Abrir arquivo ---------------------------------------------------
    FILE *f = fopen(fileName.c_str(), "rb");
    if (!f)
        throw std::runtime_error("ImageLoader: não foi possível abrir \"" + fileName + "\"");

    // --- Ler cabeçalho ---------------------------------------------------
    SgiHeader hdr;
    if (fread(&hdr, 1, sizeof(hdr), f) < 12)
    {
        fclose(f);
        throw std::runtime_error("ImageLoader: cabeçalho incompleto em \"" + fileName + "\"");
    }

    m_swapped = (hdr.imagic == IMAGIC_SWAP);
    if (m_swapped)
    {
        hdr.type  = swapShort(hdr.type);
        hdr.dim   = swapShort(hdr.dim);
        hdr.sizeX = swapShort(hdr.sizeX);
        hdr.sizeY = swapShort(hdr.sizeY);
        hdr.sizeZ = swapShort(hdr.sizeZ);
    }

    if (hdr.imagic != IMAGIC && hdr.imagic != IMAGIC_SWAP)
    {
        fclose(f);
        throw std::runtime_error("ImageLoader: formato SGI inválido em \"" + fileName + "\"");
    }

    m_width    = hdr.sizeX;
    m_height   = hdr.sizeY;
    m_channels = hdr.sizeZ;   // 1=BW, 2=LA, 3=RGB, 4=RGBA

    // --- Tabelas RLE (se aplicável) --------------------------------------
    std::vector<unsigned long> rowStart, rowSize;
    const bool rle = ((hdr.type & 0xFF00) == 0x0100);

    if (rle)
    {
        const int tableLen = m_height * m_channels;
        rowStart.resize(tableLen);
        rowSize .resize(tableLen);

        fseek(f, 512, SEEK_SET);
        fread(rowStart.data(), sizeof(unsigned long), tableLen, f);
        fread(rowSize .data(), sizeof(unsigned long), tableLen, f);

        if (m_swapped)
        {
            for (auto &v : rowStart) v = swapLong(v);
            for (auto &v : rowSize)  v = swapLong(v);
        }
    }

    // --- Buffer temporário por canal ------------------------------------
    // Máximo necessário: uma linha * 256 (headroom para RLE)
    std::vector<unsigned char> tmpBuf(static_cast<std::size_t>(m_width) * 256);

    // Canais separados para a linha corrente
    std::vector<std::vector<unsigned char>> channels(m_channels,
                                                      std::vector<unsigned char>(m_width));

    // --- Buffer de saída intercalado ------------------------------------
    m_data.resize(static_cast<std::size_t>(m_width) * m_height * m_channels);

    unsigned char *out = m_data.data();

    for (int row = 0; row < m_height; ++row)
    {
        // Ler cada canal da linha
        for (int ch = 0; ch < m_channels; ++ch)
            readRow(f, channels[ch].data(), row, ch, hdr.type, rowStart, rowSize, tmpBuf);

        // Intercalar: pixel 0 ch0, pixel 0 ch1 … pixel 0 chN, pixel 1 ch0 …
        for (int px = 0; px < m_width; ++px)
            for (int ch = 0; ch < m_channels; ++ch)
                *out++ = channels[ch][px];
    }

    fclose(f);
}

// ---------------------------------------------------------------------------
// loadTexture — cria e configura uma textura OpenGL a partir de um arquivo SGI
// ---------------------------------------------------------------------------

GLuint ImageLoader::loadTexture(const std::string &fileName)
{
    try
    {
        ImageLoader img(fileName);

        GLuint texID = 0;
        glGenTextures(1, &texID);
        glBindTexture(GL_TEXTURE_2D, texID);

        // Filtragem
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Wrapping
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // Enviar dados + gerar mipmaps automaticamente
        gluBuild2DMipmaps(
            GL_TEXTURE_2D,
            img.getChannels(),      // componentes internos (1–4)
            img.getWidth(),
            img.getHeight(),
            img.getGLFormat(),      // GL_RGB, GL_RGBA, GL_LUMINANCE…
            GL_UNSIGNED_BYTE,
            img.getData()
        );

        std::cout << "Textura carregada: " << fileName
                  << " (" << img.getWidth() << "x" << img.getHeight()
                  << ", " << img.getChannels() << " canal(is))\n";

        return texID;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao carregar textura: " << e.what() << '\n';
        return 0;
    }
}