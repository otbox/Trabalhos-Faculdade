#ifndef POLYGON_H
#define POLYGON_H

#include <GL/glut.h>
#include <memory>
using std::make_unique;
using std::unique_ptr;

class Polygon
{
protected:
    float x, y, z;
    float sx, sy, sz;
    float r, g, b;
    float xg, yg, zg;
    GLuint textureID;

public:
    Polygon(float px, float py, float pz,
            float psx, float psy, float psz,
            float pr, float pg, float pb,
            float xg, float yg, float zg, GLuint textureID = 0);

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

enum class TexturesTypes
{
    WIDE,
    REPEATE
};

class Cube : public Polygon
{
public:
    using Polygon::Polygon;
    TexturesTypes textureType;
    void draw() const override;
    void setTypeTexture(TexturesTypes t)
    {
        textureType = t;
    }

    // ~Cube();
};

class PolygonBuilder
{
private:
    float x = 0.0f, y = 0.0f, z = 0.0f;
    float sx = 1.0f, sy = 1.0f, sz = 1.0f;
    float r = 1.0f, g = 1.0f, b = 1.0f;
    float xg = 0.0f, yg = 0.0f, zg = 0.0f;
    GLuint textureID;

public:
    PolygonBuilder &at(float px, float py, float pz);
    PolygonBuilder &scaled(float psx = 1, float psy = 1, float psz = 1);
    PolygonBuilder &colored(float pr, float pg, float pb);
    PolygonBuilder &rotated(float pxg = 0.0f, float pyg = 0.0f, float pzg = 0.0f);
    PolygonBuilder &textured(GLuint textureID = 0);

    // template <typename T>
    // T build() const
    // {
    //     return T(x, y, z, sx, sy, sz, r, g, b);
    // }
    template <typename T>
    unique_ptr<T> build() const
    {
        return make_unique<T>(x, y, z, sx, sy, sz, r, g, b, xg, yg, zg, textureID);
    }
};

#endif