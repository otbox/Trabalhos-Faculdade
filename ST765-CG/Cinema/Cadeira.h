#ifndef CADEIRA_H
#define CADEIRA_H

#include <vector>
#include <memory>
#include "Polygon.h"
#include <GL/glut.h>

class Cadeira : public Polygon {
public:
    std::vector<std::unique_ptr<Polygon>> partes;


    Cadeira(float px, float py, float pz,
            float psx, float psy, float psz,
            float pr, float pg, float pb,
        float xg, float yg, float zg, GLuint texture);


    void draw() const override;
};

#endif