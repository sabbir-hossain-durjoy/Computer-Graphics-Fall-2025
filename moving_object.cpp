#include <GL/gl.h>
#include <windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

void drawCircle(float h, float k, float rx, float ry, float a, float b, float c)
{
    glColor3f(a, b, c);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        glVertex2f(h + rx * cos(3.14159 * i / 180), k + ry * sin(3.14159 * i / 180));
    }
    glEnd();
}

float p = 0.0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (p >= -15)
        p = p - .005;
    else
        p = 10;

    glutPostRedisplay();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.2, 0.0);
    glVertex2f(p - 2, -4);
    glVertex2f(p + 4, -4);
    glVertex2f(p + 4, -1);
    glVertex2f(p - 2, -1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.4, 1.0);
    glVertex2f(p + 0, -2);
    glVertex2f(p + 0, -3);
    glVertex2f(p + 1, -3);
    glVertex2f(p + 1, -2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.4, 1.0);
    glVertex2f(p + 2, -2);
    glVertex2f(p + 2, -3);
    glVertex2f(p + 3, -3);
    glVertex2f(p + 3, -2);
    glEnd();

    drawCircle(p + 0, -4, 0.5, 0.5, 0, 0, 0);
    drawCircle(p + 2, -4, 0.5, 0.5, 0, 0, 0);

    glFlush();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(-10, 10, -10, 10, -10, 10);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("moving_object");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
