#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h> //OpenGL
#include <GLUT/GLUT.h> //表示等を行う
#include <math.h> //sin(), cos()を使用するためのヘッダファイルの読み込み
#include <string.h> //文字表示用
//敵のポジションを表す変数
double posEnemy[2];
//敵の色を表す関数
GLfloat colEnemy[3];
//敵の状態を表す変数
double statusEnemy = 0.0;
//背景色を表す変数
GLfloat colBack[3];
//箱のサイズ
double box_size;
//敵を叩けているかどうか
int isPunching = 0;
//スコア
int score;
//マウス操作イベント
void mouse(int button, int state, int x, int y){
    double pos[2];
    double distance;
    if (button != GLUT_LEFT_BUTTON){
        return;
    }
    if (state == GLUT_DOWN){
        pos[0] = (double)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        pos[1] = - (double)y / glutGet(GLUT_WINDOW_HEIGHT) * 2 + 1;
    }
    distance = sqrt(pow((pos[0] - posEnemy[0]), 2.0) + pow(pos[1] - (posEnemy[1] + box_size * statusEnemy), 2.0));
    if (distance < 0.5){
        isPunching = 1;
        score++;
        glutPostRedisplay();
    }
}
//円形の描画
void drawCircle_f(double pos_x, double pos_y, GLfloat color[3], double radius, int startAngle, int endAngle){
    int i;
    glBegin(GL_LINE_STRIP); //折れ線の描画開始
    for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
        glColor3d(color[0], color[1], color[2]); //描画色を指定
        glVertex2d(
            pos_x + radius * cos(3.14 * i / 180),
            pos_y + radius * sin(3.14 * i / 180));
    }
    glEnd(); //描画終了
}
//顔の描画
void drawFace(double posGiven[2], GLfloat colorGiven[3], int type) {
    double size = 0.2;
    drawCircle_f(posGiven[0], posGiven[1], colorGiven, size * 1.0, 0, 360); //顔
    drawCircle_f(posGiven[0] - size * 0.4, posGiven[1] + size * 0.3, colorGiven, size * 0.1, 0, 360); //左目
    drawCircle_f(posGiven[0] + size * 0.4, posGiven[1] + size * 0.3, colorGiven, size * 0.1, 0, 360); //右目
    if (type == 0){
        drawCircle_f(posGiven[0], posGiven[1] + size * 0.2, colorGiven, size * 0.8, 225, 315); //口
    }
    else if (type == 1){
        drawCircle_f(posGiven[0], posGiven[1] - size * 1.0, colorGiven, size * 0.8, 45, 135); //口
    }
}
//モグラの描画
void drawMole(double posGiven[2], double status){
    double pos[2];
    pos[0] = posGiven[0];
    pos[1] = posGiven[1] + box_size * status;
    drawFace(pos, colEnemy, 1);
    glColor3d(colBack[0], colBack[1], colBack[2]);
    glBegin(GL_POLYGON);
    glVertex2d(posGiven[0] - box_size / 2, posGiven[1] - box_size / 2);
    glVertex2d(posGiven[0] + box_size / 2, posGiven[1] - box_size / 2);
    glVertex2d(posGiven[0] + box_size / 2, posGiven[1] + box_size / 2);
    glVertex2d(posGiven[0] - box_size / 2, posGiven[1] + box_size / 2);
    glEnd();
}
//画面を描画
void display(void) {
    char str[20];
    int i;
    glClearColor(colBack[0], colBack[1], colBack[2], 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(colEnemy[0], colEnemy[1], colEnemy[2]);
    if (isPunching == 1){
        colBack[0] = 0.2;
        colBack[1] = 0.5;
        colBack[2] = 0.2;
    }
    else {
        colBack[0] = 0.0;
        colBack[1] = 0.0;
        colBack[2] = 0.0;
    }
    sprintf(str, "Score: %0.7d", score);
    glColor3d(-1.0, 1.0, 1.0);
    glRasterPos2i(-1.0, -1.0);
    for (i = 0; i < strlen(str); i++){
        glutBitmapCharacter((GLUT_BITMAP_8_BY_13), str[i]);
    }
    drawMole(posEnemy, statusEnemy);
    glutSwapBuffers();
}
// 再描画関数（一定時間ごと）
void updatePos(int value){
    statusEnemy += 0.05;
    if (statusEnemy > 1 || isPunching == 1){
        isPunching = 0;
        statusEnemy = 0;
        posEnemy[0] = (double)rand() / RAND_MAX * 2.0 - 1.0;
        posEnemy[1] = (double)rand() / RAND_MAX * 1.8 - 1.4;
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatePos, 0);
}
//初期化
void init(void){
    time_t time(time_t * time);
    srand((unsigned int)time(NULL));
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //敵の位置の初期化
    posEnemy[0] = -0.5;
    posEnemy[1] = 0.5;
    //敵の色の初期化
    colEnemy[0] = 1.0;
    colEnemy[1] = 0.8;
    colEnemy[2] = 0.4;
    //ボックスの背景色を指定
    colBack[0] = 0.0;
    colBack[1] = 0.0;
    colBack[2] = 0.0;
    //ボックスサイズを初期化
    box_size = 0.42;
}
 
int main(int argc, char* argv[]){
    glutInit(&argc, argv); //GLUTライブラリを初期化
    //表示モードをダブルバッファリングに設定
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow(argv[0]); //ウィンドウを生成
    glutDisplayFunc(display); //ウィンドウの描画を行う関数を指定
    glutTimerFunc(100, updatePos, 0);
    glutMouseFunc(mouse);
    init(); //初期化
    glutMainLoop(); //メインループ
    return EXIT_SUCCESS;
}