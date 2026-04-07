#include <GL/glut.h>

class Polygon
{
private:
    float x, y, z;
    float sx, sy, sz;
    float r, g, b;
    float xg, yg, zg;

    
public:
    Polygon(float px, float py, float pz,
            float psx = 1.0f, float psy = 1.0f, float psz = 1.0f,
            float pr = 1.0f, float pg = 0.0f, float pb = 0.0f)
        : x(px), y(py), z(pz),
          sx(psx), sy(psy), sz(psz),
          r(pr), g(pg), b(pb) {}

    ~Polygon();

    void setColor(float pr, float pg, float pb)
    {
        r = pr;
        g = pg;
        b = pb;
    }

    void setScale(float psx, float psy, float psz)
    {
        sx = psx;
        sy = psy;
        sz = psz;
    }

    void setPosition(float px, float py, float pz)
    {
        x = px;
        y = py;
        z = pz;
    }
    // adicionar set color
    // adicionar set iluminação no outro entre outros.

    virtual void draw() const;
};

class PolygonBuilder
{
private:
    float x = 0.0f, y = 0.0f, z = 0.0f;
    float sx = 1.0f, sy = 1.0f, sz = 1.0f;
    float r = 1.0f, g = 1.0f, b = 1.0f;

public:
    PolygonBuilder& at(float px, float py, float pz)
    {
        x = px;
        y = py;
        z = pz;
        return *this;
    }

    PolygonBuilder& scaled(float psx, float psy, float psz)
    {
        sx = psx;
        sy = psy;
        sz = psz;
        return *this;
    }

    PolygonBuilder& colored(float pr, float pg, float pb)
    {
        r = pr;
        g = pg;
        b = pb;
        return *this;
    }

    Cube buildCube() const
    {
        return Cube(x, y, z, sx, sy, sz, r, g, b);
    }
};
