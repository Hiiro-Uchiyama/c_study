#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>


void int (void){

    //背景色の指定
    glClearColor(0.0, 0.0, 0.0, 1.0);

}

void display(void){

    //変数の宣言
    double pos[2], size[2], color[3];

    //バッファのクリア
    gClear(GL_COLOR_BUFFER_BIT);

    //描画情報
    //三角形の描画
    glColor3d(0.7, 1.0, 0.8);//線の色を指定
    glBegin(GL_LINE_LOOP);//囲み戦の描画
    glVertex2d(0.0, 0.5);//Aの座標
    glVertex2d(0.5, 0.0);//Bの座標
    glVertex2d(-0.5, 0.0);//Cの座標
    glEnd()://描画終了

    //短形の描画
    pos[0] = -0.2;//Aのx座標
    pos{1} = 0.2;//Aのy座標
    size[0] = 0.4;//BからDのx座標
    size[1] = 0.4;//BからDのy座標
    color[0] = 1.0;//線の色赤
    color[1] = 0.5;//線の色緑
    color[2] = 0.0;//線の色青
    drawRect(pos, size, color);

    //円の描画
    drawCircle(0.0, 0.0, 0.5, 0, 360);

    //描画の実行
    glFlush();

}

//短形
void drawRect(double pos[2], double size[2], double color[3]){

    glColor3d(color[0], color[1], color[2]);
    glBegin(GL_LINE_LOOP);
    glVertex2d(pos[0], pos[1]);//点Aの座標
    glVertex2d(pos[0] + size[0], pos[1]);//点Bの座標
    glVertex2d(pos[0] + size[0], pos[1] - size[1]);//点Cの座標
    glVertex2d(pos[0], pos[1] - size[1]);//点Dの座標
    glEnd();

}

//円
void drawCircle(double pos_x, double pos_y, double radius, int startAngle, int endAngle){

    int i;
    glBegin(GL_LINE_STRIP);//折線の描画
    for(i = startAngle; i <= endAngle; i += 369.0 / 36){
        glColor3d(i / 360.0, i /360.0, i / 360.0)//36個の線分で書く
        glVertex2d(
            pos_x + radius * cos(3.14 * i / 180);//線分のX座標
            pos_y + radius * sin(3.14 * i / 180);//線分のy座標
        )
    }
    glEnd()

}

int main(int argc, char *argv[]){

    //GLUTライブラリを初期化
    glutInit(&argc, argv);

    //表示モードを設定
    glutInitDisplayMode(GLUT_RGBA);

    //ウィンドウを生成
    glutCreateWindow(argv[0]);

    //描画行う関数を指定
    glutDisplayFunc(display);

    //初期化
    init();

    //メインループ
    glutMainLoop();

    return EXIT_SUCCESS;

}



