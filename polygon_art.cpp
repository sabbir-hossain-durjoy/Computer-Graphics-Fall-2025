#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.5, 1.0, 0.0);
glVertex3f (0.4, 0.9, 0.0);
glVertex3f (0.6, 0.9, 0.0);
glEnd();

glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.6, 0.9, 0.0);
glVertex3f (0.4, 0.9, 0.0);
glVertex3f (0.3, 0.8, 0.0);
glVertex3f (0.7, 0.8, 0.0);
glEnd();


glColor3f (1.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.58, 0.8, 0.0);
glVertex3f (0.42, 0.8, 0.0);
glVertex3f (0.3, 0.7, 0.0);
glVertex3f (0.42, 0.6, 0.0);
glVertex3f (0.58, 0.6, 0.0);
glVertex3f (0.7, 0.7, 0.0);
glEnd();

glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.6, 0.6, 0.0);
glVertex3f (0.4, 0.6, 0.0);
glVertex3f (0.3, 0.5, 0.0);
glVertex3f (0.7, 0.5, 0.0);
glEnd();


glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.3, 0.5, 0.0);
glVertex3f (0.2, 0.4, 0.0);
glVertex3f (0.8, 0.4, 0.0);
glVertex3f (0.7, 0.5, 0.0);
glEnd();

glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.5, 0.5, 0.0);
glVertex3f (0.6, 0.4, 0.0);
glVertex3f (0.7, 0.5, 0.0);
glEnd();

glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.8, 0.4, 0.0);
glVertex3f (0.6, 0.4, 0.0);
glVertex3f (0.7, 0.5, 0.0);
glEnd();


glColor3f (0.5, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.3, 0.4, 0.0);
glVertex3f (0.3, 0.3, 0.0);
glVertex3f (0.42, 0.3, 0.0);
glVertex3f (0.42, 0.4, 0.0);
glEnd();
glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.3, 0.3, 0.0);
glVertex3f (0.3, 0.2, 0.0);
glVertex3f (0.42, 0.2, 0.0);
glVertex3f (0.42, 0.3, 0.0);
glEnd();
glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.3, 0.2, 0.0);
glVertex3f (0.3, 0.1, 0.0);
glVertex3f (0.42, 0.1, 0.0);
glVertex3f (0.42, 0.2, 0.0);
glEnd();



glColor3f (0.5, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.58, 0.4, 0.0);
glVertex3f (0.58, 0.3, 0.0);
glVertex3f (0.7, 0.3, 0.0);
glVertex3f (0.7, 0.4, 0.0);
glEnd();
glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.58, 0.3, 0.0);
glVertex3f (0.58, 0.2, 0.0);
glVertex3f (0.7, 0.2, 0.0);
glVertex3f (0.7, 0.3, 0.0);
glEnd();
glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.58, 0.2, 0.0);
glVertex3f (0.58, 0.1, 0.0);
glVertex3f (0.7, 0.1, 0.0);
glVertex3f (0.7, 0.2, 0.0);
glEnd();

glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.36, 0.1, 0.0);
glVertex3f (0.3, 0.0, 0.0);
glVertex3f (0.42, 0.0, 0.0);
glEnd();

glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.64, 0.1, 0.0);
glVertex3f (0.58, 0.0, 0.0);
glVertex3f (0.7, 0.0, 0.0);
glEnd();



glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.35, 0.55, 0.0);
glVertex3f (0.23, 0.55, 0.0);
glVertex3f (0.14, 0.64, 0.0);
glVertex3f (0.26, 0.64, 0.0);
glEnd();

glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.65, 0.55, 0.0);
glVertex3f (0.77, 0.55, 0.0);
glVertex3f (0.86, 0.64, 0.0);
glVertex3f (0.74, 0.64, 0.0);
glEnd();

glFlush ();
}
void init (void)
{

glClearColor (0.0, 0.0, 0.0, 0.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("hello");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}