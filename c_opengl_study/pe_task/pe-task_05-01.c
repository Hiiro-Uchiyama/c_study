//
//  main.c
//  C_C
//
//  Created by Hiiro Uchiyama on 2021/05/07.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#define PI 3.141592653589793

void drawCircle(double pos_x, double pos_y, double radius, int startAngle, int endAngle) {

           int i;
           glBegin(GL_LINE_STRIP); //折れ線の描画開始
           for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
                      glColor3d(i / 360.0, i / 360.0, i / 360.0); //描画色を指定
                      glVertex2d (
                                  pos_x + radius * cos (3.14 * i / 180), //線分のx座標
                                  pos_y + radius * sin (3.14 * i / 180)  //線分のy座標
                      );
           }
           glEnd(); //描画終了
           
}

//顔の描画
void drawFace(double posGiven[2], int type){
    double size = 0.2;
    //顔の輪郭
    drawCircle(posGiven[0], posGiven[1], size * 1.0, 0, 360);
    //左目
    drawCircle(posGiven[0] - size * 0.4, posGiven[1] + size * 0.3, size * 0.1, 0, 360);
    //右目
    drawCircle(posGiven[0] + size * 0.4, posGiven[1] + size * 0.3, size * 0.1, 0, 360);
    //口
    if (type == 0){
        drawCircle(posGiven[0], posGiven[1] + size * 0.2, size * 0.8, 225, 315);
    }
    else if (type == 1){
        drawCircle(posGiven[0], posGiven[1] - size * 1.0, size * 0.8, 45, 135);
    }
}


void init(void){
    //背景色の指定
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

//描画関数
void disply(void){
    double pos_f[2] = {0.5, 0.5};
    //バッファをクリア
    glClear(GL_COLOR_BUFFER_BIT);
    drawFace(pos_f, 0);
    glFlush();
}

int main(int argc, char* argv[]){
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
