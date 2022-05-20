#include <OpenGL/OpenGL.h> // OpenGL
#include <GLUT/GLUT.h> // 表示等を行う
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define PI 3.141592653589793
 
typedef  struct {
    double pos_0;       // 位置x座標
    double pos_1;       // 位置y座標
    double size;          // サイズ
    double sign1;        // 符号
    double sign2;        // 符号
    double param1;     // パラメータ1
    double param2;     // パラメータ2
    double param3;     // パラメータ3
    double color[3];// カラー
    int  startangle;// 円の開始角度
    int  endangle;        // 円の終了角度
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
 
void drawCircle(face fval) {
    int i;
    glBegin(GL_LINE_STRIP); //折れ線の描画開始
    for (i = fval.startangle; i <= fval.endangle; i += 360.0 / 36) {
        glColor3d(fval.color[0], fval.color[1], fval.color[2]); //描画色を指定
        glVertex2d(
            fval.pos_0 + fval.sign1 * fval.size * fval.param1 + fval.size * fval.param3 * cos(3.14 * i / 180), //線分のx座標
            fval.pos_1 + fval.sign2 * fval.size * fval.param2 + fval.size * fval.param3 * sin(3.14 * i / 180)  //線分のy座標
        );
    }
    glEnd(); //描画終了
}

//顔の描画
void drawFace3(int type) {
    drawCircle(brow_left);
    drawCircle(brow_right);
    drawCircle(eye_left);
    drawCircle(eye_right);
    drawCircle(nose);
    drawCircle(faceline);
    //タイプ
    if (type == 0) {
        drawCircle(mouth_t0);  //口
    }
    else if (type == 1) {
        drawCircle(mouth_t1);  //口
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
