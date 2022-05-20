//
//  main.c
//  C_C
//
//  Created by Hiiro Uchiyama on 2021/05/07.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>

double posBegin[2];
double posEnd[2];
double *p_pos = NULL;//座標
double *p_color = NULL;//色
double *p_radius = NULL;//サイズのこと
double *p_posLength = NULL;//半径

void drawCircle(double pos[2], double color[3], double radius[1], int posLength[2]) {
   int i;
   glBegin(GL_LINE_STRIP); //折れ線の描画開始
   for (i = posLength[0]; i <= posLength[1]; i += 360.0 / 36) {
      //glColor3d(i / 360.0, i / 360.0, i / 360.0); //描画色を指定]
      glColor3d(color[0], color[1], color[2]);
      glVertex2d (
          pos[0] + radius[0] * cos (3.14 * i / 180), //線分のx座標
          pos[1] + radius[0] * sin (3.14 * i / 180)  //線分のy座標
      );
   }
   glEnd(); //描画終了
}

void mouse_sp (int button, int state, int x, int y){
    int i;
    //左ボタンの操作以外を無視する
    if (button != GLUT_LEFT_BUTTON){
        return;
    }
    if(state == GLUT_DOWN){
        posBegin[0] = (double)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;//x座標の格納
        posBegin[1] = -(double)y / glutGet(GLUT_WINDOW_WIDTH) * 2 + 1;
        printf("Left button pressed (%d, %d) ==> (%f, %f)\n", x, y, posBegin[0], posBegin[1]);//左ボタンが押された。
    }
    else if (state == GLUT_UP){
        posBegin[0] = (double)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;//x座標の格納
        posBegin[1] = -(double)y / glutGet(GLUT_WINDOW_WIDTH) * 2 + 1;
        printf("Left button released (%d, %d) ==> (%f, &f)\n", x, y, posBegin[0], posBegin[1]);//左ボタンが放された。
    }
    //新たな短形の描画
    p_pos = (double*)malloc(sizeof(double) * 2);
    p_color = (double*)malloc(sizeof(double) * 3);
    p_radius = (double*)malloc(sizeof(double) * 1);
    p_posLength = (double*)malloc(sizeof(double) * 2);
    for (i = 0; i < 2; i++){
        p_pos[i] = posBegin[i];
        p_posLength[i] = (posEnd[i]-posBegin[i]);
    }
    for (i = 0; i < 3; i++){
        p_color[i] = (double)rand() / RAND_MAX;//色を配色
    }
    p_radius[0] = sqrt(p_posLength[0]*p_posLength[0]+p_posLength[1]*p_posLength[1]);
}

//画面を描画
void disply(void){
    glClear(GL_COLOR_BUFFER_BIT);
    if (p_pos != NULL){
        drawCircle(p_pos, p_color, p_radius, p_posLength);
    }
    glFlush();
    glutPostRedisplay();//指定された関数の呼び出し
}

//初期化
void init (void){
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

//main関数
int main (int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);//表示モード
    glutCreateWindow(argv[0]);
    glutDisplayFunc(disply);
    glutMouseFunc(mouse_sp);//マウスイベントを扱う
    init();//初期化
    glutMainLoop();//メインループ
    return EXIT_SUCCESS;
}
