#include "Cadeira.h"
#include <GL/glut.h>

Cadeira::Cadeira(float px, float py, float pz,
                 float psx, float psy, float psz,
                 float pr, float pg, float pb,
                 float xg, float yg, float zg)
    : Polygon(px, py, pz, psx, psy, psz, pr, pg, pb, xg, yg, zg)
{

    // Cores e Materiais da Imagem
    float cor_assento_r = pr, cor_assento_g = pg, cor_assento_b = pb;
    float cor_base_r = 0.1f, cor_base_g = 0.1f, cor_base_b = 0.1f;

    // Assento 
    partes.push_back(
        PolygonBuilder()
            .at(0.0f, -0.1f, -0.04f) 
            .colored(cor_assento_r, cor_assento_g, cor_assento_b)
            .scaled(0.9f, 0.12f, 0.9f) 
            .build<Cube>());

    // Carcaça Preta do Encosto (Forma as bordas e a parte de trás)
    partes.push_back(
        PolygonBuilder()
            .at(0.0f, 0.3f, -0.48f)                      
            .colored(cor_base_r, cor_base_g, cor_base_b) 
            .scaled(0.92f, 0.98f, 0.15f)
            .rotated(-25.0f, 0.0f, 0.0f) 
            .build<Cube>());

    // Carcaça Preta Inferior (Base do Assento)
    partes.push_back(
        PolygonBuilder()
            .at(0.0f, -0.16f, -0.1f)                    
            .colored(cor_base_r, cor_base_g, cor_base_b) 
            .scaled(0.92f, 0.06f, 0.92f)                 
            .build<Cube>());
    // Encosto (Couro Vermelho, Alto)

    partes.push_back(
        PolygonBuilder()
            .at(0.0f, 0.4f, -0.42f) // Alto e para trás
            .colored(cor_assento_r, cor_assento_g, cor_assento_b)
            .scaled(0.9f, 0.9f, 0.12f)   // Alto e profundo
            .rotated(-25.0f, 0.0f, 0.0f) // Maior e mais espesso que a almofada (0.9f x 0.9f x 0.12f)
            .build<Cube>());

    // Braco esquerdo (Plástico Preto com Porta-Copos)
    partes.push_back(
        PolygonBuilder()
            .at(-0.48f, 0.1f, -0.05f)
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(0.12f, 0.12f, 0.9f)
            .build<Cube>());

    // Braco direito (Plástico Preto com Porta-Copos)
    partes.push_back(
        PolygonBuilder()
            .at(0.48f, 0.1f, -0.05f)
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(0.12f, 0.12f, 0.9f)
            .build<Cube>());

    // Painel vermelho abaixo do porta-copos esquerdo
    partes.push_back(
        PolygonBuilder()
            .at(-0.48f, -0.25f, 0.0f)
            .colored(cor_assento_r, cor_assento_g, cor_assento_b)
            .scaled(0.1f, 0.7f, 0.75f)
            .build<Cube>());

    // Painel vermelho abaixo do porta-copos direito
    partes.push_back(
        PolygonBuilder()
            .at(0.48f, -0.25f, 0.0f)
            .colored(cor_assento_r, cor_assento_g, cor_assento_b)
            .scaled(0.1f, 0.7f, 0.75f)
            .build<Cube>());

    // 5. Pilar Central
    partes.push_back(
        PolygonBuilder()
            .at(0.0f, -0.3f, -0.1f) // Centro
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(0.3f, 0.4f, 0.3f) // Pilar largo
            .build<Cube>());

    // 6. Barra Transversal Central (No chão)
    partes.push_back(
        PolygonBuilder()
            .at(0.0f, -0.5f, -0.1f) // No chão
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(1.0f, 0.1f, 0.4f) // Barra horizontal
            .build<Cube>());

    // Pernas de Apoio Externas
    // Perna de apoio esquerda
    partes.push_back(
        PolygonBuilder()
            .at(-0.4f, -0.6f, -0.1f)
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(0.1f, 0.3f, 0.1f)
            .build<Cube>());

    // Perna de apoio direita
    partes.push_back(
        PolygonBuilder()
            .at(0.4f, -0.6f, -0.1f)
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(0.1f, 0.3f, 0.1f)
            .build<Cube>());

    // Placas de Montagem
    float espessura_placa = 0.02f;
    float tamanho_placa = 0.15f;
    float offset_y_placa = -0.7f;

    // Placa dianteira esquerda
    partes.push_back(
        PolygonBuilder()
            .at(-0.4f, offset_y_placa, 0.0f)
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(tamanho_placa, espessura_placa, tamanho_placa)
            .build<Cube>());

    // Placa traseira esquerda
    partes.push_back(
        PolygonBuilder()
            .at(-0.4f, offset_y_placa, -0.2f)
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(tamanho_placa, espessura_placa, tamanho_placa)
            .build<Cube>());

    // Placa dianteira direita
    partes.push_back(
        PolygonBuilder()
            .at(0.4f, offset_y_placa, 0.0f)
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(tamanho_placa, espessura_placa, tamanho_placa)
            .build<Cube>());

    // Placa traseira direita
    partes.push_back(
        PolygonBuilder()
            .at(0.4f, offset_y_placa, -0.2f)
            .colored(cor_base_r, cor_base_g, cor_base_b)
            .scaled(tamanho_placa, espessura_placa, tamanho_placa)
            .build<Cube>());
}

void Cadeira::draw() const
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(xg, 1.0f, 0.0f, 0.0f);
    glRotatef(yg, 0.0f, 1.0f, 0.0f);
    glRotatef(zg, 0.0f, 0.0f, 1.0f);
    glScalef(sx, sy, sz);
    for (const auto &obj : partes)
    {
        obj->draw();
    }
    glPopMatrix();
}