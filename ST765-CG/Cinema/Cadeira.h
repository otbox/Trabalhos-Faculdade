#ifndef CADEIRA_H
#define CADEIRA_H

#include <vector>
#include <memory>
#include "Polygon.h"

class Cadeira : public Polygon
{
public:
    std::vector<std::unique_ptr<Polygon>> partes;

    Cadeira(float px, float py, float pz,
            float psx, float psy, float psz,
            float pr, float pg, float pb)
        : Polygon(px, py, pz, psx, psy, psz, pr, pg, pb)
    {
        // Todas as posicoes sao locais (relativas ao centro da cadeira).
        // O draw() aplica glTranslatef + glScalef sobre tudo junto.

        // 1. Assento
        partes.push_back(
            PolygonBuilder()
                .at(0.0f, 0.0f, 0.0f)
                .colored(pr, pg, pb)
                .scaled(0.9f, 0.15f, 0.8f)
                .build<Cube>());

        // 2. Encosto
        partes.push_back(
            PolygonBuilder()
                .at(0.0f, 0.5f, -0.38f)
                .colored(pr, pg, pb)
                .scaled(0.9f, 0.85f, 0.12f)
                .build<Cube>());

        // 3. Braco esquerdo
        partes.push_back(
            PolygonBuilder()
                .at(-0.48f, 0.1f, 0.05f)
                .colored(0.15f, 0.10f, 0.08f)
                .scaled(0.08f, 0.1f, 0.75f)
                .build<Cube>());

        // 4. Braco direito
        partes.push_back(
            PolygonBuilder()
                .at(0.48f, 0.1f, 0.05f)
                .colored(0.15f, 0.10f, 0.08f)
                .scaled(0.08f, 0.1f, 0.75f)
                .build<Cube>());

        // 5. Perna dianteira esquerda
        partes.push_back(
            PolygonBuilder()
                .at(-0.35f, -0.32f, 0.32f)
                .colored(0.1f, 0.1f, 0.1f)
                .scaled(0.07f, 0.5f, 0.07f)
                .build<Cube>());

        // 6. Perna dianteira direita
        partes.push_back(
            PolygonBuilder()
                .at(0.35f, -0.32f, 0.32f)
                .colored(0.1f, 0.1f, 0.1f)
                .scaled(0.07f, 0.5f, 0.07f)
                .build<Cube>());

        // 7. Perna traseira esquerda
        partes.push_back(
            PolygonBuilder()
                .at(-0.35f, -0.32f, -0.32f)
                .colored(0.1f, 0.1f, 0.1f)
                .scaled(0.07f, 0.5f, 0.07f)
                .build<Cube>());

        // 8. Perna traseira direita
        partes.push_back(
            PolygonBuilder()
                .at(0.35f, -0.32f, -0.32f)
                .colored(0.1f, 0.1f, 0.1f)
                .scaled(0.07f, 0.5f, 0.07f)
                .build<Cube>());
    }

    void draw() const override
    {
        glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(sx, sy, sz);
        for (const auto &obj : partes)
        {
            obj->draw();
        }
        glPopMatrix();
    }
};

#endif