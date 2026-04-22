#include <GL/glut.h>
#include <stdlib.h>
#include "Polygon.h"
#include "Camera.h"
#include "iostream"
#include "Sala.h"
#include <vector>
#include <memory>
using namespace std;

static int rot = 0;
Camera cam(0.0f, 2.0f, 15.0f, 270.0f, 0.0f);

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cam.placeCamera();

    glPushMatrix();
    glRotatef((GLfloat)rot, 0.0, 1.0, 0.0);

    vector<unique_ptr<Polygon>> polygons;

    auto sala = PolygonBuilder().at(0, 0.5f, 5).colored(0.25f, 0.25f, 0.25f).scaled(1.5f, 1.5f, 1.5f).build<Sala>();
    sala->draw();

    // polygons.push_back(

    // // Cadeira — posicionada acima do chao (y=0.5 para ficar sobre o piso)


    // for (const auto &obj : polygons)
    // {
    //     obj->draw();
    // }

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    cam.reshape(w, h);
}

void keyboard(unsigned char key, int, int)
{
    switch (key)
    {
    case 'w': cam.moveForward(0.5f);  break;
    case 's': cam.moveForward(-0.5f); break;
    case 'a': cam.moveRight(-0.5f);   break;
    case 'd': cam.moveRight(0.5f);    break;
    case 'q': cam.rotateYaw(-5.0f);   break;
    case 'e': cam.rotateYaw(5.0f);    break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}