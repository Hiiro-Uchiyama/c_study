/*-------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
/*-------------------------------------------------------------------------------------------------*/
 
// 初期化関数
void init(void) {
           //背景色を指定
           glClearColor(0.0, 0.0, 0.0, 1.0);
}
 
// Step 2
//矩形描画関数
void drawRect(double pos[2], double size[2], double color[3]) {

           glColor3d(color[0], color[1], color[2]); //描画色を指定
           glBegin(GL_LINE_LOOP);
           glVertex2d(pos[0], pos[1]); //点Aの座標
           glVertex2d(pos[0] + size[0], pos[1]); //点Bの座標
           glVertex2d(pos[0] + size[0], pos[1] - size[1]); //点Cの座標
           glVertex2d(pos[0], pos[1] - size[1]); //点Dの座標
           glEnd();

}
 
//Step 3
//円描画関数
void drawCircle(double pos_x, double pos_y, double radius, int startAngle, int endAngle) {

           int i;
           glBegin(GL_LINE_STRIP); //折れ線の描画開始

           for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
                      glColor3d(i / 360.0, i / 360.0, i / 360.0); //描画色を指定
                      glVertex2d(
                                  pos_x + radius * cos(3.14 * i / 180), //線分のx座標
                                  pos_y + radius * sin(3.14 * i / 180)  //線分のy座標
                      );
           }

           glEnd(); //描画終了

}

//描画関数
void display(void) {

           int i;
           double pos[2], size[2], color[3];
 
           //バッファをクリア
           glClear(GL_COLOR_BUFFER_BIT);
 
           //描画する線の情報
           //三角形 1 の描画
           glColor3d(0.7, 1.0, 0.8); //線の色を指定
           glBegin(GL_LINE_LOOP); //囲み線の描画開始
           glVertex2d(0.0, 0.5); //点Aの座標(x, y: -1～1)
           glVertex2d(0.5, 0.0); //点Bの座標(x, y: -1～1)
           glVertex2d(-0.5, 0.0); //点Cの座標(x, y: -1～1)
           glEnd(); //描画終了
 
           //三角形 2 の描画
           glColor3d(0.5, 0.5, 0.5); //線の色を指定
           glBegin(GL_LINE_LOOP); //囲み線の描画開始
           glVertex2d(0.0, -0.5); //点dの座標(x, y: -1～1)
           glVertex2d(0.5, 0.0); //点Bの座標(x, y: -1～1)
           glVertex2d(-0.5, 0.0); //点Cの座標(x, y: -1～1)
           glEnd(); //描画終了
 
           //多重矩形の描画
           for (i = 1; i < 10; i++) {
                      pos[0] = -0.1 * i; //点Aのx座標
                      pos[1] = 0.1 * i; //点Aのy座標
                      size[0] = 0.2 * i; //点B～Dのx座標（点Aのx座標からの変化量）
                      size[1] = 0.2 * i; //点B～Dのy座標（点Aのy座標からの変化量）
                      color[0] = 1.0 - 0.1 * i; //線の色（赤）
                      color[1] = 0.5; //線の色（緑）
                      color[2] = 0.0 + 0.1 * i; //線の色（青）
                      drawRect(pos, size, color); //矩形描画関数の呼び出し
           }
 
           // 3つの円の描画
           for (i = 0; i <= 2; i++) {
                      drawCircle(1.0 - i, -1.0 + i, 0.5, 0, 360); //円描画関数の呼び出し
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
/*-------------------------------------------------------------------------------------------------*/