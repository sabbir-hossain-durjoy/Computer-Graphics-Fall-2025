#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

constexpr float PI = 3.14159265358979323846f;

int frameNumber = 1;

GLfloat position_c1 = 1.6f, speed_c1 = 0.01f;
GLfloat position_c2 = 2.4f, speed_c2 = 0.01f;
GLfloat position_c3 = -0.9f, speed_c3 = 0.01f;
GLfloat position_c4 = 0.9f, speed_c4 = 0.01f;

GLfloat position_rain = 0.0f, speed_rain = 0.05f;
GLfloat position_rain2 = 2.0f, speed_rain2 = 0.05f;

int cnt = 0;
int flag = 0;
int r = 0;

static void drawCircle(float cx, float cy, float rad, int segments = 60) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= segments; i++) {
            float ang = 2.0f * PI * i / segments;
            glVertex2f(cx + rad * cosf(ang), cy + rad * sinf(ang));
        }
    glEnd();
}

static void setOrtho() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2, 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void windmill() {
    glPushMatrix();
    glTranslatef(1.6f, 0.3f, 0.0f);

    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
        glVertex2f(-0.80f, 0.275f);
        glVertex2f(-0.80f, 0.25f);
        glVertex2f(-0.65f, 0.25f);
        glVertex2f(-0.65f, 0.275f);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
        glVertex2f(-0.775f, 0.5f);
        glVertex2f(-0.79f, 0.275f);
        glVertex2f(-0.66f, 0.275f);
        glVertex2f(-0.675f, 0.5f);
    glEnd();

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2f(-0.71f, 0.35f);
        glVertex2f(-0.71f, 0.275f);
        glVertex2f(-0.74f, 0.275f);
        glVertex2f(-0.74f, 0.35f);
    glEnd();

    glColor3ub(51, 153, 255);
    glBegin(GL_POLYGON);
        glVertex2f(-0.71f, 0.45f);
        glVertex2f(-0.71f, 0.4f);
        glVertex2f(-0.74f, 0.4f);
        glVertex2f(-0.74f, 0.45f);
    glEnd();

    glColor3ub(0, 102, 204);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.79f, 0.5f);
        glVertex2f(-0.725f, 0.63f);
        glVertex2f(-0.66f, 0.5f);
    glEnd();

    glTranslatef(-0.725f, 0.55f, 0.0f);
    glRotatef(frameNumber * (-180.0f / 500.0f), 0, 0, 1);

    for (int k = 0; k < 4; k++) {
        glColor3ub(204, 229, 255);
        glBegin(GL_POLYGON);
            glVertex2f(0.00f, 0.01f);
            glVertex2f(0.00f, 0.00f);
            glVertex2f(0.20f, 0.00f);
            glVertex2f(0.20f, 0.01f);
        glEnd();

        glColor3ub(255, 51, 51);
        glBegin(GL_POLYGON);
            glVertex2f(0.03f, 0.05f);
            glVertex2f(0.03f, 0.01f);
            glVertex2f(0.20f, 0.01f);
            glVertex2f(0.20f, 0.05f);
        glEnd();

        glRotatef(90, 0, 0, 1);
    }

    glColor3ub(255, 51, 51);
    drawCircle(0.0f, 0.0f, 0.02f);

    glPopMatrix();
}

void tree() {
    glLineWidth(10.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-1.5f, 0.8f);
        glVertex2f(-1.5f, 0.55f);
    glEnd();

    glColor3ub(0, 153, 51);
    drawCircle(-1.45f, 0.82f, 0.08f);
    drawCircle(-1.5f, 0.85f, 0.08f);
    drawCircle(-1.55f, 0.82f, 0.08f);

    glPointSize(5.0);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-1.53f, 0.85f);
        glVertex2f(-1.47f, 0.8f);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-0.8f, 0.8f);
        glVertex2f(-0.8f, 0.57f);
    glEnd();

    glColor3ub(0, 153, 51);
    drawCircle(-0.85f, 0.82f, 0.08f);
    drawCircle(-0.8f, 0.85f, 0.08f);
    drawCircle(-0.75f, 0.82f, 0.08f);

    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(1.55f, 0.65f);
        glVertex2f(1.55f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 153, 51);
        glVertex2f(1.45f, 0.7f);
        glVertex2f(1.55f, 0.95f);
        glVertex2f(1.65f, 0.7f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-0.2f, 0.65f);
        glVertex2f(-0.2f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 153, 51);
        glVertex2f(-0.3f, 0.7f);
        glVertex2f(-0.2f, 0.95f);
        glVertex2f(-0.1f, 0.7f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(1.9f, 0.7f);
        glVertex2f(1.9f, 0.85f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 153, 51);
        glVertex2f(1.8f, 0.75f);
        glVertex2f(1.9f, 1.0f);
        glVertex2f(2.0f, 0.75f);
    glEnd();
}

void shop() {
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(-1.95f, 0.5f);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-1.55f, 0.75f);
        glVertex2f(-1.55f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);
        glVertex2f(-1.5f, 0.7f);
        glVertex2f(-1.55f, 0.75f);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-2.0f, 0.7f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(139, 69, 19);
        glVertex2f(-1.9f, 0.5f);
        glVertex2f(-1.9f, 0.62f);
        glColor3ub(0, 153, 153);
        glVertex2f(-1.82f, 0.62f);
        glVertex2f(-1.82f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(135, 206, 250);
        glVertex2f(-1.77f, 0.55f);
        glVertex2f(-1.77f, 0.62f);
        glColor3ub(0, 153, 153);
        glVertex2f(-1.6f, 0.62f);
        glVertex2f(-1.6f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 204, 102);
        glVertex2f(-0.75f, 0.5f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(77, 38, 0);
        glVertex2f(-0.73f, 0.6f);
        glVertex2f(-0.73f, 0.75f);
        glVertex2f(-0.22f, 0.75f);
        glVertex2f(-0.22f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(128, 64, 0);
        glVertex2f(-0.73f, 0.5f);
        glVertex2f(-0.73f, 0.6f);
        glVertex2f(-0.22f, 0.6f);
        glVertex2f(-0.22f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(130, 15, 100);
        glVertex2f(-0.15f, 0.75f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.8f, 0.75f);
    glEnd();
}

void house() {
    glBegin(GL_POLYGON);
        glColor3ub(224, 228, 0);
        glVertex2f(-1.4f, 0.5f);
        glVertex2f(-1.4f, 1.0f);
        glVertex2f(-0.9f, 1.0f);
        glVertex2f(-0.9f, 0.5f);
    glEnd();

    auto win = [](float x1, float y1, float x2, float y2) {
        glBegin(GL_POLYGON);
            glColor3ub(135, 206, 250);
            glVertex2f(x1, y1);
            glVertex2f(x1, y2);
            glColor3ub(0, 230, 230);
            glVertex2f(x2, y2);
            glVertex2f(x2, y1);
        glEnd();
    };

    win(-1.35f, 0.55f, -1.25f, 0.65f);
    win(-1.05f, 0.55f, -0.95f, 0.65f);
    win(-1.35f, 0.85f, -1.25f, 0.95f);
    win(-1.2f, 0.85f, -1.1f, 0.95f);
    win(-1.05f, 0.85f, -0.95f, 0.95f);

    glBegin(GL_POLYGON);
        glColor3ub(139, 69, 19);
        glVertex2f(-1.2f, 0.5f);
        glVertex2f(-1.2f, 0.65f);
        glVertex2f(-1.1f, 0.65f);
        glVertex2f(-1.1f, 0.5f);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
        glColor3f(1, 1, 1);
        glVertex2f(-1.17f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(153, 1, 0);
        glVertex2f(-0.15f, 0.5f);
        glVertex2f(-0.15f, 0.8f);
        glVertex2f(0.35f, 0.8f);
        glVertex2f(0.35f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(153, 1, 0);
        glVertex2f(0.05f, 0.8f);
        glVertex2f(0.05f, 0.99f);
        glVertex2f(0.35f, 0.99f);
        glVertex2f(0.35f, 0.8f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(135, 206, 250);
        glVertex2f(0.05f, 0.6f);
        glVertex2f(0.05f, 0.7f);
        glColor3ub(26, 140, 255);
        glVertex2f(0.15f, 0.7f);
        glVertex2f(0.15f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(135, 206, 250);
        glVertex2f(0.2f, 0.6f);
        glVertex2f(0.2f, 0.7f);
        glColor3ub(26, 140, 255);
        glVertex2f(0.3f, 0.7f);
        glVertex2f(0.3f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(135, 206, 250);
        glVertex2f(0.15f, 0.85f);
        glVertex2f(0.15f, 0.95f);
        glColor3ub(26, 140, 255);
        glVertex2f(0.25f, 0.95f);
        glVertex2f(0.25f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(139, 69, 19);
        glVertex2f(-0.1f, 0.5f);
        glVertex2f(-0.1f, 0.65f);
        glVertex2f(0.0f, 0.65f);
        glVertex2f(0.0f, 0.5f);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
        glColor3f(1, 1, 1);
        glVertex2f(-0.03f, 0.6f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 255, 0);
        glVertex2f(0.36f, 0.8f); glVertex2f(-0.16f, 0.8f);
        glVertex2f(0.36f, 0.84f); glVertex2f(-0.16f, 0.84f);
        for (float xx = -0.14f; xx <= 0.35f; xx += 0.05f) {
            glVertex2f(xx, 0.8f); glVertex2f(xx, 0.84f);
        }
    glEnd();
}

void factory() {
    glBegin(GL_POLYGON);
        glColor3ub(163, 136, 151);
        glVertex2f(1.5f, -0.8f);
        glVertex2f(1.55f, -0.4f);
        glVertex2f(1.65f, -0.4f);
        glVertex2f(1.7f, -0.8f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(220, 170, 159);
        glVertex2f(1.45f, -2.0f);
        glVertex2f(1.45f, -0.7f);
        glVertex2f(1.65f, -0.55f);
        glVertex2f(1.65f, -2.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(220, 170, 159);
        glVertex2f(1.65f, -2.0f);
        glVertex2f(1.65f, -0.7f);
        glVertex2f(1.85f, -0.55f);
        glVertex2f(1.85f, -2.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(220, 170, 159);
        glVertex2f(1.85f, -2.0f);
        glVertex2f(1.85f, -0.7f);
        glVertex2f(2.05f, -0.55f);
        glVertex2f(2.05f, -2.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(192, 117, 124);
        glVertex2f(1.45f, -0.7f);
        glVertex2f(1.45f, -0.66f);
        glVertex2f(1.6f, -0.55f);
        glVertex2f(1.65f, -0.55f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(192, 117, 124);
        glVertex2f(1.65f, -0.7f);
        glVertex2f(1.65f, -0.66f);
        glVertex2f(1.8f, -0.55f);
        glVertex2f(1.85f, -0.55f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(192, 117, 124);
        glVertex2f(1.85f, -0.7f);
        glVertex2f(1.85f, -0.66f);
        glVertex2f(2.0f, -0.55f);
        glVertex2f(2.05f, -0.55f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(96, 82, 118);
        glVertex2f(1.5f, -0.78f);
        glVertex2f(1.5f, -0.7f);
        glVertex2f(1.6f, -0.7f);
        glVertex2f(1.6f, -0.78f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(96, 82, 118);
        glVertex2f(1.7f, -0.78f);
        glVertex2f(1.7f, -0.7f);
        glVertex2f(1.8f, -0.7f);
        glVertex2f(1.8f, -0.78f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(96, 82, 118);
        glVertex2f(1.9f, -0.78f);
        glVertex2f(1.9f, -0.7f);
        glVertex2f(1.99f, -0.7f);
        glVertex2f(1.99f, -0.78f);
    glEnd();
}

void fence() {
    glBegin(GL_LINES);
        glColor3ub(204, 0, 0);

        glVertex2f(-2.0f, 0.6f); glVertex2f(0.39f, 0.6f);
        glVertex2f(-2.0f, 0.53f); glVertex2f(0.39f, 0.53f);

        glVertex2f(-1.98f, 0.5f); glVertex2f(-1.98f, 0.63f);
        glVertex2f(-1.5f, 0.5f);  glVertex2f(-1.5f, 0.63f);
        glVertex2f(-1.45f, 0.5f); glVertex2f(-1.45f, 0.63f);
        glVertex2f(-0.4f, 0.5f);  glVertex2f(-0.4f, 0.63f);
        glVertex2f(-0.85f, 0.5f); glVertex2f(-0.85f, 0.63f);
        glVertex2f(-0.8f, 0.5f);  glVertex2f(-0.8f, 0.63f);
        glVertex2f(-0.17f, 0.5f); glVertex2f(-0.17f, 0.63f);
        glVertex2f(0.37f, 0.5f);  glVertex2f(0.37f, 0.63f);

        glVertex2f(2.0f, 0.6f);   glVertex2f(1.42f, 0.6f);
        glVertex2f(2.0f, 0.53f);  glVertex2f(1.42f, 0.53f);

        for (float xx = 1.45f; xx <= 1.95f; xx += 0.05f) {
            glVertex2f(xx, 0.5f);
            glVertex2f(xx, 0.63f);
        }
    glEnd();
}

void road_footpath() {
    glBegin(GL_POLYGON);
        glColor3ub(95, 96, 91);
        glVertex2f(-2.0f, 0.5f);
        glVertex2f(2.0f, 0.5f);
        glVertex2f(2.0f, -0.5f);
        glVertex2f(-2.0f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(95, 96, 91);
        glVertex2f(0.4f, 1.0f);
        glVertex2f(1.4f, 1.0f);
        glVertex2f(1.4f, -1.0f);
        glVertex2f(0.4f, -1.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(176, 191, 189);
        glVertex2f(-2.0f, 0.5f);
        glVertex2f(-2.0f, 0.3f);
        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.6f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(176, 191, 189);
        glVertex2f(-2.0f, -0.5f);
        glVertex2f(-2.0f, -0.3f);
        glVertex2f(0.6f, -0.3f);
        glVertex2f(0.6f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(176, 191, 189);
        glVertex2f(2.0f, -0.5f);
        glVertex2f(2.0f, -0.3f);
        glVertex2f(1.2f, -0.3f);
        glVertex2f(1.2f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(176, 191, 189);
        glVertex2f(2.0f, 0.5f);
        glVertex2f(2.0f, 0.3f);
        glVertex2f(1.2f, 0.3f);
        glVertex2f(1.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(176, 191, 189);
        glVertex2f(0.4f, -1.0f);
        glVertex2f(0.6f, -1.0f);
        glVertex2f(0.6f, -0.3f);
        glVertex2f(0.4f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(176, 191, 189);
        glVertex2f(1.2f, -1.0f);
        glVertex2f(1.4f, -1.0f);
        glVertex2f(1.4f, -0.3f);
        glVertex2f(1.2f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(176, 191, 189);
        glVertex2f(1.2f, 1.0f);
        glVertex2f(1.4f, 1.0f);
        glVertex2f(1.4f, 0.3f);
        glVertex2f(1.2f, 0.3f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(176, 191, 189);
        glVertex2f(0.4f, 1.0f);
        glVertex2f(0.6f, 1.0f);
        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.4f, 0.3f);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(-2.0f, 0.0f); glVertex2f(-1.8f, 0.0f);
        glVertex2f(-1.7f, 0.0f); glVertex2f(-1.5f, 0.0f);
        glVertex2f(-1.4f, 0.0f); glVertex2f(-1.2f, 0.0f);
        glVertex2f(-1.1f, 0.0f); glVertex2f(-0.9f, 0.0f);
        glVertex2f(-0.8f, 0.0f); glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.5f, 0.0f); glVertex2f(-0.3f, 0.0f);
        glVertex2f(-0.2f, 0.0f); glVertex2f(0.0f, 0.0f);

        glVertex2f(1.7f, 0.0f); glVertex2f(1.9f, 0.0f);
        glVertex2f(0.9f, 0.8f); glVertex2f(0.9f, 0.97f);
        glVertex2f(0.9f, -0.97f); glVertex2f(0.9f, -0.8f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.2f, 0.3f); glVertex2f(0.2f, -0.3f);
        glVertex2f(0.4f, -0.3f); glVertex2f(0.4f, 0.3f);
        glVertex2f(0.6f, 0.5f); glVertex2f(1.2f, 0.5f);
        glVertex2f(0.6f, 0.7f); glVertex2f(1.2f, 0.7f);
        glVertex2f(1.4f, 0.3f); glVertex2f(1.4f, -0.3f);
        glVertex2f(1.6f, 0.3f); glVertex2f(1.6f, -0.3f);
        glVertex2f(0.6f, -0.5f); glVertex2f(1.2f, -0.5f);
        glVertex2f(0.6f, -0.7f); glVertex2f(1.2f, -0.7f);
    glEnd();
}

void traffic_light1() {
    glBegin(GL_POLYGON);
        glColor3ub(128, 0, 0);
        glVertex2f(0.45f, 0.38f);
        glVertex2f(0.45f, 0.42f);
        glVertex2f(0.55f, 0.42f);
        glVertex2f(0.55f, 0.38f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 0, 0);
        glVertex2f(0.55f, 0.4f);
        glVertex2f(0.7f, 0.4f);
        glVertex2f(0.7f, 0.4f);
        glVertex2f(0.7f, 0.15f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(204, 122, 0);
        glVertex2f(0.65f, 0.15f);
        glVertex2f(0.75f, 0.15f);
        glVertex2f(0.75f, -0.05f);
        glVertex2f(0.65f, -0.05f);
    glEnd();

    glColor3ub(204, 0, 0);   drawCircle(0.7f, 0.1f, 0.02f);
    glColor3ub(255, 204, 0); drawCircle(0.7f, 0.05f, 0.02f);
    glColor3ub(0, 128, 0);   drawCircle(0.7f, 0.0f, 0.02f);
}

void traffic_light2() {
    glBegin(GL_POLYGON);
        glColor3ub(128, 0, 0);
        glVertex2f(1.28f, -0.35f);
        glVertex2f(1.32f, -0.35f);
        glVertex2f(1.32f, -0.45f);
        glVertex2f(1.28f, -0.45f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 0, 0);
        glVertex2f(1.3f, -0.35f);
        glVertex2f(1.3f, -0.2f);
        glVertex2f(1.3f, -0.2f);
        glVertex2f(1.0f, -0.2f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(204, 122, 0);
        glVertex2f(0.9f, -0.1f);
        glVertex2f(1.0f, -0.1f);
        glVertex2f(1.0f, -0.3f);
        glVertex2f(0.9f, -0.3f);
    glEnd();

    glColor3ub(204, 0, 0);   drawCircle(0.95f, -0.15f, 0.02f);
    glColor3ub(255, 204, 0); drawCircle(0.95f, -0.2f, 0.02f);
    glColor3ub(0, 128, 0);   drawCircle(0.95f, -0.25f, 0.02f);
}

void car1() {
    glPushMatrix();
    glTranslatef(position_c1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glColor3ub(230, 0, 0);
        glVertex2f(-0.2f, 0.25f);
        glVertex2f(0.07f, 0.25f);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(-0.2f, 0.05f);
        glVertex2f(-0.22f, 0.07f);
        glVertex2f(-0.22f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.18f, 0.06f);
        glVertex2f(-0.18f, 0.24f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(230, 0, 0);
        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(-0.15f, 0.21f);
        glVertex2f(-0.15f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.2f);
        glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.1f);
        glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0) {
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.2f);
            glVertex2f(0.14f, 0.23f);
            glVertex2f(0.45f, 0.3f);
            glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.1f);
            glVertex2f(0.14f, 0.07f);
            glVertex2f(0.45f, 0.0f);
            glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
        glColor3ub(230, 0, 0);
        glVertex2f(0.07f, 0.24f); glVertex2f(0.03f, 0.21f);
        glVertex2f(0.03f, 0.09f); glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.18f, 0.06f); glVertex2f(-0.15f, 0.09f);
        glVertex2f(-0.15f, 0.21f); glVertex2f(-0.18f, 0.24f);
        glVertex2f(-0.06f, 0.24f); glVertex2f(-0.06f, 0.21f);
        glVertex2f(-0.06f, 0.09f); glVertex2f(-0.06f, 0.06f);
    glEnd();

    glPopMatrix();
}

void car2() {
    glPushMatrix();
    glTranslatef(position_c2, 0.0f, 0.0f);
    glScalef(-1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
        glColor3ub(255, 204, 0);
        glVertex2f(-0.04f, 0.25f);
        glVertex2f(0.07f, 0.25f);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(-0.04f, 0.05f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.03f, 0.06f);
        glVertex2f(-0.03f, 0.24f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 204, 0);
        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(-0.07f, 0.21f);
        glVertex2f(-0.07f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.2f);
        glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.1f);
        glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0) {
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.2f);
            glVertex2f(0.14f, 0.23f);
            glVertex2f(0.45f, 0.3f);
            glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.1f);
            glVertex2f(0.14f, 0.07f);
            glVertex2f(0.45f, 0.0f);
            glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(-0.06f, 0.25f);
        glVertex2f(-0.06f, 0.05f);
        glVertex2f(-0.5f, 0.05f);
        glVertex2f(-0.5f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 204, 0);
        glVertex2f(0.07f, 0.24f); glVertex2f(0.03f, 0.21f);
        glVertex2f(0.03f, 0.09f); glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.03f, 0.24f); glVertex2f(-0.03f, 0.21f);
        glVertex2f(-0.03f, 0.09f); glVertex2f(-0.03f, 0.06f);

        glColor3ub(217, 217, 217);
        glVertex2f(-0.06f, 0.25f); glVertex2f(-0.06f, 0.05f);
        glVertex2f(-0.06f, 0.05f); glVertex2f(-0.5f, 0.05f);
        glVertex2f(-0.5f, 0.05f); glVertex2f(-0.5f, 0.25f);
        glVertex2f(-0.5f, 0.25f); glVertex2f(-0.06f, 0.25f);
    glEnd();

    glPopMatrix();
}

void car3() {
    glPushMatrix();
    glTranslatef(0.9f, position_c3, 0.0f);
    glRotatef(90, 0, 0, 1);

    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.13f, 0.25f);
        glVertex2f(0.07f, 0.25f);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(-0.13f, 0.05f);
        glVertex2f(-0.15f, 0.07f);
        glVertex2f(-0.15f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.13f, 0.06f);
        glVertex2f(-0.13f, 0.24f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(-0.1f, 0.21f);
        glVertex2f(-0.1f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.2f);
        glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.1f);
        glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0) {
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.2f);
            glVertex2f(0.14f, 0.23f);
            glVertex2f(0.45f, 0.3f);
            glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.1f);
            glVertex2f(0.14f, 0.07f);
            glVertex2f(0.45f, 0.0f);
            glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.07f, 0.24f); glVertex2f(0.03f, 0.21f);
        glVertex2f(0.03f, 0.09f); glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.13f, 0.06f); glVertex2f(-0.1f, 0.09f);
        glVertex2f(-0.1f, 0.21f); glVertex2f(-0.13f, 0.24f);
        glVertex2f(-0.03f, 0.24f); glVertex2f(-0.03f, 0.21f);
        glVertex2f(-0.03f, 0.09f); glVertex2f(-0.03f, 0.06f);
    glEnd();

    glPopMatrix();
}

void car4() {
    glPushMatrix();
    glTranslatef(0.9f, position_c4, 0.0f);
    glRotatef(270, 0, 0, 1);

    glBegin(GL_POLYGON);
        glColor3ub(51, 102, 255);
        glVertex2f(-0.13f, 0.25f);
        glVertex2f(0.07f, 0.25f);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(-0.13f, 0.05f);
        glVertex2f(-0.15f, 0.07f);
        glVertex2f(-0.15f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.13f, 0.06f);
        glVertex2f(-0.13f, 0.24f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(51, 102, 255);
        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(-0.1f, 0.21f);
        glVertex2f(-0.1f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.2f);
        glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.1f);
        glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0) {
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.2f);
            glVertex2f(0.14f, 0.23f);
            glVertex2f(0.45f, 0.3f);
            glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.1f);
            glVertex2f(0.14f, 0.07f);
            glVertex2f(0.45f, 0.0f);
            glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
        glColor3ub(51, 102, 255);
        glVertex2f(0.07f, 0.24f); glVertex2f(0.03f, 0.21f);
        glVertex2f(0.03f, 0.09f); glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.13f, 0.06f); glVertex2f(-0.1f, 0.09f);
        glVertex2f(-0.1f, 0.21f); glVertex2f(-0.13f, 0.24f);
        glVertex2f(-0.03f, 0.24f); glVertex2f(-0.03f, 0.21f);
        glVertex2f(-0.03f, 0.09f); glVertex2f(-0.03f, 0.06f);
    glEnd();

    glPopMatrix();
}

void redgreen1() {
    glColor3ub(255, 51, 51);
    drawCircle(0.7f, 0.1f, 0.02f);
    glColor3ub(0, 255, 0);
    drawCircle(0.95f, -0.25f, 0.02f);
}

void redgreen2() {
    glColor3ub(0, 255, 0);
    drawCircle(0.7f, 0.0f, 0.02f);
    glColor3ub(255, 51, 51);
    drawCircle(0.95f, -0.15f, 0.02f);
}

static void drawDrop(float xx, float yy) {
    glBegin(GL_LINES);
        glVertex2f(xx, yy);
        glVertex2f(xx + 0.05f, yy - 0.05f);
    glEnd();
}

void rain() {
    glLineWidth(2.0f);
    glColor3ub(255, 255, 255);
    for (float xx = -2.0f; xx <= 2.0f; xx += 0.2f) {
        for (float yy = -1.0f; yy <= 1.0f; yy += 0.2f) {
            drawDrop(xx + (position_rain2 - 2.0f), yy + position_rain);
        }
    }
}

void day() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON);
        glColor3ub(51, 204, 51);
        glVertex2f(2.0f, 1.0f);
        glVertex2f(2.0f, -1.0f);
        glVertex2f(-2.0f, -1.0f);
        glVertex2f(-2.0f, 1.0f);
    glEnd();

    tree();
    road_footpath();
    car1();
    car2();
    car3();
    car4();
    traffic_light1();
    traffic_light2();
    factory();
    windmill();
    fence();
    shop();
    house();

    if (cnt == 0) redgreen2();
    else redgreen1();

    if (r != 0) rain();

    glutSwapBuffers();
}

void update_car1(int) {
    if (cnt == 0) {
        speed_c1 = 0.01f;
        if (position_c1 > 2.7f) position_c1 = -2.7f;
        position_c1 += speed_c1;
    } else {
        if (position_c1 > 0.0f) { speed_c1 = 0.0f; position_c1 = 0.0f; }
    }
    glutPostRedisplay();
    glutTimerFunc(10, update_car1, 0);
}

void update_car2(int) {
    if (cnt == 0) {
        speed_c2 = 0.01f;
        if (position_c2 < -2.7f) position_c2 = 2.7f;
        position_c2 -= speed_c2;
    } else {
        if (position_c2 < 1.8f) { speed_c2 = 0.0f; position_c2 = 1.8f; }
    }
    glutPostRedisplay();
    glutTimerFunc(10, update_car2, 0);
}

void update_car3(int) {
    if (cnt == 0) {
        if (position_c3 > -0.9f) { speed_c3 = 0.0f; position_c3 = -0.9f; }
    } else {
        speed_c3 = 0.01f;
        if (position_c3 > 1.7f) position_c3 = -1.7f;
        position_c3 += speed_c3;
    }
    glutPostRedisplay();
    glutTimerFunc(10, update_car3, 0);
}

void update_car4(int) {
    if (cnt == 0) {
        if (position_c4 < 0.9f) { speed_c4 = 0.0f; position_c4 = 0.9f; }
    } else {
        speed_c4 = 0.01f;
        if (position_c4 < -1.7f) position_c4 = 1.7f;
        position_c4 -= speed_c4;
    }
    glutPostRedisplay();
    glutTimerFunc(10, update_car4, 0);
}

void update_rain(int) {
    if (position_rain < -0.1f) position_rain = 0.3f;
    position_rain -= speed_rain;

    if (position_rain2 > 2.0f) position_rain2 = 1.8f;
    position_rain2 += speed_rain2;

    glutPostRedisplay();
    glutTimerFunc(100, update_rain, 0);
}

void update_windmill(int) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30, update_windmill, 0);
}

void button(unsigned char key, int, int) {
    switch (key) {
        case 'r': cnt = 1; break;
        case 'g': cnt = 0; break;
        case 'h': flag = !flag; break;
    }
}

void rain_button(int button, int state, int, int) {
    if (state != GLUT_DOWN) return;

    if (button == GLUT_LEFT_BUTTON) {
        r = 1;
        PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    }
    if (button == GLUT_RIGHT_BUTTON) {
        r = 0;
        PlaySound(NULL, NULL, SND_ASYNC);
    }
}

void inigl() {
    glClearColor(1, 1, 1, 1);
    setOrtho();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1430, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("test");

    glutDisplayFunc(day);
    inigl();

    glutTimerFunc(30, update_windmill, 0);
    glutTimerFunc(10, update_car1, 0);
    glutTimerFunc(10, update_car2, 0);
    glutTimerFunc(10, update_car3, 0);
    glutTimerFunc(10, update_car4, 0);
    glutTimerFunc(100, update_rain, 0);

    glutKeyboardFunc(button);
    glutMouseFunc(rain_button);

    glutMainLoop();
    return 0;
}
