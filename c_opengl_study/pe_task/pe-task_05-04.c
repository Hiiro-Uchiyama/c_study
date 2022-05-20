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

void drawCircle(double pos_x, double pos_y, double color[3], double radius, int startAngle, int endAngle) {

           int i;
           glBegin(GL_POLYGON); //折れ線の描画開始
           for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
                      //glColor3d(i / 360.0, i / 360.0, i / 360.0); //描画色を指定]
                      glColor3d(color[0], color[1], color[2]);
                      glVertex2d (
                                  pos_x + radius * cos (3.14 * i / 180), //線分のx座標
                                  pos_y + radius * sin (3.14 * i / 180)  //線分のy座標
                      );
           }
           glEnd(); //描画終了
           
}
 
void drawFace2(double posGiven[2], double color_f[3]){
    double size = 0.3;
    double color_f1[3] = {0.996, 0.863, 0.741};
    double color_f2[3] = {0.85, 0.85, 0};
    double color_f3[3] = {0, 0, 0};
    double color_f4[3] = {1.0, 0, 0};
    //顔の輪郭
    drawCircle(posGiven[0], posGiven[1], color_f1, size * 1.0, 0, 360);
    //左目
    drawCircle(posGiven[0] - size * 0.4, posGiven[1] + size * 0.2, color_f3, size * 0.1, 0, 360);
    //右目
    drawCircle(posGiven[0] + size * 0.4, posGiven[1] + size * 0.2, color_f3, size * 0.1, 0, 360);
    //口
    drawCircle(posGiven[0], posGiven[1] + size * 0.2, color_f4, size * 0.8, 225, 315);
    //アフロ
    drawCircle(posGiven[0] + size * 0.05, posGiven[1] + size * 0.8, color_f2, size * 0.3, 0, 360);
    //アフロ
    drawCircle(posGiven[0] + size * -0.3, posGiven[1] + size * 0.8, color_f2, size * 0.3, 0, 360);
    //アフロ
    drawCircle(posGiven[0] + size * 0.4, posGiven[1] + size * 0.8, color_f2, size * 0.3, 0, 360);
}


void init(void){
    //背景色の指定
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

//描画関数
void disply(void){
    double pos_f3[2] = {0.2, 0.2};
    double color_f3[3] = {0.2, 0.2, 0.9};
    static const GLfloat vtx2[] = {0.2f, 0.21f, 0.2f, 0.1f};
    //バッファをクリア
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawFace2(pos_f3, color_f3);
    
    glColor3d(0, 0, 0);
    glPointSize(6.0);
    glVertexPointer(2, GL_FLOAT, 0, vtx2);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_LINES, 0, 2);
    glDisableClientState(GL_VERTEX_ARRAY);
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
