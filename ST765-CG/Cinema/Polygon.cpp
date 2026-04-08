#include <GL/glut.h>
#include "Polygon.h"
#include <memory>
using namespace std;
using std::unique_ptr;
using std::make_unique;

Polygon::Polygon(float px, float py, float pz,
                 float psx, float psy, float psz,
                 float pr, float pg, float pb,
                float xg, float yg, float zg)
    : x(px), y(py), z(pz),
      sx(psx), sy(psy), sz(psz),
      r(pr), g(pg), b(pb), xg(xg), yg(yg), zg(zg) {}

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

void Cube::draw() const
{
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(xg, 1.0f, 0.0f, 0.0f);
    glRotatef(yg, 0.0f, 1.0f, 0.0f);
    glRotatef(zg, 0.0f, 0.0f, 1.0f);
    glScalef(sx, sy, sz);
    glutSolidCube(1.0);
    glPopMatrix();
}
// template <typename T>
// unique_ptr<T> PolygonBuilder::build() const 
// {
//     return make_unique<T>(x, y, z, sx, sy, sz, r, g, b);
// }