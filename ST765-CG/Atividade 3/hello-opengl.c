#include <GL/gl.h>
#include <GL/glut.h>

const int WIDTH = 800;
const int HEIGHT = 800;
const int SIZE = 80;
int toolFlag = 0;

void createGrid (int size) {
    int x = 0, y = 0;
    int c = 0;
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(0.5f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glBegin(GL_TRIANGLE_STRIP);
    
    if (size < 0){
        y += size * 2;
    }
    while (y < HEIGHT)  {
        if (abs(x) > WIDTH + abs(size)) {
            y += abs(size);
            size *= -1;
        }
        glVertex3f (x, y, 0.0);
        glVertex3f (x, y + abs(size), 0.0);
        x += size;
    }
    glEnd(); 
}

void renderGrid(int size) {
    createGrid(size);
    createGrid(-size);
}

void createNormalizePoints (int x, int y){
    glVertex3f (x * SIZE, y * SIZE, 0.0);
}

void renderTool() {
    glColor3f(1.0, 1.0, 0.0);
    glLineWidth(4.0f);

    glPolygonMode(GL_FRONT_AND_BACK, toolFlag ? GL_LINE : GL_FILL);

    // CABECA Esquerda
    glBegin(GL_POLYGON);
    createNormalizePoints(3,6);
    createNormalizePoints(2,7);
    createNormalizePoints(2,9);
    createNormalizePoints(3,10);
    createNormalizePoints(3,8);
    createNormalizePoints(4,7);
    createNormalizePoints(5,7);
    createNormalizePoints(5,6);
    glEnd();
    // Cabeca Direireita
    glBegin(GL_POLYGON);
    createNormalizePoints(6,6);
    createNormalizePoints(7,7);
    createNormalizePoints(7,9);
    createNormalizePoints(6,10);
    createNormalizePoints(6,8);
    createNormalizePoints(5,7);
    createNormalizePoints(5,6);
    glEnd();
    // CABO
    glBegin(GL_POLYGON);
    createNormalizePoints(4,1);
    createNormalizePoints(3,2);
    createNormalizePoints(3,6);
    createNormalizePoints(6,6);
    createNormalizePoints(6,2);
    createNormalizePoints(5,1);
    glEnd();
}

void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int mouseX = x;
        int mouseY = HEIGHT - y;

        int toolMinX = 2 * SIZE, toolMaxX = 7 * SIZE;
        int toolMinY = 1 * SIZE, toolMaxY = 10 * SIZE;
        int xFlag = mouseX >= toolMinX && mouseX <= toolMaxX ? 1 : 0; 
        int yFlag = mouseY >= toolMinY && mouseY <= toolMaxY ? 1 : 0; 
        if (xFlag && yFlag) {
            toolFlag = !toolFlag;
            glutPostRedisplay();
        }
    }
}

void display(void)
{
    /*  clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);
    renderGrid(SIZE);
    renderTool();
    glFlush();
}

void init(void)
{
    /*  select clearing (background) color       */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -1, 1);
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
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CarTool");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}   