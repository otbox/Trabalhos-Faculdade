#ifndef CADEIRA_H
#define CADEIRA_H

#include <vector>
#include <memory>
#include "Polygon.h"
class Cadeira : public Polygon
{
public:
    std::vector<std::unique_ptr<Polygon>> partes;

    Cadeira(float px, float py, float pz, float psx, float psy, float psz, float pr, float pg, float pb) : Polygon(px, py, pz, psx, psy, psz, pr, pg, pb)
    {
        PolygonBuilder builder;
        // 1. Assento (Mais grosso e fofinho)
        partes.push_back(
            builder.at(0.0f, 0.0f, 0.0f)
                .colored(pr, pg, pb)
                .scaled(1.0f, 0.4f, 1.0f) // Subiu de 0.2 para 0.4 no Y
                .build<Cube>());

        // 2. Encosto (Mais espesso)
        partes.push_back(
            builder.at(0.0f, 0.6f, -0.45f)
                .colored(pr, pg, pb)
                .scaled(1.0f, 1.2f, 0.4f) // Subiu de 0.2 para 0.4 no Z
                .build<Cube>());

        // 3. Braço Esquerdo (Mais largo para apoiar o balde de pipoca)
        partes.push_back(
            builder.at(-0.65f, 0.35f, 0.0f) // Ajustado X para não entrar no assento
                .colored(0.15f, 0.15f, 0.15f)
                .scaled(0.3f, 0.2f, 0.9f) // Mais largo no X e alto no Y
                .build<Cube>());

        // 4. Braço Direito
        partes.push_back(
            builder.at(0.65f, 0.35f, 0.0f)
                .colored(0.15f, 0.15f, 0.15f)
                .scaled(0.3f, 0.2f, 0.9f)
                .build<Cube>());

        // 5. Suporte Central (Pé mais robusto para aguentar o peso)
        partes.push_back(
            builder.at(0.0f, -0.5f, 0.0f)
                .colored(0.05f, 0.05f, 0.05f)
                .scaled(0.4f, 0.8f, 0.4f) // Aumentado para 0.4 no X e Z
                .build<Cube>());
    }
    void draw() const override
    {
        glPushMatrix();
        glTranslatef(x, y, z);
        glScaled(sx, sy, sz);
        for (const auto &obj : partes)
        {
            obj->draw();
        }
        glPopMatrix();
    }
};

#endif