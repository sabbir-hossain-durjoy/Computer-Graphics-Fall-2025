#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glColor3f (0.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.2, 0.7, 0.0);
glVertex3f (0.5, 1.0, 0.0);
glVertex3f (0.8, 0.7, 0.0);
glEnd();

glColor3f (1.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.3, 0.7, 0.0);
glVertex3f (0.3, 0.2, 0.0);
glVertex3f (0.7, 0.2, 0.0);
glVertex3f (0.7, 0.7, 0.0);
glEnd();

glColor3f (0.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.4, 0.2, 0.0);
glVertex3f (0.4, 0.1, 0.0);
glVertex3f (0.6, 0.1, 0.0);
glVertex3f (0.6, 0.2, 0.0);
glEnd();

glColor3f (1.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.4, 0.6, 0.0);
glVertex3f (0.4, 0.4, 0.0);
glVertex3f (0.6, 0.4, 0.0);
glVertex3f (0.6, 0.6, 0.0);
glEnd();

glColor3f (1.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.3, 0.5, 0.0);
glVertex3f (0.2, 0.2, 0.0);
glVertex3f (0.3, 0.2, 0.0);
glEnd();

glColor3f (1.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.7, 0.5, 0.0);
glVertex3f (0.7, 0.2, 0.0);
glVertex3f (0.8, 0.2, 0.0);
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