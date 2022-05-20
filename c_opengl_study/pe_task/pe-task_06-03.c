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

double posBegin[2];
double posEnd[2];
double *p_pos = NULL;//座標
double *p_size = NULL;//サイズ
double *p_color = NULL;//色
double *static_pos = NULL;//ランダム座標

//三角形描画関数
void drawTri (double pos[2], double static_pos[2], double size[2], double color[3]){
    glColor3d(color[3], color[1], color[2]);
    glBegin(GL_POLYGON);
    glVertex2d(pos[0], pos[1]);
    glVertex2d(pos[0] + size[0], pos[1]);
    glVertex2d(static_pos[0] + size[0], static_pos[0] - size[1]);
    glEnd();
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
    p_size = (double*)malloc(sizeof(double) * 2);
    p_color = (double*)malloc(sizeof(double) * 3);
    static_pos = (double*)malloc(sizeof(double) * 2);
    for (i = 0; i < 2; i++){
        p_pos[i] = posBegin[i];
        p_size[i] = posEnd[i] - posBegin[i];
        static_pos[i] = ((double)rand()/RAND_MAX)*2-1;
        if (i == 1){
            p_size[i] *= -1;
        }
    }
    for (i = 0; i < 3; i++){
        p_color[i] = (double)rand() / RAND_MAX;//色を配色
    }
}

//画面を描画
void disply(void){
    glClear(GL_COLOR_BUFFER_BIT);
    if (p_pos != NULL){
        drawTri(p_pos, static_pos, p_size, p_color);
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
