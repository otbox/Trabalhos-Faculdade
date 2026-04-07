#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
    /*  clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);

    /*  draw white polygon (rectangle) with corners at
     *  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */
    glColor3f(1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex3f (0.25, 0.25, 0.0);
    glVertex3f (0.75, 0.25, 0.0);
    glVertex3f (0.75, 0.75, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();
    // glBegin(GL_POLYGON);
    // glVertex3f(0.25, 0.25, 0.0);
    // glVertex3f(1.85, 0.25, 0.0);
    // glVertex3f(1.85, 0.85, 0.0);
    // glVertex3f(0.25, 0.85, 0.0);
    // glEnd();

    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // glColor3f (1.0, 1.0, 0.0);
    // glBegin(GL_POLYGON);
    //     glVertex3f (0.50, 0.75, 0.0); //Cima
    //     glVertex3f (0.75, 0.55, 0.0); //Direita
    //     glVertex3f (0.65, 0.25, 0.0); //Baixo direita
    //     glVertex3f (0.35, 0.25, 0.0); //Baixo Esquerda
    //     glVertex3f (0.25, 0.55, 0.0); // Essquerda
    // glEnd();
    
    // glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x3333);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f (0.45, 0.45, 0.0); //Cima
        glVertex3f (0.55, 0.45, 0.0); //Baixo direita
        glVertex3f (0.55, 0.55, 0.0); //Direita
        glVertex3f (0.45, 0.55, 0.0); //Baixo Esquerda
        // glVertex3f (0.25, 0.55, 0.0); // Essquerda
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f (0.65, 0.65, 0.0); //Cima
        glVertex3f (0.35, 0.65, 0.0); //Baixo direita
        glVertex3f (0.35, 0.35, 0.0); //Direita
        glVertex3f (0.65, 0.35, 0.0); //Baixo Esquerda
        // glVertex3f (0.25, 0.55, 0.0); // Essquerda
    glEnd();


    /*  don't wait!
     *  start processing buffered OpenGL routines
     */
    glFlush();
}

void init(void)
{
    /*  select clearing (background) color       */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // tecla Esc (encerra o programa)
        exit(0);
        break;
    }
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}