#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Set background to blue
    gluOrtho2D(0, 500, 0, 500);        // Set coordinate system
}

// Function to draw a circle
void drawCircle(int h, int k, int rx, int ry)
{
    glColor3f(1.0, 1.0, 1.0);  // Yellow color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        glVertex2f(h + rx * cos(3.14159 * i / 180), k + ry * sin(3.14159 * i / 180));
    }
    glEnd();
}

void drawCircle2(int h, int k, int rx, int ry, int a, int b, int c)
{
    glColor3f(a, b, c);  // Yellow color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        glVertex2f(h + rx * cos(3.14159 * i / 180), k + ry * sin(3.14159 * i / 180));
    }
    glEnd();
}

// Function to draw a triangle
/*void drawTriangle(void)
{
    glColor3f(1.0, 1.0, 0.0);  // Yellow color
    glBegin(GL_TRIANGLES);
        glVertex2i(150, 150);  // Bottom-left
        glVertex2i(350, 150);  // Bottom-right
        glVertex2i(250, 300);  // Top peak
    glEnd();
}
*/
// Function to display both the circle and triangle
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear screen (sets background to blue)

    drawCircle(250, 350, 30, 30);  // Draw the circle at (250, 350)
   // drawTriangle();                // Draw the triangle at predefined coordinates

    drawCircle(400, 350, 40, 30);
    drawCircle(430, 350, 30, 30);
    drawCircle(410, 360, 30, 30);
    drawCircle(380, 360, 30, 30);
    drawCircle(360, 350, 25, 25);

    drawCircle(100, 350, 40, 30);
    drawCircle(100, 380, 30, 30);
    drawCircle(130, 360, 30, 30);
    drawCircle(80, 370, 30, 30);
    drawCircle(60, 360, 30, 30);


    //glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.8, 1.0, 0.3);
    glBegin(GL_POLYGON);
    glVertex3f (80, 0, 0.0);
    glVertex3f (100, 0, 0.0);
    glVertex3f (100, 100, 0.0);
    glVertex3f (80, 100, 0.0);
    glEnd();

    drawCircle2(90, 100, 40, 60, 0, 1, 0);


    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (390, 0, 0.0);
    glVertex3f (410, 0, 0.0);
    glVertex3f (410, 60, 0.0);
    glVertex3f (390, 60, 0.0);
    glEnd();

    glColor3f (0.7, 1.8, 1.8);
    glBegin(GL_POLYGON);
    glVertex3f (360, 60, 0.0);
    glVertex3f (440, 60, 0.0);
    glVertex3f (440, 180, 0.0);
    glVertex3f (360, 180, 0.0);
    glEnd();


    drawCircle2(400, 90, 10, 10, 1, 0, 0);
    drawCircle2(400, 120, 10, 10, 0, 1, 0);
    drawCircle2(400, 150, 10, 10, 0, 0, 1);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle and Triangle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}