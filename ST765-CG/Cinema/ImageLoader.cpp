#include "ImageLoader.h"
#include <stdexcept>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <limits>

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

uint32_t ImageLoader::swapLong(uint32_t v)
{
    return ((v & 0x000000FFUL) << 24)
         | ((v & 0x0000FF00UL) <<  8)
         | ((v & 0x00FF0000UL) >>  8)
         | ((v & 0xFF000000UL) >> 24);
}

// ---------------------------------------------------------------------------
// readRow
// ---------------------------------------------------------------------------

void ImageLoader::readRow(FILE *f,
                          unsigned char *buf,
                          int y, int z,
                          unsigned short type,
                          const std::vector<uint32_t> &rowStart,
                          const std::vector<uint32_t> &rowSize,
                          std::vector<unsigned char>  &tmpBuf) const
{
    const bool rle = ((type & 0xFF00) == 0x0100);

    if (rle)
    {
        const int idx = y + z * m_height;

        if (rowSize[idx] > tmpBuf.size())
            throw std::runtime_error("RLE rowSize excede tmpBuf na linha " + std::to_string(y));

        fseek(f, static_cast<long>(rowStart[idx]), SEEK_SET);
        fread(tmpBuf.data(), 1, rowSize[idx], f);

        const unsigned char *src    = tmpBuf.data();
        const unsigned char *srcEnd = tmpBuf.data() + rowSize[idx];
        unsigned char       *dst    = buf;
        unsigned char       *dstEnd = buf + m_width;

        while (src < srcEnd)
        {
            const unsigned char pixel = *src++;
            int count = pixel & 0x7F;
            if (!count) break;

            if (pixel & 0x80)
            {
                if (dst + count > dstEnd) count = static_cast<int>(dstEnd - dst);
                if (src + count > srcEnd) count = static_cast<int>(srcEnd - src);
                while (count--) *dst++ = *src++;
            }
            else
            {
                if (src >= srcEnd) break;
                const unsigned char rep = *src++;
                if (dst + count > dstEnd) count = static_cast<int>(dstEnd - dst);
                while (count--) *dst++ = rep;
            }
        }
    }
    else
    {
        const long offset = 512L
                          + static_cast<long>(z) * m_width * m_height
                          + static_cast<long>(y) * m_width;
        fseek(f, offset, SEEK_SET);
        fread(buf, 1, static_cast<std::size_t>(m_width), f);
    }
}

// ---------------------------------------------------------------------------
// load
// ---------------------------------------------------------------------------

void ImageLoader::load(const std::string &fileName)
{
    FILE *f = fopen(fileName.c_str(), "rb");
    if (!f)
        throw std::runtime_error("ImageLoader: não foi possível abrir \"" + fileName + "\"");

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

    printf("Debug ImageLoader: %s | %dx%d | Canais: %d | Swapped: %s\n",
           fileName.c_str(), hdr.sizeX, hdr.sizeY, hdr.sizeZ, m_swapped ? "Sim" : "Não");

    if (hdr.imagic != IMAGIC && hdr.imagic != IMAGIC_SWAP)
    {
        fclose(f);
        throw std::runtime_error("ImageLoader: formato SGI inválido em \"" + fileName + "\"");
    }

    m_width    = hdr.sizeX;
    m_height   = hdr.sizeY;
    m_channels = hdr.sizeZ;

    // -----------------------------------------------------------------------
    // Tabelas RLE
    // -----------------------------------------------------------------------
    std::vector<uint32_t> rowStart, rowSize;  // ← CORREÇÃO: era unsigned long
    const bool rle = ((hdr.type & 0xFF00) == 0x0100);

    if (rle)
    {
        const size_t tableLen = static_cast<size_t>(m_height) * m_channels;
        rowStart.assign(tableLen, 0U);        // ← CORREÇÃO: era 0UL
        rowSize .assign(tableLen, 0U);        // ← CORREÇÃO: era 0UL

        fseek(f, 512, SEEK_SET);

        size_t rsA = fread(rowStart.data(), sizeof(uint32_t), tableLen, f);  // ← sizeof(uint32_t)
        if (rsA != tableLen) {
            fclose(f);
            throw std::runtime_error("Falha fread rowStart: " +
                std::to_string(rsA) + "/" + std::to_string(tableLen));
        }

        size_t rsB = fread(rowSize.data(), sizeof(uint32_t), tableLen, f);   // ← sizeof(uint32_t)
        if (rsB != tableLen) {
            fclose(f);
            throw std::runtime_error("Falha fread rowSize: " +
                std::to_string(rsB) + "/" + std::to_string(tableLen));
        }

        if (m_swapped)
        {
            for (size_t i = 0; i < tableLen; ++i)
            {
                rowStart[i] = swapLong(rowStart[i]);
                rowSize[i]  = swapLong(rowSize[i]);
            }
        }

        for (size_t i = 0; i < tableLen; ++i)
        {
            if (rowSize[i] > static_cast<uint32_t>(m_width) * 256)  // ← uint32_t
            {
                fclose(f);
                throw std::runtime_error("rowSize[" + std::to_string(i) +
                    "] inválido: " + std::to_string(rowSize[i]));
            }
        }

        printf("Tabelas RLE OK: %zu entradas\n", tableLen);
    }

    // -----------------------------------------------------------------------
    // Buffers
    // -----------------------------------------------------------------------
    const size_t maxRowSize = static_cast<size_t>(m_width) * 256;
    std::vector<unsigned char> tmpBuf(maxRowSize);

    std::vector<std::vector<unsigned char>> channels(
        m_channels, std::vector<unsigned char>(m_width, 0));

    const size_t totalSize = static_cast<size_t>(m_width) * m_height * m_channels;
    m_data.resize(totalSize);

    unsigned char *out = m_data.data();

    for (int row = 0; row < m_height; ++row)
    {
        for (int ch = 0; ch < m_channels; ++ch)
            readRow(f, channels[ch].data(), row, ch, hdr.type, rowStart, rowSize, tmpBuf);

        for (int px = 0; px < m_width; ++px)
            for (int ch = 0; ch < m_channels; ++ch)
                *out++ = channels[ch][px];
    }

    fclose(f);
}

// ---------------------------------------------------------------------------
// loadTexture
// ---------------------------------------------------------------------------

GLuint ImageLoader::loadTexture(const std::string &fileName)
{
    try
    {
        ImageLoader img(fileName);

        GLuint texID = 0;
        glGenTextures(1, &texID);
        glBindTexture(GL_TEXTURE_2D, texID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        gluBuild2DMipmaps(
            GL_TEXTURE_2D,
            img.getChannels(),
            img.getWidth(),
            img.getHeight(),
            img.getGLFormat(),
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