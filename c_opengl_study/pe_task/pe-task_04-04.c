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
    //3点を配列vtx1として宣言
    static const GLfloat vtx1[] = {0.0f, 0.8f, 0.8f, 0.0f, -0.8f, 0.0f};
    static const GLfloat vtx2[] = {-0.8f, 0.6f, 0.0f, 0.7f, -0.8f, -0.6f, 0.8f, 0.6f, 0.0f, -0.7f, 0.8f, -0.6f};
    
    //バッファをクリア
    glClear(GL_COLOR_BUFFER_BIT);

    /*
    ...
    */
    /*
    //配列を用いた点の描画
    glColor3d(0.2, 0.2, 0.8);//色の指定
    glPointSize(10.0);//点のサイズ
    glVertexPointer(2, GL_FLOAT, 0, vtx1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays( GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
    */
    
    //多角形の描画
    glColor3d(0.1, 0.8, 0.1);//色の指定
    glPointSize(10.0);
    glVertexPointer(2, GL_FLOAT, 0, vtx2);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
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
