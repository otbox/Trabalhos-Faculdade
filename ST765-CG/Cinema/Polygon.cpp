#include <GL/glut.h>
#include "Polygon.h"
#include <memory>
using namespace std;
using std::unique_ptr;
using std::make_unique;

Polygon::Polygon(float px, float py, float pz,
                 float psx, float psy, float psz,
                 float pr, float pg, float pb)
    : x(px), y(py), z(pz),
      sx(psx), sy(psy), sz(psz),
      r(pr), g(pg), b(pb) {}

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

void Cube::draw() const
{
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sx, sy, sz);
    glutSolidCube(1.0);
    glPopMatrix();
}
// template <typename T>
// unique_ptr<T> PolygonBuilder::build() const 
// {
//     return make_unique<T>(x, y, z, sx, sy, sz, r, g, b);
// }