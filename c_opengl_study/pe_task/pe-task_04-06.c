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


void init(void){
    //背景色の指定
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

//描画関数
void disply(void){
    //配列の宣言
    static GLfloat vrx4[22];
    //バッファをクリア
    glClear(GL_COLOR_BUFFER_BIT);
    
    int n = 0;
    int i = 0;
    vrx4[n] = 0.0f;
    vrx4[++n] = 0.0f;

    for(i = 0; i <=90; i +=10){
        double radian = i * PI / 180.0;
        vrx4[++n] = cos(radian);//x座標
        vrx4[++n] = sin(radian);//y座標
    }
    //扇型
    glColor3d(0.1, 0.8, 0.1);//色の指定
    glPointSize(10.0);//サイズの指定
    glVertexPointer(2, GL_FLOAT, 0, vrx4);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 11);
    glDisableClientState(GL_VERTEX_ARRAY);
    
    glFlush();//実行
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
