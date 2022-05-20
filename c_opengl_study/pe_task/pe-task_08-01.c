#include <stdio.h>
#include <stdlib.h>
#include "glut.h"
#include <math.h> //sin(), cos()を使用するためのヘッダファイルの読み込み
 
//点の初期設定
double posDot[2] = { 0.9, 0 }; //ポジションを表す変数
GLfloat colDot[3] = { 1.0, 1.0, 1.0 }; //色を表す変数
double velDot[2] = { -0.05, 0.05 }; //移動量のための変数
 
//円の初期設定
double posCir[2] = { -0.9, 0 }; //ポジションを表す変数
GLfloat colCir[3] = { 1.0, 0.0, 0.0 }; //色を表す変数
double velCir[2] = { 0.1, 0.1 }; //移動量のための変数
 
//キーの状態を表すグローバル変数（0のとき：押されていない，1のとき：押されている）
int keyUp = 0, keyDown = 0, keyLeft = 0, keyRight = 0;
 
//枠との接触状態を表すグローバル変数（0:ぶつかっていない, 1:ぶつかっている）
int isCrushingFrame = 0;
 
double posPlayer[2] = { 0,0 };  //プレーヤー図形の位置を格納する配列変数
double distance = 0;            //プレーヤー図形と敵図形の距離を格納する変数
 
 
void checkSpecialKeyPressed(int key, int x, int y) {
           switch (key) {
           case GLUT_KEY_UP:
                      keyUp = 1; break;
           case GLUT_KEY_DOWN:
                      keyDown = 1; break;
           case GLUT_KEY_LEFT:
                      keyLeft = 1; break;
           case GLUT_KEY_RIGHT:
                      keyRight = 1; break;
           }
}
 
//特殊キーが戻された時の処理を行う関数を指定
void checkSpecialKeyReleased(int key, int x, int y) {
           switch (key) {
           case GLUT_KEY_UP:
                      keyUp = 0; break;
           case GLUT_KEY_DOWN:
                      keyDown = 0; break;
           case GLUT_KEY_LEFT:
                      keyLeft = 0; break;
           case GLUT_KEY_RIGHT:
                      keyRight = 0; break;
           }
}
 
//点を描画
void drawDot(double position[2]) {
           glPointSize(10); //点の大きさを指定
           //点の描画座標を指定
           glBegin(GL_POINTS);
           glVertex2d(position[0], position[1]);
           glEnd();
}
 
//円を描画
void drawCircle(double position[2], double radius, int startAngle, int endAngle) {
           int i;
           glBegin(GL_POLYGON); //
           for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
                      glVertex3f(
                                  position[0] + radius * cos(3.14 * i / 180),
                                  position[1] + radius * sin(3.14 * i / 180), 0.0);
           }
           glEnd(); //描画終了
}
 
//　再描画関数（一定時間ごと）
void updatePos(int value) {
           //点の位置の更新
           posDot[0] += velDot[0];
           posDot[1] += velDot[1];
 
           //画面の端まで移動したときは方向変換
           if (posDot[0] >= 1.0 || posDot[0] <= -1.0)
                      velDot[0] *= -1;
           if (posDot[1] >= 1.0 || posDot[1] <= -1.0)
                      velDot[1] *= -1;
 
           //円の位置を更新
           if (keyUp == 1)
                      posCir[1] += velCir[1];
           if (keyDown == 1)
                      posCir[1] -= velCir[1];
           if (keyLeft == 1)
                      posCir[0] -= velCir[0];
           if (keyRight == 1)
                      posCir[0] += velCir[0];
 
           //円が画面の端まで移動したときは停止
           if (posCir[0] >= 1.0)
                      posCir[0] = 1.0;
           if (posCir[0] <= -1.0)
                      posCir[0] = -1.0;
           if (posCir[1] >= 1.0)
                      posCir[1] = 1.0;
           if (posCir[1] <= -1.0)
                      posCir[1] = -1.0;
 
           glutPostRedisplay(); //画面の再描画
           glutTimerFunc(100, updatePos, 0); //一定時間（ミリ秒）後に，この関数を実行
 
           //posCir[]の値をposPlayer[]へ代入
           posPlayer[0] = posCir[0];
           posPlayer[1] = posCir[1];
 
           //枠との当たり判定
           isCrushingFrame = 0;
           if (pow(posPlayer[0], 2.0) > 0.6 || pow(posPlayer[1], 2.0) > 0.6) {
                      isCrushingFrame++;
           }
           printf("posPlayer[0]=%3.2f, posPlayer[1]=%3.2f, !Frame(%d)\n",
                      posPlayer[0], posPlayer[1], isCrushingFrame);
}
 
//画面を描画
void display(void) {
           glClear(GL_COLOR_BUFFER_BIT); //バッファをクリア
           glColor3d(colDot[0], colDot[1], colDot[2]); //描画色の指定
           drawDot(posDot); //点（ドット）を描画
 
           glColor3d(colCir[0], colCir[1], colCir[2]); //描画色の指定
           drawCircle(posCir, 0.05, 0, 360); //円を描画
           glutSwapBuffers();
 
           if (isCrushingFrame > 0) {
                      glClearColor(1.0, 1.0, 1.0, 0.0);
           }
           else {
                      glClearColor(0.0, 0.0, 0.0, 1.0);
           }
}
 
//初期化
void init(void) {
           glClearColor(0.0, 0.0, 0.0, 1.0); //背景色を指定
}
 
int main(int argc, char* argv[]) {
           glutInit(&argc, argv); //GLUTライブラリを初期化
           //表示モードをダブルバッファリングに設定
           glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
           glutCreateWindow(argv[0]); //ウィンドウを生成
           glutDisplayFunc(display); //ウィンドウの描画を行う関数を指定
 
           //特殊キーが押された（戻された）ときの処理を行う関数を指定
           glutSpecialFunc(checkSpecialKeyPressed);
           glutSpecialUpFunc(checkSpecialKeyReleased);
 
           init(); //初期化
 
           //一定時間後に実行する関数を指定
           glutTimerFunc(1000, updatePos, 0);
           glutMainLoop(); //メインループ
 
           return EXIT_SUCCESS;
}