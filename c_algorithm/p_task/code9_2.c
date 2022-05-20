#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "glut.h"

#define PI 3.141592653589793

typedef  struct {
    double pos_0;	// 位置x座標
    double pos_1;	// 位置y座標
    double size;	// サイズ
    double sign1;	// 符号
    double sign2;	// 符号
    double param1;	// パラメータ1
    double param2;	// パラメータ2
    double param3;	// パラメータ3
    double color[3];// カラー
    int  startangle;// 円の開始角度
    int  endangle;	// 円の終了角度
} face;

face brow_left = { 0.2, 0.2, 0.3, -1.0, 1.0, 0.3, 0.4, 0.1, { 0.9, 0.5, 0.2 }, 0, 180 };
face brow_right = { 0.2, 0.2, 0.3, 1.0, 1.0, 0.3, 0.4, 0.1, { 0.9, 0.5, 0.2 }, 0, 180 };
face eye_left = { 0.2, 0.2, 0.3, -1.0, 1.0, 0.3, 0.3, 0.05, { 0.9, 0.5, 0.2 }, 0, 360 };
face eye_right = { 0.2, 0.2, 0.3, 1.0, 1.0, 0.3, 0.3, 0.05, { 0.9, 0.5, 0.2 }, 0, 360 };
face nose = { 0.2, 0.2, 0.3, 1.0, -1.0, 0, 0.1, 0.2, { 0.9, 0.5, 0.2 }, 70, 290 };
face mouth_t0 = { 0.2, 0.2, 0.3, 1.0, 1.0, 0, 0.2, 0.7, { 0.9, 0.5, 0.2 }, 225, 315 };
face mouth_t1 = { 0.2, 0.2, 0.3, 1.0, -1.0, 0, 1.2, 0.7, { 0.9, 0.5, 0.2 }, 45, 135 };
face faceline = { 0.2, 0.2, 0.3, 1.0, 1.0, 0, 0, 1.0, { 0.9, 0.5, 0.2 }, 0, 360 };


//初期化関数
void init(void) {
    //背景色を指定
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void drawCircle(double pos_x, double pos_y, double color[3], double radius, int startAngle, int endAngle) {

    int i;

    glBegin(GL_LINE_STRIP); //折れ線の描画開始

    for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
        glColor3d(color[0], color[1], color[2]); //描画色を指定
        glVertex2d(
            pos_x + radius * cos(3.14 * i / 180), //線分のx座標
            pos_y + radius * sin(3.14 * i / 180)  //線分のy座標
        );
    }
    glEnd(); //描画終了
}

//顔の描画
void drawFace3(int type) {
    double pos[2] = { 0.2,0.2 };
    double size = 0.3;
    double color_f[3] = { 0.9,0.5,0.2 };

    drawCircle(pos[0] - size * 0.3, pos[1] + size * 0.4, color_f, size * 0.1, 0, 180);   //眉（左）
    drawCircle(pos[0] + size * 0.3, pos[1] + size * 0.4, color_f, size * 0.1, 0, 180);   //眉（右）
    drawCircle(pos[0] - size * 0.3, pos[1] + size * 0.3, color_f, size * 0.05, 0, 360);   //目（左）
    drawCircle(pos[0] + size * 0.3, pos[1] + size * 0.3, color_f, size * 0.05, 0, 360);   //目（右）
    drawCircle(pos[0], pos[1] + size * 0.1, color_f, size * 0.2, 70, 290);   //鼻
    drawCircle(pos[0], pos[1], color_f, size * 1.0, 0, 360);   //輪郭

    //タイプ
    if (type == 0) {
        drawCircle(pos[0], pos[1] + size * 0.2, color_f, size * 0.7, 225, 315);  //口
    }
    else if (type == 1) {
        drawCircle(pos[0], pos[1] - size * 1.2, color_f, size * 0.7, 45, 135);  //口
    }

}


//描画関数
void disply(void) {
    //バッファをクリア
    glClear(GL_COLOR_BUFFER_BIT);
    drawFace3(1);
    glFlush();  //命令実行
}


int main(int argc, char* argv[]) {
    //GlUTライブラリを初期化
    glutInit(&argc, argv);

    //表示モードを設定
    glutInitDisplayMode(GLUT_RGBA);

    //ウィンドウを生成
    glutCreateWindow(argv[0]);

    //描画を行う関数
    glutDisplayFunc(disply);

    //初期化
    init();

    //メインループ
    glutMainLoop();

    return EXIT_SUCCESS;
}
