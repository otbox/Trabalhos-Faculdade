#ifndef CAIXASOM_H
#define CAIXASOM_H

#include <vector>
#include <memory>
#include "Polygon.h"

class CaixaSom : public Polygon
{
public:
    std::vector<std::unique_ptr<Polygon>> partes;

    CaixaSom(float px, float py, float pz,
             float psx, float psy, float psz,
             float pr, float pg, float pb,
             float xg = 0, float yg = 0, float zg = 0);

    void draw() const override;
};

#endif