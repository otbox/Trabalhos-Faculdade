#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <string>
#include <vector>
#include <stdexcept>
#include <cstdio>
#include <cstdint>

#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

/**
 * ImageLoader - Carrega imagens SGI (.rgb, .rgba, .bw) para uso em texturas OpenGL.
 *
 * Uso básico (manual):
 *   ImageLoader img("textura.rgb");
 *   glTexImage2D(GL_TEXTURE_2D, 0, img.getChannels(), img.getWidth(), img.getHeight(),
 *                0, img.getGLFormat(), GL_UNSIGNED_BYTE, img.getData());
 *
 * Uso simplificado (recomendado):
 *   GLuint texID = ImageLoader::loadTexture("textura.rgb");
 */
class ImageLoader
{
public:
    // -----------------------------------------------------------------------
    // Construção / destrução
    // -----------------------------------------------------------------------

    /** Carrega a imagem no momento da construção. Lança std::runtime_error em falha. */
    explicit ImageLoader(const std::string &fileName);

    ~ImageLoader() = default;

    // Sem cópia (dados pesados); movível.
    ImageLoader(const ImageLoader &) = delete;
    ImageLoader &operator=(const ImageLoader &) = delete;
    ImageLoader(ImageLoader &&) = default;
    ImageLoader &operator=(ImageLoader &&) = default;

    // -----------------------------------------------------------------------
    // Acesso aos dados da imagem
    // -----------------------------------------------------------------------

    /** Largura em pixels. */
    int getWidth() const { return m_width; }

    /** Altura em pixels. */
    int getHeight() const { return m_height; }

    /**
     * Número de canais (profundidade):
     *  1 = escala de cinza, 2 = cinza+alpha, 3 = RGB, 4 = RGBA
     */
    int getChannels() const { return m_channels; }

    /**
     * Formato OpenGL correspondente ao número de canais:
     *  GL_LUMINANCE, GL_LUMINANCE_ALPHA, GL_RGB ou GL_RGBA
     */
    unsigned int getGLFormat() const;

    /**
     * Ponteiro para os dados brutos (row-major, bottom-up como exige OpenGL).
     * Cada pixel ocupa getChannels() bytes.
     */
    const unsigned char *getData() const { return m_data.data(); }

    /** Tamanho total do buffer em bytes. */
    std::size_t getDataSize() const { return m_data.size(); }

    // -----------------------------------------------------------------------
    // Utilitário OpenGL
    // -----------------------------------------------------------------------

    /**
     * Carrega a imagem e cria uma textura OpenGL completa (com mipmaps).
     *
     * Configurações aplicadas automaticamente:
     *   - MIN filter : GL_LINEAR_MIPMAP_LINEAR
     *   - MAG filter : GL_LINEAR
     *   - Wrap S/T   : GL_REPEAT
     *
     * @param fileName  Caminho para o arquivo SGI (.rgb / .rgba / .bw).
     * @return          ID da textura gerada, ou 0 em caso de falha.
     */
    static GLuint loadTexture(const std::string &fileName);

private:
    // -----------------------------------------------------------------------
    // Estrutura interna do arquivo SGI
    // -----------------------------------------------------------------------

    static constexpr unsigned short IMAGIC = 0x01DA;
    static constexpr unsigned short IMAGIC_SWAP = 0xDA01;

#pragma pack(push, 1)
    struct SgiHeader
    {
        unsigned short imagic;
        unsigned short type;
        unsigned short dim;
        unsigned short sizeX, sizeY, sizeZ;
        uint32_t minVal, maxVal;
        uint32_t wasteBytes;
        char name[80];
        uint32_t colorMap;
    };
#pragma pack(pop)

    // -----------------------------------------------------------------------
    // Estado
    // -----------------------------------------------------------------------

    int m_width = 0;
    int m_height = 0;
    int m_channels = 0;
    bool m_swapped = false;

    std::vector<unsigned char> m_data;

    // -----------------------------------------------------------------------
    // Helpers internos
    // -----------------------------------------------------------------------

    unsigned short swapShort(unsigned short v);
    static uint32_t swapLong(uint32_t v);
    std::vector<uint32_t> rowStart, rowSize;

    void load(const std::string &fileName);

    /** Lê uma linha de pixels de um canal, descomprimindo RLE se necessário. */
    void readRow(FILE *f,
                 unsigned char *buf,
                 int y, int z,
                 unsigned short type,
                 const std::vector<uint32_t> &rowStart,
                 const std::vector<uint32_t> &rowSize,
                 std::vector<unsigned char> &tmpBuf) const;
};

#endif // IMAGE_LOADER_H