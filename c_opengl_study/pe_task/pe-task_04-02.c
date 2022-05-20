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

void init(void){
    //背景色の指定
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

//描画関数
void disply(void){
    //バッファをクリア
    glClear(GL_COLOR_BUFFER_BIT);
    //点の描画
    glColor3d(0.8, 0.1, 0.1);//赤を指定
    glPointSize(20.0);//点のサイズを指定
    glBegin(GL_POINTS);//描画の開始
    glVertex2d(0.0, 0.8);
    
    //座標指定を使った三角形描画
    glColor3d(0.7, 1.0, 0.8);//線の色を指定
    glBegin(GL_LINE_LOOP);//囲み線の描画を開始
    glVertex2d(0.0, 0.7);//てんAの描画
    glVertex2d(0.7, 0.0);//てんBの描画
    glVertex2d(-0.7, 0.0);//てんCの描画
    glEnd();
    
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
