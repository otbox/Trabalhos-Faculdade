#include "CaixaSom.h"

CaixaSom::CaixaSom(float px, float py, float pz,
                   float psx, float psy, float psz,
                   float pr, float pg, float pb,
                   float xg, float yg, float zg)
    : Polygon(px, py, pz, psx, psy, psz, pr, pg, pb, xg, yg, zg)
{
    PolygonBuilder builder;

    // 1. Gabinete Principal (O corpo da caixa)
    // Cor pr, pg, pb (geralmente preto ou madeira)
    partes.push_back(
        builder.at(0.0f, 0.0f, 0.0f)
               .colored(pr, pg, pb)
               .scaled(1.0f, 1.0f, 1.0f)
               .build<Cube>());

    // 2. Woofer (Alto-falante de graves - maior, embaixo)
    partes.push_back(
        builder.at(0.0f, -0.2f, 0.51f) // Levemente para frente do gabinete (z=0.51)
               .colored(0.1f, 0.1f, 0.1f) // Cinza quase preto
               .scaled(0.7f, 0.7f, 0.02f) // Grande e fino
               .build<Cube>());

    // 3. Tweeter (Alto-falante de agudos - menor, em cima)
    partes.push_back(
        builder.at(0.0f, 0.35f, 0.51f) 
               .colored(0.05f, 0.05f, 0.05f) 
               .scaled(0.3f, 0.3f, 0.02f) // Pequeno
               .build<Cube>());

    // 4. Detalhe: Duto de Ar (O buraquinho do grave)
    // partes.push_back(
    //     builder.at(0.0f, -0.7f, 0.51f)
    //            .colored(0.0f, 0.0f, 0.0f)
    //            .scaled(0.15f, 0.15f, 0.01f)
    //            .build<Cube>());
}

void CaixaSom::draw() const
{
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(xg, 1.0f, 0.0f, 0.0f);
        glRotatef(yg, 0.0f, 1.0f, 0.0f);
        glRotatef(zg, 0.0f, 0.0f, 1.0f);
        glScalef(sx, sy, sz);

        for (const auto& p : partes) {
            p->draw();
        }
    glPopMatrix();
}