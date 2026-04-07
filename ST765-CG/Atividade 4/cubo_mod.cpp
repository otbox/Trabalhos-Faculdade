#include <GL/glut.h>
#include <stdlib.h>

static int rot = 0;

void init(void){
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glEnable(GL_DEPTH_TEST);
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

/* rotacao da cena*/
glPushMatrix();
glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);


/* Chao */
 glColor3f(0.0,0.0,0.0);
 glPushMatrix();
// glTranslatef (-2.0, 0.0, 0.0);
 glScalef (3.0, 0.2, 2.6);
 glutSolidCube (1.0);
 glPopMatrix();
 
/* pilar 1 - direita frontal */
 glColor3f(1.0,1.0,0.0);
 glPushMatrix();
 glTranslatef (1.4, 1.4, 1.2);
 glScalef (0.2, 2.6, 0.2);
 glutSolidCube (1.0);
 glPopMatrix();

/* pilar 2 - direita fundo */
 glPushMatrix();
 glTranslatef (1.4, 1.4, -1.2);
 glScalef (0.2, 2.6, 0.2);
 glutSolidCube (1.0);
 glPopMatrix();

/* pilar 3 - esquerda frontal */
 glPushMatrix();
 glTranslatef (-1.4, 1.4, 1.2);
 glScalef (0.2, 2.6, 0.2);
 glutSolidCube (1.0);
 glPopMatrix();

/* pilar 4 - esquerda fundo */
 glPushMatrix();
 glTranslatef (-1.4, 1.4, -1.2);
 glScalef (0.2, 2.6, 0.2);
 glutSolidCube (1.0);
 glPopMatrix();

/* coluna 1 - horizontal frontal */
 glColor3f(1.0,0.0,0.0);
 glPushMatrix();
 glTranslatef (0.0, 2.6, 1.2);
 glScalef (2.6, 0.2, 0.2);
 glutSolidCube (1.0);
 glPopMatrix();

/* coluna 2 - horizontal fundo */
 glPushMatrix();
     (0.0, 2.6, -1.2);
 glScalef (2.6, 0.2, 0.2);
 glutSolidCube (1.0);
 glPopMatrix();


glPopMatrix(); //da rotacao da cena

glutSwapBuffers();

}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, -3.0, -10.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 'q':
  rot = (rot+5) % 360;
  glutPostRedisplay();
  break;
  case 'e':
  rot = (rot-5) % 360;
  glutPostRedisplay();
  break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
