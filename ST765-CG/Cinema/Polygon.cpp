#include <GL/glut.h>
#include "Polygon.h"
#include <memory>
using namespace std;
using std::unique_ptr;
using std::make_unique;

Polygon::Polygon(float px, float py, float pz,
                 float psx, float psy, float psz,
                 float pr, float pg, float pb,
                float xg, float yg, float zg, GLuint textureID)
    : x(px), y(py), z(pz),
      sx(psx), sy(psy), sz(psz),
      r(pr), g(pg), b(pb), xg(xg), yg(yg), zg(zg), textureID(textureID) {}

Polygon::~Polygon()
{
}

void Polygon::draw() const {

}

PolygonBuilder &PolygonBuilder::at(float px, float py, float pz)
{
    x = px;
    y = py;
    z = pz;
    return *this;
}

PolygonBuilder &PolygonBuilder::scaled(float psx, float psy, float psz)
{
    sx = psx;
    sy = psy;
    sz = psz;
    return *this;
}

PolygonBuilder &PolygonBuilder::colored(float pr, float pg, float pb)
{
    r = pr;
    g = pg;
    b = pb;
    return *this;
}
PolygonBuilder &PolygonBuilder::rotated(float pxg, float pyg, float pzg) {
    xg = pxg;
    yg = pyg;
    zg = pzg;
    return *this;
}

PolygonBuilder &PolygonBuilder::textured(GLuint ptextureID) {
    textureID = ptextureID;
    return *this;
}

void Cube::draw() const
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(xg, 1.0f, 0.0f, 0.0f);
    glRotatef(yg, 0.0f, 1.0f, 0.0f);
    glRotatef(zg, 0.0f, 0.0f, 1.0f);
    glScalef(sx, sy, sz);

float texCoordMax = 1.0f; // Valor padrão (WIDE)

    if (this->textureID != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this->textureID);
        
        switch (textureType)
        {
            case TexturesTypes::WIDE:
                // Estica a imagem: a coordenada vai de 0 a 1
                texCoordMax = 1.0f;
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
                break;
                
            case TexturesTypes::REPEATE:
                // Repete a imagem: a coordenada vai de 0 a 5 (por exemplo)
                texCoordMax = 5.0f; 
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                break;
        }
        glColor3f(1.0f, 1.0f, 1.0f); 
    } else {
        glDisable(GL_TEXTURE_2D);
        glColor3f(r, g, b);
    }

    glBegin(GL_QUADS);
        // Face Frontal
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
        glTexCoord2f(texCoordMax, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
        glTexCoord2f(texCoordMax, texCoordMax); glVertex3f( 0.5f,  0.5f,  0.5f);
        glTexCoord2f(0.0f, texCoordMax); glVertex3f(-0.5f,  0.5f,  0.5f);
        
        // Face Traseira
        glTexCoord2f(texCoordMax, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(texCoordMax, texCoordMax); glVertex3f(-0.5f,  0.5f, -0.5f);
        glTexCoord2f(0.0f, texCoordMax); glVertex3f( 0.5f,  0.5f, -0.5f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);

        // Face Superior (Topo)
        glTexCoord2f(0.0f, texCoordMax); glVertex3f(-0.5f,  0.5f, -0.5f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
        glTexCoord2f(texCoordMax, 0.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
        glTexCoord2f(texCoordMax, texCoordMax); glVertex3f( 0.5f,  0.5f, -0.5f);

        // Face Inferior (Baixo)
        glTexCoord2f(texCoordMax, texCoordMax); glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(0.0f, texCoordMax); glVertex3f( 0.5f, -0.5f, -0.5f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
        glTexCoord2f(texCoordMax, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);

        // Face Direita
        glTexCoord2f(texCoordMax, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
        glTexCoord2f(texCoordMax, texCoordMax); glVertex3f( 0.5f,  0.5f, -0.5f);
        glTexCoord2f(0.0f, texCoordMax); glVertex3f( 0.5f,  0.5f,  0.5f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);

        // Face Esquerda
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(texCoordMax, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
        glTexCoord2f(texCoordMax, texCoordMax); glVertex3f(-0.5f,  0.5f,  0.5f);
        glTexCoord2f(0.0f, texCoordMax); glVertex3f(-0.5f,  0.5f, -0.5f);
    glEnd();

    if (this->textureID != 0) glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}
// template <typename T>
// unique_ptr<T> PolygonBuilder::build() const 
// {
//     return make_unique<T>(x, y, z, sx, sy, sz, r, g, b);
// }