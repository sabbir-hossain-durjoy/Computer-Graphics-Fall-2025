#include <GL/glut.h>

float angleX = 0, angleY = 0, angleZ = 0;
float scaleVal = 1.0f;
float tx = 0, ty = 0, tz = 0;

void drawCube()
{
    glBegin(GL_QUADS);

    glColor3f(1, 0, 0);
    glVertex3f(-1, -1,  1);
    glVertex3f( 1, -1,  1);
    glVertex3f( 1,  1,  1);
    glVertex3f(-1,  1,  1);

    glColor3f(0, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1,  1, -1);
    glVertex3f( 1,  1, -1);
    glVertex3f( 1, -1, -1);

    glColor3f(0, 0, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1,  1);
    glVertex3f(-1,  1,  1);
    glVertex3f(-1,  1, -1);

    glColor3f(1, 1, 0);
    glVertex3f(1, -1, -1);
    glVertex3f(1,  1, -1);
    glVertex3f(1,  1,  1);
    glVertex3f(1, -1,  1);

    glColor3f(0, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1,  1);
    glVertex3f( 1, 1,  1);
    glVertex3f( 1, 1, -1);

    glColor3f(1, 0, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f( 1, -1, -1);
    glVertex3f( 1, -1,  1);
    glVertex3f(-1, -1,  1);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(6, 6, 10,  0, 0, 0,  0, 1, 0);

    glTranslatef(tx, ty, tz);
    glScalef(scaleVal, scaleVal, scaleVal);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);
    glRotatef(angleZ, 0, 0, 1);

    drawCube();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int, int)
{
    switch (key)
    {
        case 'x': angleX += 5; break;
        case 'y': angleY += 5; break;
        case 'z': angleZ += 5; break;

        case 'X': angleX -= 5; break;
        case 'Y': angleY -= 5; break;
        case 'Z': angleZ -= 5; break;

        case '+': scaleVal += 0.1f; break;
        case '-':
            scaleVal -= 0.1f;
            if (scaleVal < 0.2f) scaleVal = 0.2f;
            break;

        case 'w': ty += 0.2f; break;
        case 's': ty -= 0.2f; break;
        case 'a': tx -= 0.2f; break;
        case 'd': tx += 0.2f; break;
        case 'q': tz += 0.2f; break;
        case 'e': tz -= 0.2f; break;
    }

    glutPostRedisplay();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.6f, 0.8f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 50.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("3D Object using OpenGL & Transformations");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
