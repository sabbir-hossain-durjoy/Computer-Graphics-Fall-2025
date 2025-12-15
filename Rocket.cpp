#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Coordinate system
const int MIN_X = -10;
const int MAX_X = 60;
const int MIN_Y = -10;
const int MAX_Y = 60;

// Bresenham (with thick points)
void drawLine(int x1, int y1, int x2, int y2) {

    glPointSize(6.0);  // 🔥 THICK POINTS FOR BOLD VISIBILITY

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (true) {
        glVertex2i(x1, y1);
        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx)  { err += dx; y1 += sy; }
    }
    glEnd();
}

// Dark grid
void drawGrid() {
    glColor3f(0.15, 0.15, 0.15);
    glBegin(GL_LINES);
    for (int i = MIN_X; i <= MAX_X; i++) {
        glVertex2i(i, MIN_Y);
        glVertex2i(i, MAX_Y);
    }
    for (int i = MIN_Y; i <= MAX_Y; i++) {
        glVertex2i(MIN_X, i);
        glVertex2i(MAX_X, i);
    }
    glEnd();
}

// Rocket (SUPER BOLD COLORS)
void drawRocket() {

    // ---------------- BODY (NEON CYAN) ----------------
    glColor3f(0.0, 1.0, 1.0);  // ★ BOLD CYAN
    drawLine(20, 15, 20, 40);
    drawLine(30, 15, 30, 40);
    drawLine(20, 15, 30, 15);
    drawLine(20, 40, 30, 40);

    // ---------------- NOSE (BRIGHT NEON BLUE) ----------------
    glColor3f(0.0, 0.4, 1.0); // ★ STRONG BLUE
    drawLine(20, 40, 25, 52);
    drawLine(30, 40, 25, 52);
    drawLine(20, 40, 30, 40);

    // ---------------- WINDOW (NEON YELLOW) ----------------
    glColor3f(1.0, 1.0, 0.0); // ★ BRIGHT YELLOW
    drawLine(23, 28, 27, 28);
    drawLine(27, 28, 27, 32);
    drawLine(27, 32, 23, 32);
    drawLine(23, 32, 23, 28);

    glColor3f(1.0, 1.0, 1.0); // highlight
    glPointSize(7);
    glBegin(GL_POINTS);
    glVertex2i(24, 31);
    glEnd();

    // ---------------- FINS (NEON MAGENTA & PURPLE) ----------------
    glColor3f(1.0, 0.0, 1.0); // ★ MAGENTA LEFT
    drawLine(20, 20, 14, 10);
    drawLine(20, 15, 14, 10);
    drawLine(20, 15, 20, 20);

    glColor3f(0.7, 0.0, 1.0); // ★ VIOLET RIGHT
    drawLine(30, 20, 36, 10);
    drawLine(30, 15, 36, 10);
    drawLine(30, 15, 30, 20);

    // ---------------- FLAMES (ULTRA BOLD COLORS) ----------------
    glColor3f(1.0, 0.3, 0.0); // ★ RED-ORANGE OUTER
    drawLine(22, 15, 25, 4);
    drawLine(28, 15, 25, 4);
    drawLine(22, 15, 28, 15);

    glColor3f(1.0, 1.0, 0.0); // ★ BRIGHT YELLOW INNER
    drawLine(24, 15, 25, 8);
    drawLine(26, 15, 25, 8);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawGrid();
    drawRocket();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(MIN_X, MAX_X, MIN_Y, MAX_Y);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Ultra-Visible Rocket (Bold Colors)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
