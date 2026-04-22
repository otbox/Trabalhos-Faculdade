#ifndef SALA_H
#define SALA_H

#include <vector>
#include <memory>
#include "Polygon.h"

class Sala : public Polygon
{
public:
    std::vector<std::unique_ptr<Polygon>> partes;

    Sala(float px, float py, float pz,
         float psx, float psy, float psz,
         float pr, float pg, float pb,
         float xg, float yg, float zg, GLuint textureID = 0);

    void draw() const override;
};

class Row : public Polygon
{
private:
    int chairsNumber;
    float calculateSpaceBetweenChairs(float tamanhoCadeira, float espacamento);
    std::vector<std::unique_ptr<Polygon>> partes;

public:
    Row(float px, float py, float pz,
        float psx, float psy, float psz,
        float pr, float pg, float pb,
        float xg, float yg, float zg, GLuint textureID = 0);

    void draw() const override;
};

class Porta : public Polygon
{
public:
    std::vector<std::unique_ptr<Polygon>> partes;
    Porta(float px, float py, float pz,
             float psx, float psy, float psz,
             float pr, float pg, float pb,
             float xg, float yg, float zg, GLuint textureID = 0);
    void draw() const override;
};

#endif