#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <string.h>
#pragma warning (disable: 4996)
#define pi 3.141592

double posDot[2] = { 0.9, 0 };
GLfloat colDot[3] = { 1.0, 1.0, 1.0 };
double velDot[2] = { -0.05, 0.05 };
double posCir[2] = { -0.8, 0 };
GLfloat colCir[3] = { 1.0, 0.0, 0.0 };
double velCir[2] = { 0.04, 0.04 };
double Bar_Left = 0;
double Bar_Right = 0;
double posSquare[2] = { 0.6, 0.02 };
GLfloat colSquare[3] = { 1.0, 1.0, 1.0 };
double velSquare[2] = { 0.01, 0.01 };
GLfloat colb[3] = { 1.0, 1.0, 1.0 };
int score = 100;
int flag_gameover = 0;
double Z_Buttons = 0;
double X_Buttons = 0;
double Upwards = 0;
double Arounds = 1;
int Start = 0;
int Last = 0;

int m = 0;

struct Square {
    double Left;
    double Right;
    double Low;
    double Hight;
    int CollisionDetection;
};

struct Square squere[10] = {
    { -1.0, -0.8, 0.8, 1.0, 0 },
    { -0.8, -0.6, 0.8, 1.0, 0 },
    { -0.6, -0.4, 0.8, 1.0, 0 },
    { -0.4, -0.2, 0.8, 1.0, 0 },
    { -0.2, 0.0, 0.8, 1.0, 0 },
    { 0.0, 0.2, 0.8, 1.0, 0 },
    { 0.2, 0.4, 0.8, 1.0, 0 },
    { 0.4, 0.6, 0.8, 1.0, 0 },
    { 0.6, 0.8, 0.8, 1.0, 0 },
    { 0.8, 1.0, 0.8, 1.0, 0 },
};

void Key(unsigned char key, int x, int y){
    if (Bar_Left == 1.0) {
        if (key == 'z') {
            Z_Buttons = Z_Buttons + 0.2;
        }
    }
    else if (Bar_Right == 1.0) {
        if (key == 'x'){
            X_Buttons = X_Buttons + 0.2;
        }
    }
    else {
        if (key == 'z'){
            Z_Buttons = Z_Buttons + 0.2;
        }
        if (key == 'x'){
            X_Buttons = X_Buttons + 0.2;
        }
    }
    glutPostRedisplay();
}

void Point(double position[2]) {
    glPointSize(15);
    glBegin(GL_POINTS);
    glVertex2d(position[0], position[1]);
    glEnd();
}

void Bar() {
    glBegin(GL_LINE_LOOP);
    Bar_Left = -0.2 + 0.2 * ( X_Buttons - Z_Buttons );
    Bar_Right = 0.2 + 0.2 * ( X_Buttons - Z_Buttons );
    glVertex2d(Bar_Left, -0.95);
    glVertex2d(Bar_Left, -0.90);
    glVertex2d(Bar_Right, -0.90);
    glVertex2d(Bar_Right, -0.95);
    glEnd();
}

void Squares(double Left, double Right, double Low, double Hight, int ColleisionDetection){
    if (ColleisionDetection == 0){
        glBegin(GL_LINE_LOOP);
        glVertex2d(Left, Hight);
        glVertex2d(Left, Low);
        glVertex2d(Right, Low);
        glVertex2d(Right, Hight);
        glEnd();
    }
    else{
        ;
    }
}

void Circle(double position[2], double radius, int startAngle, int endAngle) {
    int i;
    glBegin(GL_POLYGON);
    for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
        glVertex3f(
            position[0] + radius * cos(3.14 * i / 180),
            position[1] + radius * sin(3.14 * i / 180), 0.0);
    }
    glEnd();
}
    
void Update(int value) {
    unsigned int i = 0;
    unsigned int j = 5;
    if (score <= 0){
        ;
    }
    else {
        if (Upwards == 0){
            posDot[1] += velDot[1];
            if (m == 0){
                for (i = 0; i < 5; i++){
                    if(posDot[1] >= 0.8 && ((squere[i].Left - posDot[0]) >= -0.002 || squere[i].Right - posDot[0] >= -0.002) && (squere[i].Low - posDot[1]) <= 0.002){
                        velDot[1] *= -1;
                        squere[i].CollisionDetection = 1;
                        score++;
                        m = 1;
                    }
                }
                for (j = 5; j < 10; j++){
                    if(posDot[1] >= 0.8 && ((fabs(squere[j].Left - posDot[0])) <= 0.002 || fabs(squere[j].Right - posDot[0]) <= 0.002) && (squere[j].Low - posDot[1]) <= 0.002){
                        velDot[1] *= -1;
                        squere[j].CollisionDetection = 1;
                        score++;
                        m = 1;
                    }
                }
            }
            else if (posDot[1] >= 1.0){
                velDot[1] *= -1;
                Upwards = 1;
            }
            else{
                velDot[1] *= -1;
                Upwards = 1;
            }
        }
        if (Upwards == 1){
            posDot[1] += velDot[1];
            if (posDot[1] <= -0.88 && (fabs(Bar_Right) - fabs(posDot[0])) <= 0.25 && (fabs(posDot[0]) - fabs(Bar_Left) <= 0.25)){
                velDot[1] *= -1;
                Upwards = 0;
                m = 0;
            }
            else if (posDot[1] <= -1.0){
                score -= 1000;
                flag_gameover = 1;
            }
        }
        if (Arounds == 0){
            posDot[0] += velDot[0];
            if (posDot[0] >= 1.0){
                velDot[0] *= -1;
                Arounds = 1;
            }
        }
        if (Arounds == 1){
            posDot[0] += velDot[0];
            if (posDot[0] <= -1.0){
                velDot[0] *= -1;
                Arounds = 0;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(80, Update, 0);
    if (score < 0){
        flag_gameover = 1;
        score = 0;
    }
    if (Start == 0){
        Start = 1;
    }
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    char str[20];
    char strgameover[20];
    char startstr[50];
    unsigned int i;
    unsigned int m;
    unsigned int n;
    if (Start == 0){
        sprintf(startstr, "Pleace wait 10 second.");
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2i(-0.9, 0);
        for (i = 0; i < strlen(startstr); i++){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, startstr[i]);
        }
        glutSwapBuffers();
    }
    else if (Start == 1) {
        if (flag_gameover == 0){
            sprintf(str, "Score: %07d", score);
            glColor3f(1.0, 1.0, 1.0);
            glRasterPos2i(-0.5, 0.2);
            for (i = 0; i < strlen(str); i++){
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
            }
        }
        else if (flag_gameover == 1){
            sprintf(strgameover, "Game Over.");
            glColor3f(1.0, 1.0, 1.0);
            glRasterPos2i(-0.5, 0.2);
            for (m = 0; m < strlen(strgameover); m++){
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strgameover[m]);
            }
        }
        glColor3d(colSquare[0], colSquare[1], colSquare[2]);
        Bar();
        glColor3d(colDot[0], colDot[1], colDot[2]);
        Point(posDot);
        for (n = 0; n < 10; n++){
            if (squere[n].CollisionDetection == 0){
                glColor3d(colSquare[0], colSquare[1], colSquare[2]);
                Squares(squere[n].Left, squere[n].Right, squere[n].Low, squere[n].Hight, squere[n].CollisionDetection);
            }
        }
        glutSwapBuffers();
    }
}

void Init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    glutKeyboardFunc(Key);
    glutDisplayFunc(Display);
    Init();
    glutTimerFunc(1000, Update, 0);
    glutMainLoop();
    return EXIT_SUCCESS;
}
