#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

// 初期設定
double posDot[2] = { 0.9, 0 }; //ポジションを表す変数
GLfloat colDot[3] = { 1.0, 1.0, 1.0 }; //色を表す変数
double velDot[2] = { -0.05, 0.05 }; //移動量のための変数

//点の描画
void drawDot(double position[2]) {
    glPointSize(10); //点の大きさ指定
    //点座標指定
    glBegin(GL_POINTS);
    glVertex2d(position[0], position[1]);
    glEnd();
}

// 画面の描画
void updatePos(int value) {
    //点の位置の更新
    posDot[0] += velDot[0];
    posDot[1] += velDot[1];

    //画面端まで移動した時の方向転換
    if (posDot[0] >= 1.0 || posDot[0] <= -1.0)
        velDot[0] *= -1;
    if (posDot[1] >= 1.0 || posDot[1] <= -1.0)
        velDot[1] *= -1;
        
    glutPostRedisplay(); //画面の描画
    glutTimerFunc(100, updatePos, 0); //一定時間ごにこの関数を実行
}

//画面を描画
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); //バッファをクリア
    glColor3d(colDot[0], colDot[1], colDot[2]); //描画色の指定
    drawDot(posDot); //点描画
    glFlush();
    glutSwapBuffers(); //ダブルバッファを交換
}

//初期化
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); //背景色を指定
}

//メイン関数
int main(int argc, char* argv[]) {
    glutInit(&argc, argv); //GLUTライブラリの初期化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //
    glutCreateWindow(argv[0]); //ウィンドウを生成
    glutDisplayFunc(display); //画面描画を行う関数を指定
    init(); //初期化
    //一定時間後に実行する関数を指定
    glutTimerFunc(1000, updatePos, 0);
    glutMainLoop(); //メインープ
    return EXIT_SUCCESS;
}
