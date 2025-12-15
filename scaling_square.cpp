#include <GL/glut.h>

float square[4][2] = {
    {50, 50},
    {100, 50},
    {100, 100},
    {50, 100}
};

float Sx = 1.5f;
float Sy = 1.5f;

void drawSquare(float v[4][2])
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; i++)
        glVertex2f(v[i][0], v[i][1]);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    drawSquare(square);

    float scaledSquare[4][2];
    for (int i = 0; i < 4; i++)
    {
        scaledSquare[i][0] = square[i][0] * Sx;
        scaledSquare[i][1] = square[i][1] * Sy;
    }

    glColor3f(1.0, 0.0, 0.0);
    drawSquare(scaledSquare);

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 300, 0, 300);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2D Scaling Transformation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
