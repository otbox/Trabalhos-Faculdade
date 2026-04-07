#ifndef POLYGON_H
#define POLYGON_H

#include <GL/glut.h>
#include <memory>
using std::unique_ptr;
using std::make_unique;

class Polygon
{
protected:
    float x, y, z;
    float sx, sy, sz;
    float r, g, b;
    float xg, yg, zg;

public:
    Polygon(float px, float py, float pz,
            float psx, float psy, float psz,
            float pr, float pg, float pb);

    virtual ~Polygon();

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

    virtual void draw() const;
};

class Cube : public Polygon
{
public:
    using Polygon::Polygon;
    void draw() const override;
    
    // ~Cube();
};

class PolygonBuilder
{
private:
    float x = 0.0f, y = 0.0f, z = 0.0f;
    float sx = 1.0f, sy = 1.0f, sz = 1.0f;
    float r = 1.0f, g = 1.0f, b = 1.0f;

public:
    PolygonBuilder &at(float px, float py, float pz);
    PolygonBuilder &scaled(float psx = 1, float psy = 1, float psz = 1);
    PolygonBuilder &colored(float pr, float pg, float pb);


    // template <typename T>
    // T build() const
    // {
    //     return T(x, y, z, sx, sy, sz, r, g, b);
    // }
    template <typename T>
    unique_ptr<T> build() const {
        return make_unique<T>(x, y, z, sx, sy, sz, r, g, b);
    }
};

#endif