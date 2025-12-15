#include <GL/glut.h>
#include <cmath>
#include <algorithm>

// ----------------- Screen (virtual pixel grid) -----------------
static const int W = 800;
static const int H = 600;

static inline float ndcX(int px){ return -1.0f + 2.0f * px / (float)(W-1); }
static inline float ndcY(int py){ return -1.0f + 2.0f * py / (float)(H-1); }

static inline int toPixX(float x){ return (int)std::lround((x+1.0f)*0.5f*(W-1)); }
static inline int toPixY(float y){ return (int)std::lround((y+1.0f)*0.5f*(H-1)); }

static inline bool inBounds(int x,int y){ return x>=0 && x<W && y>=0 && y<H; }

static inline float clampf(float v, float lo, float hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static inline void plot(int x,int y)
{
    if(!inBounds(x,y)) return;
    glVertex2f(ndcX(x), ndcY(y));
}

// ----------------- DDA line -----------------
void drawLineDDA(int x0,int y0,int x1,int y1)
{
    int dx=x1-x0, dy=y1-y0;
    int steps = std::max(std::abs(dx), std::abs(dy));
    if(steps==0){ plot(x0,y0); return; }

    float x=x0, y=y0;
    float xInc = dx/(float)steps;
    float yInc = dy/(float)steps;

    for(int i=0; i<=steps; i++)
    {
        plot((int)std::lround(x),(int)std::lround(y));
        x+=xInc; y+=yInc;
    }
}
void drawHLineDDA(int x0,int x1,int y)
{
    if(x0>x1) std::swap(x0,x1);
    drawLineDDA(x0,y,x1,y);
}

// ----------------- Bresenham circle (with fill spans) -----------------
void circleFillSpans(int cx,int cy,int x,int y)
{
    drawHLineDDA(cx-x,cx+x,cy+y);
    drawHLineDDA(cx-x,cx+x,cy-y);
    drawHLineDDA(cx-y,cx+y,cy+x);
    drawHLineDDA(cx-y,cx+y,cy-x);
}
void circlePlot8(int cx,int cy,int x,int y)
{
    plot(cx+x,cy+y); plot(cx-x,cy+y); plot(cx+x,cy-y); plot(cx-x,cy-y);
    plot(cx+y,cy+x); plot(cx-y,cy+x); plot(cx+y,cy-x); plot(cx-y,cy-x);
}
void drawCircleBresenham(int cx,int cy,int r,bool filled)
{
    int x=0,y=r,d=1-r;

    if(filled) circleFillSpans(cx,cy,x,y);
    else       circlePlot8(cx,cy,x,y);

    while(x<y)
    {
        x++;
        if(d<0) d += 2*x+1;
        else { y--; d += 2*(x-y)+1; }

        if(filled) circleFillSpans(cx,cy,x,y);
        else       circlePlot8(cx,cy,x,y);
    }
}

// ----------------- Simple fill rect & triangle using DDA spans -----------------
void fillRectDDA(int x0,int y0,int x1,int y1)
{
    if(x0>x1) std::swap(x0,x1);
    if(y0>y1) std::swap(y0,y1);
    for(int y=y0; y<=y1; y++) drawHLineDDA(x0,x1,y);
}
static inline void sortByY(int &x0,int &y0,int &x1,int &y1,int &x2,int &y2)
{
    if(y0>y1){ std::swap(y0,y1); std::swap(x0,x1); }
    if(y1>y2){ std::swap(y1,y2); std::swap(x1,x2); }
    if(y0>y1){ std::swap(y0,y1); std::swap(x0,x1); }
}
void fillTriangleDDA(int x0,int y0,int x1,int y1,int x2,int y2)
{
    sortByY(x0,y0,x1,y1,x2,y2);
    if(y0==y2) return;

    auto interpX = [](int xa,int ya,int xb,int yb,int y)->float
    {
        if(yb==ya) return (float)xa;
        return xa + (xb-xa)*(float)(y-ya)/(float)(yb-ya);
    };

    for(int y=y0; y<=y1; y++)
    {
        int A=(int)std::lround(interpX(x0,y0,x2,y2,y));
        int B=(int)std::lround(interpX(x0,y0,x1,y1,y));
        drawHLineDDA(A,B,y);
    }
    for(int y=y1; y<=y2; y++)
    {
        int A=(int)std::lround(interpX(x0,y0,x2,y2,y));
        int B=(int)std::lround(interpX(x1,y1,x2,y2,y));
        drawHLineDDA(A,B,y);
    }
}

// ----------------- Scene basic parts -----------------
void drawSkyGradient()
{
    int yTop=toPixY(1.0f), yBot=toPixY(0.0f);
    for(int y=yBot; y<=yTop; y++)
    {
        float t=(yTop==yBot)?0.0f:(float)(y-yBot)/(float)(yTop-yBot);
        float r = 0.7f + (0.5f-0.7f)*t;
        float g = 0.9f + (0.8f-0.9f)*t;

        glColor3f(r,g,1.0f);
        glBegin(GL_POINTS);
            drawHLineDDA(0,W-1,y);
        glEnd();
    }
}
void drawGround()
{
    glColor3f(0.2f,0.6f,0.2f);
    glBegin(GL_POINTS);
        fillRectDDA(toPixX(-1),toPixY(-1),toPixX(1),toPixY(0));
    glEnd();
}
void drawRoad()
{
    glColor3f(0.6f,0.5f,0.4f);
    glBegin(GL_POINTS);
        fillRectDDA(toPixX(-1),toPixY(-1),toPixX(1),toPixY(-0.7f));
    glEnd();
}

// ----------------- Clouds (filled circles) -----------------
void drawCloud(float x, float y, float s)
{
    glColor3f(0.95f, 0.95f, 1.0f);

    auto one = [&](float cx, float cy, float rr)
    {
        int pcx = toPixX(cx);
        int pcy = toPixY(cy);
        int pr  = (int)std::lround(rr * 0.5f * (W - 1));
        drawCircleBresenham(pcx, pcy, pr, true);
    };

    glBegin(GL_POINTS);
        one(x,                 y,              0.07f * s);
        one(x - 0.06f * s,     y - 0.01f * s,   0.06f * s);
        one(x + 0.06f * s,     y - 0.01f * s,   0.06f * s);
        one(x,                 y + 0.03f * s,   0.05f * s);
    glEnd();
}

// ----------------- Fence (simple posts + rails) -----------------
void drawFenceSegment(float x1, float x2, float yBase)
{
    glColor3f(0.8f, 0.7f, 0.5f);

    float rail1 = yBase + 0.03f;
    float rail2 = yBase + 0.08f;

    int X1 = toPixX(x1), X2 = toPixX(x2);

    glBegin(GL_POINTS);
        // rails as thin rectangles
        fillRectDDA(X1, toPixY(rail1 - 0.005f), X2, toPixY(rail1 + 0.005f));
        fillRectDDA(X1, toPixY(rail2 - 0.005f), X2, toPixY(rail2 + 0.005f));

        // posts
        for(float x = x1; x <= x2; x += 0.07f)
        {
            fillRectDDA(toPixX(x - 0.007f), toPixY(yBase),
                        toPixX(x + 0.007f), toPixY(yBase + 0.12f));
        }
    glEnd();
}

// ----------------- Sun (rotate rays + pulse) -----------------
float sunAngle=0.0f, sunPulse=0.0f;

void drawSun(float x,float y,float r)
{
    int cx=toPixX(x), cy=toPixY(y);
    int pr=(int)std::lround(r*0.5f*(W-1));

    float pulse = 0.12f * std::sin(sunPulse);
    float G = clampf(0.9f + pulse, 0.0f, 1.0f);

    glColor3f(1.0f, G, 0.0f);
    glBegin(GL_POINTS);
        drawCircleBresenham(cx,cy,pr,true);
    glEnd();

    glColor3f(1.0f,0.85f,0.05f);
    glBegin(GL_POINTS);
    for(int i=0; i<12; i++)
    {
        float a = sunAngle + i*(2.0f*3.14159265f/12.0f);
        float x1=x + r*std::cos(a),         y1=y + r*std::sin(a);
        float x2=x + (r+0.08f)*std::cos(a), y2=y + (r+0.08f)*std::sin(a);
        drawLineDDA(toPixX(x1),toPixY(y1),toPixX(x2),toPixY(y2));
    }
    glEnd();
}

// ----------------- Car (move + scale) -----------------
float carX=-1.2f, carY=-0.86f, carScale=1.0f, carSpeed=0.004f;

void drawCar(float x,float y,float s,float shade)
{
    // body
    glColor3f(0.2f*shade,0.2f*shade,0.8f*shade);
    glBegin(GL_POINTS);
        fillRectDDA(toPixX(x-0.175f*s),toPixY(y),
                    toPixX(x+0.175f*s),toPixY(y+0.10f*s));
    glEnd();

    // roof triangle
    glColor3f(0.15f*shade,0.15f*shade,0.65f*shade);
    glBegin(GL_POINTS);
        fillTriangleDDA(toPixX(x-0.12f*s),toPixY(y+0.10f*s),
                        toPixX(x+0.05f*s),toPixY(y+0.10f*s),
                        toPixX(x-0.03f*s),toPixY(y+0.18f*s));
    glEnd();

    // wheels
    glColor3f(0.05f*shade,0.05f*shade,0.05f*shade);
    int pr=(int)std::lround((0.04f*s)*0.5f*(W-1));
    glBegin(GL_POINTS);
        drawCircleBresenham(toPixX(x-0.10f*s),toPixY(y-0.005f*s),pr,true);
        drawCircleBresenham(toPixX(x+0.10f*s),toPixY(y-0.005f*s),pr,true);
    glEnd();
}

void drawCarOnly()
{
    drawCar(carX,carY,carScale,1.0f);
}

// ----------------- Flag: left fixed, right shears (waving) -----------------
float flagShear=0.0f;

void drawFlag(float x,float y)
{
    float poleH=0.45f, fw=0.25f, fh=0.15f;

    // pole
    glColor3f(0.6f,0.6f,0.6f);
    glBegin(GL_POINTS);
        fillRectDDA(toPixX(x-0.01f),toPixY(y),
                    toPixX(x+0.01f),toPixY(y+poleH));
    glEnd();

    float top=y+poleH, bot=top-fh;
    int py0=toPixY(bot), py1=toPixY(top);

    // smaller shear
    float sh = 0.03f * std::sin(flagShear);

    // green rectangle: LEFT edge fixed, RIGHT edge moves
    glColor3f(0.0f,0.4f,0.0f);
    glBegin(GL_POINTS);
    for(int py=py0; py<=py1; py++)
    {
        float yn=ndcY(py);
        float t=(top==bot)?0.0f:(yn-bot)/(top-bot);
        t = clampf(t, 0.0f, 1.0f);

        float off = sh * t;

        int xL = toPixX(x + 0.01f);             // fixed to pole
        int xR = toPixX(x + 0.01f + fw + off);  // only right edge waves

        drawHLineDDA(xL, xR, py);
    }
    glEnd();

    // red circle: small right shift (since only right side moves)
    glColor3f(0.8f,0.0f,0.0f);
    float cx = x + 0.01f + fw*0.45f + sh*0.45f;
    float cy = bot + fh*0.5f;
    int rr=(int)std::lround(0.04f*0.5f*(W-1));

    glBegin(GL_POINTS);
        drawCircleBresenham(toPixX(cx),toPixY(cy),rr,true);
    glEnd();
}

// ----------------- Extra objects (simple) -----------------
void drawTree(float x,float y)
{
    glColor3f(0.4f,0.2f,0.0f);
    glBegin(GL_POINTS);
        fillRectDDA(toPixX(x-0.02f),toPixY(y),
                    toPixX(x+0.02f),toPixY(y+0.2f));
    glEnd();

    glColor3f(0.0f,0.5f,0.0f);
    float cy=y+0.27f;
    glBegin(GL_POINTS);
        drawCircleBresenham(toPixX(x),toPixY(cy+0.03f),(int)std::lround(0.10f*0.5f*(W-1)),true);
        drawCircleBresenham(toPixX(x-0.07f),toPixY(cy),(int)std::lround(0.08f*0.5f*(W-1)),true);
        drawCircleBresenham(toPixX(x+0.07f),toPixY(cy),(int)std::lround(0.08f*0.5f*(W-1)),true);
    glEnd();
}
void drawHouse(float x,float y)
{
    glColor3f(0.8f,0.5f,0.3f);
    glBegin(GL_POINTS);
        fillRectDDA(toPixX(x-0.15f),toPixY(y),
                    toPixX(x+0.15f),toPixY(y+0.2f));
    glEnd();

    glColor3f(0.6f,0.1f,0.1f);
    glBegin(GL_POINTS);
        fillTriangleDDA(toPixX(x-0.18f),toPixY(y+0.2f),
                        toPixX(x+0.18f),toPixY(y+0.2f),
                        toPixX(x),toPixY(y+0.34f));
    glEnd();

    glColor3f(0.4f,0.2f,0.0f);
    glBegin(GL_POINTS);
        fillRectDDA(toPixX(x-0.04f),toPixY(y),
                    toPixX(x+0.04f),toPixY(y+0.11f));
    glEnd();

    glColor3f(0.7f,0.9f,1.0f);
    glBegin(GL_POINTS);
        fillRectDDA(toPixX(x+0.06f),toPixY(y+0.08f),
                    toPixX(x+0.12f),toPixY(y+0.14f));
    glEnd();
}

// Birds (simple)
const int NUM_BIRDS=3;
float birdX[NUM_BIRDS]= {-1.2f,-0.8f,-1.5f};
float birdY[NUM_BIRDS]= { 0.75f,0.65f,0.85f};
float birdSpeed[NUM_BIRDS]= {0.003f,0.0045f,0.0025f};

void drawBird(float x,float y)
{
    glColor3f(0.1f,0.1f,0.1f);
    glBegin(GL_POINTS);
        drawLineDDA(toPixX(x-0.03f),toPixY(y),toPixX(x),toPixY(y+0.02f));
        drawLineDDA(toPixX(x),toPixY(y+0.02f),toPixX(x+0.03f),toPixY(y));
    glEnd();
}

// ----------------- Display & Update -----------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSkyGradient();
    drawGround();
    drawRoad();

    // clouds
    drawCloud(-0.60f, 0.75f, 1.0f);
    drawCloud( 0.00f, 0.85f, 0.9f);
    drawCloud( 0.55f, 0.72f, 0.8f);

    // fence (left and right)
    float fenceY = -0.48f;
    drawFenceSegment(-0.95f, -0.40f, fenceY);
    drawFenceSegment(-0.05f,  0.95f, fenceY);

    drawCarOnly();
    drawSun(0.78f,0.80f,0.12f);

    drawTree(-0.85f,-0.35f);
    drawTree(-0.50f,-0.18f);
    drawTree( 0.30f,-0.15f);

    drawHouse(-0.15f,-0.25f);
    drawFlag(0.65f,-0.18f);

    for(int i=0; i<NUM_BIRDS; i++) drawBird(birdX[i],birdY[i]);

    glutSwapBuffers();
}

void update(int)
{
    // birds
    for(int i=0; i<NUM_BIRDS; i++)
    {
        birdX[i]+=birdSpeed[i];
        if(birdX[i]>1.3f) birdX[i]=-1.3f;
    }

    // sun rotation + pulse
    sunAngle += 0.02f;
    if(sunAngle > 2.0f*3.14159265f) sunAngle -= 2.0f*3.14159265f;
    sunPulse += 0.04f;

    // flag wave
    flagShear += 0.06f;

    // car translate + scale
    carX += carSpeed;
    if(carX>1.3f) carX=-1.3f;
    carScale = 0.95f + 0.08f*std::sin(sunPulse*0.6f);

    glutPostRedisplay();
    glutTimerFunc(16,update,0);
}

void init()
{
    glClearColor(0.6f,0.9f,1.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPointSize(1.0f);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(W,H);
    glutCreateWindow("Village Scenario");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,update,0);
    glutMainLoop();
    return 0;
}
