#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include<stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#pragma warning (disable: 4996)
#define pi 3.141592

double posBounceCir[2] = { -0.8, 0 };
double posBounceCir_2[2] = { 0.8, 0 };
double posBounceCir_3[2] = { 0, 0.8 };
double posBounceCir_4[2] = { 0, -0.8 };
GLfloat colBounceCir[3] = { 1.0, 0.0, 0.0 };
double velBounceCir[2] = { 0.04, 0.04 };
double velBounceCir_2[2] = { 0.03, 0.03 };
double velBounceCir_3[2] = { 0.02, 0.02 };
double velBounceCir_4[2] = { 0.01, 0.01 };
double posSquare[2] = { 0.6, 0.02 };
double left = 0;
double right = 0;
GLfloat colSquare[3] = { 1.0, 1.0, 1.0 };
double velSquare[2] = { 0.01, 0.01 };
GLfloat colb[3] = { 1.0, 1.0, 1.0 };
GLfloat colCir[3] = { 1.0, 0, 0 };
int score = 100;
int flag_gameover = 0;
double key_n = 0;
double key_left = 0;
double key_b = 0;
double key_right = 0;

double m = 0;
double j = 0;
double JudgmentA = 0;
double JudgmentA_2 = 0;
double JudgmentA_3 = 0;
double JudgmentA_4 = 0;
double l= 0;
double JudgmentB = 0;
double JudgmentB_2 = 0;
double JudgmentB_3 = 0;
double JudgmentB_4 = 0;
double n = 0;
double angle = 0;
int start = 0;
int second = 10;

void keyboard(unsigned char key, int x, int y){
    left = -0.3 + (30 * (key_b - key_n))/100;
    right = 0.3 + (30 * (key_b - key_n))/100;
    if (left == 1.0) {
        if (key == 'b') {
            key_n = key_n + 0.29;
        }
    }
    else if (right == 1.0) {
        if (key == 'n'){
            key_b = key_b + 0.29;
        }
    }
    else {
        if (key == 'b'){
            key_n = key_n + 0.29;
        }
        if (key == 'n'){
            key_b = key_b + 0.29;
        }
    }
    glutPostRedisplay();
}

void drawBounceCircle(double position[2], double radius, int startAngle, int endAngle) {
    int i;
    glBegin(GL_POLYGON);
    for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
        glVertex3f(
            position[0] + radius * cos(3.14 * i / 180),
            position[1] + radius * sin(3.14 * i / 180), 0.0);
    }
    glEnd();
}

void drawSquare() {
    glBegin(GL_LINE_LOOP);
    left = -0.2 + 0.2 * (key_b - key_n);
    right = 0.2 + 0.2 * (key_b - key_n);
    glVertex2d(left, -0.95);
    glVertex2d(left, -0.90);
    glVertex2d(right, -0.90);
    glVertex2d(right, -0.95);
    glEnd();
}

void update(int value) {

    srand((unsigned int)time(NULL));

    if (score <= 0){
        ;
    }
    else {
        if (JudgmentA == 0){
            posBounceCir[1] += velBounceCir[1] * (rand() % 10)/8;
            if (posBounceCir[1] >= 1.0){
                velBounceCir[1] *= -1;
                JudgmentA = 1;
                score++;
            }
        }
        if (JudgmentA == 1){
            posBounceCir[1] += velBounceCir[1] * (rand() % 10)/8;
            if (posBounceCir[1] <= -0.88 && (fabs(right) - fabs(posBounceCir[0])) <= 0.25 && (fabs(posBounceCir[0]) - fabs(left) <= 0.25)){
                velBounceCir[1] *= -1;
                JudgmentA = 0;
            }
            if (posBounceCir[1] <= -1.1){
                score -= 100;
                flag_gameover = 1;
            }
        }
        if (JudgmentB == 0){
            posBounceCir[0] += velBounceCir[0] * (rand() % 10)/8;
            if (posBounceCir[0] >= 1.0){
                velBounceCir[0] *= -1;
                JudgmentB = 1;
            }
        }
        if (JudgmentB == 1){
            posBounceCir[0] += velBounceCir[0] * (rand() % 10)/8;
            if (posBounceCir[0] <= -0.95){
                velBounceCir[0] *= -1;
                JudgmentB = 0;
            }
        }
    }

    if (score <= 0){
        ;
    }
    else {
        if (JudgmentA_2 == 0){
            posBounceCir_2[1] += velBounceCir_2[1] * (rand() % 10)/7;
            if (posBounceCir_2[1] >= 1.0){
                velBounceCir_2[1] *= -1;
                JudgmentA_2 = 1;
                score++;
            }
        }
        if (JudgmentA_2 == 1){
            posBounceCir_2[1] += velBounceCir_2[1] * (rand() % 10)/7;
            if (posBounceCir_2[1] <= -0.88 && (fabs(right) - fabs(posBounceCir_2[0])) <= 0.25 && (fabs(posBounceCir_2[0]) - fabs(left) <= 0.25)){
                velBounceCir_2[1] *= -1;
                JudgmentA_2 = 0;
            }
            if (posBounceCir_2[1] <= -1.1){
                score -= 100;
                flag_gameover = 1;
            }
        }
        if (JudgmentB_2 == 0){
            posBounceCir_2[0] += velBounceCir_2[0] * (rand() % 10)/7;
            if (posBounceCir_2[0] >= 1.0){
                velBounceCir_2[0] *= -1;
                JudgmentB_2 = 1;
            }
        }
        if (JudgmentB_2 == 1){
            posBounceCir_2[0] += velBounceCir_2[0] * (rand() % 10)/7;
            if (posBounceCir_2[0] <= -0.95){
                velBounceCir_2[0] *= -1;
                JudgmentB_2 = 0;
            }
        }
    }

    if (score <= 0){
        ;
    }
    else {
        if (JudgmentA_3 == 0){
            posBounceCir_3[1] += velBounceCir_3[1] * (rand() % 10)/6;
            if (posBounceCir_3[1] >= 1.0){
                velBounceCir_3[1] *= -1;
                JudgmentA_3 = 1;
                score++;
            }
        }
        if (JudgmentA_3 == 1){
            posBounceCir_3[1] += velBounceCir_3[1] * (rand() % 10)/6;
            if (posBounceCir_3[1] <= -0.88 && (fabs(right) - fabs(posBounceCir_3[0])) <= 0.25 && (fabs(posBounceCir_3[0]) - fabs(left) <= 0.25)){
                velBounceCir_3[1] *= -1;
                JudgmentA_3 = 0;
            }
            if (posBounceCir_3[1] <= -1.1){
                score -= 100;
                flag_gameover = 1;
            }
        }
        if (JudgmentB_3 == 0){
            posBounceCir_3[0] += velBounceCir_3[0] * (rand() % 10)/6;
            if (posBounceCir_3[0] >= 1.0){
                velBounceCir_3[0] *= -1;
                JudgmentB_3 = 1;
            }
        }
        if (JudgmentB_3 == 1){
            posBounceCir_3[0] += velBounceCir_3[0] * (rand() % 10)/6;
            if (posBounceCir_3[0] <= -0.95){
                velBounceCir_3[0] *= -1;
                JudgmentB_3 = 0;
            }
        }
    }

    if (score <= 0){
        ;
    }
    else {
        if (JudgmentA_4 == 0){
            posBounceCir_4[1] += velBounceCir_4[1] * (rand() % 10)/5;
            if (posBounceCir_4[1] >= 1.0){
                velBounceCir_4[1] *= -1;
                JudgmentA_4 = 1;
                score++;
            }
        }
        if (JudgmentA_4 == 1){
            posBounceCir_4[1] += velBounceCir_4[1] * (rand() % 10)/5;
            if (posBounceCir_4[1] <= -0.88 && (fabs(right) - fabs(posBounceCir_4[0])) <= 0.25 && (fabs(posBounceCir_4[0]) - fabs(left) <= 0.25)){
                velBounceCir_4[1] *= -1;
                JudgmentA_4 = 0;
            }
            if (posBounceCir_4[1] <= -1.1){
                score -= 100;
                flag_gameover = 1;
            }
        }
        if (JudgmentB_4 == 0){
            posBounceCir_4[0] += velBounceCir_4[0] * (rand() % 10)/5;
            if (posBounceCir_4[0] >= 1.0){
                velBounceCir_4[0] *= -1;
                JudgmentB_4 = 1;
            }
        }
        if (JudgmentB_4 == 1){
            posBounceCir_4[0] += velBounceCir_4[0] * (rand() % 10)/5;
            if (posBounceCir_4[0] <= -0.95){
                velBounceCir_4[0] *= -1;
                JudgmentB_4 = 0;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);

    if (score < 0){
        flag_gameover = 1;
        score = 0;
    }
    if (start == 0){
        sleep(second);
        start = 1;
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    char str[20];
    char strgameover[20];
    char startstr[50];
    unsigned int i;
    unsigned int m;
    if (start == 0){
        sprintf(startstr, "Pleace wait 10 second.");
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2i(-0.9, 0);
        for (i = 0; i < strlen(startstr); i++){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, startstr[i]);
        }
        glutSwapBuffers();
    }
    else if (start == 1) {
        if (flag_gameover == 0){
            sprintf(str, "Score: %07d", score);
            glColor3f(1.0, 1.0, 1.0);
            glRasterPos2i(-0.5, 0);
            for (i = 0; i < strlen(str); i++){
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
            }
        }
        else if (flag_gameover == 1){
            sprintf(strgameover, "Game Over.");
            glColor3f(1.0, 1.0, 1.0);
            glRasterPos2i(-0.5, 0);
            for (m = 0; m < strlen(strgameover); m++){
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strgameover[m]);
            }
        }
        glColor3d(colSquare[0], colSquare[1], colSquare[2]); //????????????????????????
        drawSquare(); //??????????????????
        glColor3d(colCir[0], colCir[1], colCir[2]); //??????????????????
        drawBounceCircle(posBounceCir, 0.03, 0, 360); //????????????
        glColor3d(colCir[0], colCir[1], colCir[2]); //??????????????????
        drawBounceCircle(posBounceCir_2, 0.03, 0, 360); //????????????
        glColor3d(colCir[0], colCir[1], colCir[2]); //??????????????????
        drawBounceCircle(posBounceCir_3, 0.03, 0, 360); //????????????
        glColor3d(colCir[0], colCir[1], colCir[2]); //??????????????????
        drawBounceCircle(posBounceCir_4, 0.03, 0, 360); //????????????
        glutSwapBuffers();
    }
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv); //GLUT???????????????????????????
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]); //????????????????????????
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display); //????????????????????????????????????????????????
    init();
    glutTimerFunc(1000, update, 0);
    glutMainLoop(); //??????????????????
    return EXIT_SUCCESS;
}
