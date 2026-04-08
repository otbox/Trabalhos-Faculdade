#include "Sala.h"
#include "Cadeira.h"
#include "CaixaSom.h"

Sala::Sala(float px, float py, float pz,
           float psx, float psy, float psz,
           float pr, float pg, float pb,
           float xg, float yg, float zg)
    : Polygon(px, py, pz, psx, psy, psz, pr, pg, pb, xg, yg, zg)
{
    float esp = 0.2f;

    // 1. Chão
    partes.push_back(
        PolygonBuilder().at(0, -2.5f, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(20.0f, esp, 20.0f).build<Cube>());
    partes.push_back(
        PolygonBuilder().at(0.0f, -0.5f, 7.75).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(20.0f, esp, 4.5f).build<Cube>());

    partes.push_back(
        PolygonBuilder().at(9.75f, 0.5f, 7.75).rotated(0, -90, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(2, 2.5, 1).build<Porta>());
    partes.push_back(
        PolygonBuilder().at(-9.75f, 0.5f, 7.75).rotated(0, 90, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(2, 2.5, 1).build<Porta>());

    // 2. Teto
    partes.push_back(
        PolygonBuilder().at(0, 2.5f, 0).colored(pr + 0.1f, pg + 0.1f, pb + 0.1f).scaled(20.0f, esp, 20.0f).build<Cube>());

    // 3. Parede Frontal
    partes.push_back(
        PolygonBuilder().at(0, 0, -10.0f).colored(pr, pg, pb).scaled(20.0f, 5.0f, esp).build<Cube>());

    // 4. Parede Traseira
    partes.push_back(
        PolygonBuilder().at(0, 0, 10.0f).colored(pr, pg, pb).scaled(20.0f, 5.0f, esp).build<Cube>());

    // 5. Parede Esquerda
    partes.push_back(
        PolygonBuilder().at(-10.0f, 0, 0).colored(pr, pg, pb).scaled(esp, 5.0f, 20.0f).build<Cube>());

    // 6. Parede Direita
    partes.push_back(
        PolygonBuilder().at(10.0f, 0, 0).colored(pr, pg, pb).scaled(esp, 5.0f, 20.0f).build<Cube>());

    // Tela Branca
    partes.push_back(
        PolygonBuilder().at(0.0f, 0.0f, -9.8f).colored(1.0f, 1.0f, 1.0f).scaled(8.0f, 3.5f, 0.1f).build<Cube>());

    // Faixas decorativas
    // Diagonais
    partes.push_back(
        PolygonBuilder().at(9.8f, 1.0f, -0.8f).colored(0.6f, 0.1f, 0.1f).rotated(-11, 0, 0).scaled(0.1f, 0.25f, 13.0f).build<Cube>());
    partes.push_back(
        PolygonBuilder().at(-9.8f, 1.0f, -0.8f).colored(0.6f, 0.1f, 0.1f).rotated(-11, 0, 0).scaled(0.1f, 0.25f, 13.0f).build<Cube>());

    // Verticais
    // Frente
    partes.push_back(
        PolygonBuilder().at(9.8f, 1.25f, -7.0f).colored(0.6f, 0.1f, 0.1f).scaled(0.1f, 3.0f, 0.5f).build<Cube>());
    partes.push_back(
        PolygonBuilder().at(-9.8f, 1.25f, -7.0f).colored(0.6f, 0.1f, 0.1f).scaled(0.1f, 3.0f, 0.5f).build<Cube>());
        // SOM
    partes.push_back(
        PolygonBuilder().at(-9.8f, 0.8f, -5.5f).rotated(0, 90, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(0.5f, 0.5f, 0.5f).build<CaixaSom>());
    partes.push_back(
        PolygonBuilder().at(9.8f, 0.8f, -5.5f).rotated(0, -90, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(0.5f, 0.5f, 0.5f).build<CaixaSom>());

    // Meio
    partes.push_back(
        PolygonBuilder().at(9.8f, 1.4f, -4.0f).colored(0.6f, 0.1f, 0.1f).scaled(0.1f, 2.0f, 0.5f).build<Cube>());
    partes.push_back(
        PolygonBuilder().at(-9.8f, 1.4f, -4.0f).colored(0.6f, 0.1f, 0.1f).scaled(0.1f, 2.0f, 0.5f).build<Cube>());
        // SOM
    partes.push_back(
        PolygonBuilder().at(-9.8f, 1.1f, -3.0f).rotated(0, 90, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(0.5f, 0.5f, 0.5f).build<CaixaSom>());
    partes.push_back(
        PolygonBuilder().at(9.8f, 1.1f, -3.0f).rotated(0, -90, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(0.5f, 0.5f, 0.5f).build<CaixaSom>());

    // Tras
    partes.push_back(
        PolygonBuilder().at(9.8f, 1.65f, -1.0f).colored(0.6f, 0.1f, 0.1f).scaled(0.1f, 1.5f, 0.5f).build<Cube>());
    partes.push_back(
        PolygonBuilder().at(-9.8f, 1.65f, -1.0f).colored(0.6f, 0.1f, 0.1f).scaled(0.1f, 1.5f, 0.5f).build<Cube>());
    // SOM
    partes.push_back(
        PolygonBuilder().at(-9.8f, 1.5f, -0.5f).rotated(0, 90, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(0.5f, 0.5f, 0.5f).build<CaixaSom>());
    partes.push_back(
        PolygonBuilder().at(9.8f, 1.5f, -0.5f).rotated(0, -90, 0).colored(pr - 0.05, pg - 0.05, pb - 0.05).scaled(0.5f, 0.5f, 0.5f).build<CaixaSom>());

    // --- 18 fileiras escalonadas ---
    int numFileiras = 9;
    float alturaInicial = -1.7f; // Y da primeira fileira
    float zInicial = -7.0f;      // Z da primeira fileira (perto da tela)
    float stepY = 0.25f;
    float stepZ = 1.5f;

    for (int i = 0; i < numFileiras; i++)
    {
        float fy = alturaInicial + i * stepY;
        float fz = zInicial + i * stepZ;

        // Fileira de cadeiras
        partes.push_back(
            PolygonBuilder()
                .at(0.0f, fy, fz)
                .colored(0.6f, 0.1f, 0.1f)
                .scaled(20.0f, 1.0f, 1.5f)
                .rotated(0, 180, 0)
                .build<Row>());
    }
}

void Sala::draw() const
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sx, sy, sz);
    glRotatef(xg, 1.0f, 0.0f, 0.0f);
    glRotatef(yg, 0.0f, 1.0f, 0.0f);
    glRotatef(zg, 0.0f, 0.0f, 1.0f);
    for (const auto &obj : partes)
    {
        obj->draw();
    }
    glPopMatrix();
};

float Row::calculateSpaceBetweenChairs(float tamanhoCadeira, float espacamento)
{
    return sx / (tamanhoCadeira + espacamento); // tamanho da fileira / (tamanho da cadeira + espaçamento)
}

Row::Row(float px, float py, float pz,
         float psx, float psy, float psz,
         float pr, float pg, float pb,
         float xg, float yg, float zg)
    : Polygon(px, py, pz, psx, psy, psz, pr, pg, pb, xg, yg, zg)
{
    float tamanhoCadeira = 1.05f;
    float espacamento = 0.05f;
    float passo = tamanhoCadeira + espacamento;

    // Cubo base da fileira
    partes.push_back(
        PolygonBuilder()
            .at(0, -1.0f, 0)
            .colored(0.1f, 0.1f, 0.1f)
            .scaled(sx, sy, sz)
            .build<Cube>());


    partes.push_back(
        PolygonBuilder()
            .at(0.0 / 2.0f, -1.0f + sy / 2.0f, sz / 2.0f)
            .colored(1.0f, 0.5f, 0.0f)
            .scaled(sx, 0.04f, 0.04f) 
            .build<Cube>());

    sx -= 4.0f;

    float pos = (-sx / 2.0f) + (tamanhoCadeira / 2.0f);
    int quantidadeCadeiras = calculateSpaceBetweenChairs(tamanhoCadeira, espacamento);

    for (int i = 0; i < quantidadeCadeiras; i++)
    {
        partes.push_back(
            PolygonBuilder()
                .at(pos, 0.0f, 0.0f)
                .colored(0.6f, 0.1f, 0.1f)
                .scaled(1.0f, 1.0f, 1.0f)
                .build<Cadeira>());

        pos += passo;
    }
}

void Row::draw() const
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(xg, 1.0f, 0.0f, 0.0f);
    glRotatef(yg, 0.0f, 1.0f, 0.0f);
    glRotatef(zg, 0.0f, 0.0f, 1.0f);
    // glScalef(sx, sy, sz);
    for (const auto &obj : partes)
    {
        obj->draw();
    }
    glPopMatrix();
};

Porta::Porta(float px, float py, float pz,
             float psx, float psy, float psz,
             float pr, float pg, float pb,
             float xg, float yg, float zg)
    : Polygon(px, py, pz, psx, psy, psz, pr, pg, pb, xg, yg, zg)
{
    PolygonBuilder builder;

    // 1. Guarnição Topo
    partes.push_back(builder.at(0.0f, 0.46f, 0.0f)
                         .colored(0.6f, 0.1f, 0.1f)
                         .scaled(1.16f, 0.08f, 0.15f)
                         .build<Cube>());

    // 2. Guarnição Lateral Esquerda
    partes.push_back(builder.at(-0.54f, 0.0f, 0.0f)
                         .colored(0.6f, 0.1f, 0.1f)
                         .scaled(0.08f, 1.0f, 0.15f)
                         .build<Cube>());

    // 3. Guarnição Lateral Direita
    partes.push_back(builder.at(0.54f, 0.0f, 0.0f)
                         .colored(0.6f, 0.1f, 0.1f)
                         .scaled(0.08f, 1.0f, 0.15f)
                         .build<Cube>());

    // 4. Folha da Porta
    partes.push_back(builder.at(0.29f, 0.0f, 0.0f)
                         .colored(0.35f, 0.35f, 0.35f)
                         .scaled(0.475f, 0.92f, 0.05f)
                         .build<Cube>());
                         
    partes.push_back(builder.at(-0.29f, 0.0f, 0.0f)
                         .colored(0.35f, 0.35f, 0.35f)
                         .scaled(0.475f, 0.92f, 0.05f)
                         .build<Cube>());

    // 5. Maçaneta Simples
    partes.push_back(builder.at(0.4f, 0.0f, 0.06f)
                         .colored(0.7f, 0.6f, 0.1f)
                         .scaled(0.05f, 0.1f, 0.05f)
                         .build<Cube>());
}

void Porta::draw() const
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(xg, 1.0f, 0.0f, 0.0f);
    glRotatef(yg, 0.0f, 1.0f, 0.0f);
    glRotatef(zg, 0.0f, 0.0f, 1.0f);
    glScalef(sx, sy, sz);

    for (const auto &p : partes)
    {
        p->draw();
    }
    glPopMatrix();
}