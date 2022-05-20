//
//  pe-task_03.c
//  OpenGL
//
//  Created by Hiiro Uchiyama on 2021/04/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>


// 初期化関数
void init(void) {

           //背景色を指定
           glClearColor(0.0, 0.0, 0.0, 1.0);

}

//円描画関数
void drawCircle(double pos_x, double pos_y, double radius, int startAngle, int endAngle) {

           int i;
           glBegin(GL_LINE_STRIP); //折れ線の描画開始
           for (i = startAngle; i <= endAngle; i += 360.0 / 100) {
                      glColor3d(1.0, 0.0, 0.0); //描画色を指定
                      glVertex2d (
                                  pos_x + radius * cos (3.14 * i / 180), //線分のx座標
                                  pos_y + radius * sin (3.14 * i / 180)  //線分のy座標
                      );
           }
           glEnd(); //描画終了

}

//描画関数
void display(void) {
 
           double pos[2], size[2], color[3];
           int i;
 
           //バッファをクリア
           glClear(GL_COLOR_BUFFER_BIT);
 
           //描画する線の情報
           //Step 1: 茎の部分
           glColor3d(0.7, 1.0, 0.8); //線の色を指定
           glBegin(GL_LINES); //囲み線の描画開始
           glVertex2d(0.0, 0.8); //点Aの座標(x, y: -1～1)
           glVertex2d(0.0, 0.3); //点Bの座標(x, y: -1～1)
           //glVertex2d(-0.5, 0.0); //点Cの座標(x, y: -1～1)
           glEnd(); //描画終了

           // 葉っぱ部分
           glColor3d(0.7, 1.0, 0.8);
           glBegin(GL_QUADS);
           glVertex2d(0.0, 0.8);
           glVertex2d(0.2, 0.2);
           glVertex2d(0.6, 0.5);
           glVertex2d(0.8, 0.3);
           glEnd();
    
           // Step 3: 円の描画
           for(i=0; i<=200; i++){
               drawCircle (0.0, 0.0, 0.5-0.0025*i, 0, 360); //円描画関数の呼び出し
           }
           glFlush(); //命令実行

}

int main(int argc, char* argv[]) {

           //GLUTライブラリを初期化
           glutInit(&argc, argv);
 
           //表示モードを設定
           glutInitDisplayMode(GLUT_RGBA);
 
           //ウィンドウを生成
           glutCreateWindow(argv[0]);
 
           //描画を行う関数を指定
           glutDisplayFunc(display);
 
           //初期化
           init();
 
           //メイングループ
           glutMainLoop();
 
           return EXIT_SUCCESS;
           
}
