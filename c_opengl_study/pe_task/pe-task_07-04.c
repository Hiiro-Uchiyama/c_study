#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> //sin(), cos()

double posDot[2] = { 0.9, 0 }; //ポジションを表す変数
GLfloat colDot[3] = { 1.0, 1.0, 1.0 }; //色を表す
double velDot[2] = { -0.05, 0.05 }; //移動量のための変数

double posCir[2] = { -0.9, 0 }; //ポジションを表す
GLfloat colCir[3] = { 1.0, 0.0, 0.0 }; //色を表す
double velCir[2] = { 0.1, 0.1 }; //移動量のための変数

double posTri[2] = { -0.9, 0 };
GLfloat colTri[3] = { 1.0, 0.0, 0.0 };
double postions[2] = { 0.1, 0.1 };
double velTri[2] = { 0.1, 0.1 };

//キー状態を表すグローバル変数
int keyUp = 0, keyDown = 0, keyLeft = 0, keyRight = 0;

//特殊キーが押された時の処理を行う
void checkSpecialKeyPressed(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        keyUp = 1; break;
    case GLUT_KEY_DOWN:
        keyDown = 1; break;
    case GLUT_KEY_LEFT:
        keyLeft = 1; break;
    case GLUT_KEY_RIGHT:
        keyRight = 1; break;
    }
}

//特殊キーが押された時の処理を行う
void checkSpecialKeyReleased(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        keyUp = 0; break;
    case GLUT_KEY_DOWN:
        keyDown = 0; break;
    case GLUT_KEY_LEFT:
        keyLeft = 0; break;
    case GLUT_KEY_RIGHT:
        keyRight = 0; break;
    }
}

//特殊キーが戻された時の処理を行う関数の指定
void drawDot(double position[2]) {
    glPointSize(10); //サイズ
    glBegin(GL_POINTS);
    glVertex2d(position[0], position[1]);
    glEnd();
}

//円の描画関数
void drawCircle(double position[2], double radius, int startAngle, int endAngle) {
    int i;
    glBegin(GL_POLYGON);
    for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
        glVertex3f(
            position[0] + radius * cos(3.14 * i / 180),
            position[1] + radius * sin(3.14 * i / 180), 0.0);
    }
    glEnd();
}

//三角形描画関数
void drawTriangle (double position[2], double position_[2]){
    glBegin(GL_POLYGON);
    glVertex2d(position[0]-position_[0], position[1]);
    glVertex2d(position[0]+position_[0], position[1]);
    glVertex2d(position[0], position[1] + position_[1]);
    glEnd();
}

//再描画関数
void updatePos(int value) {
    //点の位置の更新
    posDot[0] += velDot[0];
    posDot[1] += velDot[1];

    //点が画面の端まで移動した時は方向を転換
    if (posDot[0] >= 1.0 || posDot[0] <= -1.0)
        velDot[0] *= -1;
    if (posDot[1] >= 1.0 || posDot[1] <= -1.0)
        velDot[1] *= -1;

    //円の位置を更新
    if (keyUp == 1)
        posCir[1] += velCir[1];
    if (keyDown == 1)
        posCir[1] -= velCir[1];
    if (keyLeft == 1)
        posCir[0] -= velCir[0];
    if (keyRight == 1)
        posCir[0] += velCir[0];

    //円が画面の端まで移動した時は停止
    if (posCir[0] >= 1.0)
        posCir[0] = 1.0;
    if (posCir[0] <= -1.0)
        posCir[0] = -1.0;
    if (posCir[1] >= 1.0)
        posCir[1] = 1.0;
    if (posCir[1] <= -1.0)
        posCir[1] = -1.0;
    
    // 点の位置を更新させたかった
    //点の位置を更新
    if (keyUp == 1)
        posTri[1] += velTri[1];
    if (keyDown == 1)
        posTri[1] -= velTri[1];
    if (keyLeft == 1)
        posTri[0] -= velTri[0];
    if (keyRight == 1)
        posTri[0] += velTri[0];

    //点が画面の端まで移動した時は停止
    if (posTri[0] >= 1.0)
        posTri[0] = 1.0;
    if (posTri[0] <= -1.0)
        posTri[0] = -1.0;
    if (posTri[1] >= 1.0)
        posTri[1] = 1.0;
    if (posTri[1] <= -1.0)
        posTri[1] = -1.0;

    glutPostRedisplay(); //描画
    glutTimerFunc(100, updatePos, 0); //一定時間後にこの関数を実行
}

//画面を描画
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); //バッファをクリア
    glColor3d(colDot[0], colDot[1], colDot[2]); //描画色の指定
    drawCircle(posDot, 0.05, 0, 360); //円を書く
    
    glColor3d(colTri[0], colTri[1], colTri[2]);
    drawTriangle(posTri, postions);

    glutSwapBuffers();
}

//初期化
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); //背景色の指定
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv); //ライブラリの初期化
    //表示モードをダブルバッファリング
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow(argv[0]); //ウィンドウ生成
    glutDisplayFunc(display); //画面描画を行う関数の指定
    
    glutSpecialFunc(checkSpecialKeyPressed);
    glutSpecialUpFunc(checkSpecialKeyReleased);
    
    init(); //初期化

    //一定時間後に実行数
    glutTimerFunc(1000, updatePos, 0);
    glutMainLoop(); //メインループ

    return EXIT_SUCCESS;
}
