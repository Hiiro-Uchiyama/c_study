//各種ヘッダーファイル
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include<stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#pragma warning (disable: 4996)
#define pi 3.141592

//球および四角形の描画関連
double posBounceCir[2] = { -0.8, 0 };
double posBounceCir_2[2] = { 0.8, 0 };
double posBounceCir_3[2] = { 0, 0.8 };
double posBounceCir_4[2] = { 0, -0.8 };
GLfloat colBounceCir[3] = { 1.0, 0.0, 0.0 };
double velBounceCir[2] = { 0.04, 0.04 };
double velBounceCir_2[2] = { 0.03, 0.03 };
double velBounceCir_3[2] = { 0.02, 0.02 };
double velBounceCir_4[2] = { 0.01, 0.01 };
double posSquare[2] = { 0.6, 0.02 };
double left = 0;
double right = 0;
GLfloat colSquare[3] = { 1.0, 1.0, 1.0 };
double velSquare[2] = { 0.01, 0.01 };
GLfloat colb[3] = { 1.0, 1.0, 1.0 };
GLfloat colCir_0[3] = { 1.0, 0, 0 };
GLfloat colCir_1[3] = { 1.0, 1.0, 0 };
GLfloat colCir_2[3] = { 1.0, 1.0, 1.0 };
GLfloat colCir_3[3] = { 0, 0, 1.0 };

//ゲームのスコア及びゲームオーバー判定
int score = 0;
int flag_gameover = 0;

//キーボード関数
double key_n = 0;
double key_left = 0;
double key_b = 0;
double key_right = 0;

//球の動き関連
double m = 0;
double j = 0;
double JudgmentA = 0;
double JudgmentA_2 = 0;
double JudgmentA_3 = 0;
double JudgmentA_4 = 0;
double l= 0;
double JudgmentB = 0;
double JudgmentB_2 = 0;
double JudgmentB_3 = 0;
double JudgmentB_4 = 0;
double n = 0;
double angle = 0;

//スタート時に猶予を与えるための変数
int start = 0;
int second = 10;

void keyboard(unsigned char key, int x, int y){
    //キーボード関数である
    //キーボードでの操作を可能にするためにbボタンとnボタンが押された時に四角形が動くようにleftとrightという変数に変量を代入している
    //key_nとkey_bは逆っぽいがこれで正しく動作する
    left = -0.3 + (30 * (key_b - key_n))/100;
    right = 0.3 + (30 * (key_b - key_n))/100;
    if (left == 1.0) {
        if (key == 'b') {
            key_n = key_n + 0.29;
        }
    }
    else if (right == 1.0) {
        if (key == 'n'){
            key_b = key_b + 0.29;
        }
    }
    else {
        if (key == 'b'){
            key_n = key_n + 0.29;
        }
        if (key == 'n'){
            key_b = key_b + 0.29;
        }
    }
    glutPostRedisplay();
}

void drawBounceCircle(double position[2], double radius, int startAngle, int endAngle) {
    //円を描画する関数
    //処理としては講義中に行った円を描画する関数を使用している
    int i;
    glBegin(GL_POLYGON);
    for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
        glVertex3f(
            position[0] + radius * cos(3.14 * i / 180),
            position[1] + radius * sin(3.14 * i / 180), 0.0);
    }
    glEnd();
}

void drawSquare() {
    //四角形を描画している
    //四角形の両端を計算し描画しているだけのシンプルな関数である。
    glBegin(GL_LINE_LOOP);
    left = -0.2 + 0.2 * (key_b - key_n);
    right = 0.2 + 0.2 * (key_b - key_n);
    glVertex2d(left, -0.95);
    glVertex2d(left, -0.90);
    glVertex2d(right, -0.90);
    glVertex2d(right, -0.95);
    glEnd();
}

void update(int value) {
    
    srand((unsigned int)time(NULL));
    
    if (score < 0){
        ;
    }
    else {
        //※for文を使用するとカクツキが発生したためそれぞれを定義している
        //ちなみにJudgmentAによって球の進んでいる方向とそれに伴って球の進むことのできる上限の設定をしている
        //なおJudgmentAは上下方向JudgmentBは左右方向への移動判定に用いている
        if (JudgmentA == 0){
            posBounceCir[1] += velBounceCir[1] * (rand() % 10)/8;
            if (posBounceCir[1] >= 1.0){
                velBounceCir[1] *= -1;
                JudgmentA = 1;
                score++;
            }
        }
        if (JudgmentA == 1){
            posBounceCir[1] += velBounceCir[1] * (rand() % 10)/8;
            if (posBounceCir[1] <= -0.88 && (fabs(right) - fabs(posBounceCir[0])) <= 0.25 && (fabs(posBounceCir[0]) - fabs(left) <= 0.25)){
                velBounceCir[1] *= -1;
                JudgmentA = 0;
            }
            if (posBounceCir[1] <= -1.1){
                score -= 100;
                flag_gameover = 1;
            }
        }
        if (JudgmentB == 0){
            posBounceCir[0] += velBounceCir[0] * (rand() % 10)/8;
            if (posBounceCir[0] >= 1.0){
                velBounceCir[0] *= -1;
                JudgmentB = 1;
            }
        }
        if (JudgmentB == 1){
            posBounceCir[0] += velBounceCir[0] * (rand() % 10)/8;
            if (posBounceCir[0] <= -0.95){
                velBounceCir[0] *= -1;
                JudgmentB = 0;
            }
        }
    }
    
    if (score < 0){
        ;
    }
    else {
        if (JudgmentA_2 == 0){
            posBounceCir_2[1] += velBounceCir_2[1] * (rand() % 10)/7;
            if (posBounceCir_2[1] >= 1.0){
                velBounceCir_2[1] *= -1;
                JudgmentA_2 = 1;
                score++;
            }
        }
        if (JudgmentA_2 == 1){
            posBounceCir_2[1] += velBounceCir_2[1] * (rand() % 10)/7;
            if (posBounceCir_2[1] <= -0.88 && (fabs(right) - fabs(posBounceCir_2[0])) <= 0.25 && (fabs(posBounceCir_2[0]) - fabs(left) <= 0.25)){
                velBounceCir_2[1] *= -1;
                JudgmentA_2 = 0;
            }
            if (posBounceCir_2[1] <= -1.1){
                score -= 100;
                flag_gameover = 1;
            }
        }
        if (JudgmentB_2 == 0){
            posBounceCir_2[0] += velBounceCir_2[0] * (rand() % 10)/7;
            if (posBounceCir_2[0] >= 1.0){
                velBounceCir_2[0] *= -1;
                JudgmentB_2 = 1;
            }
        }
        if (JudgmentB_2 == 1){
            posBounceCir_2[0] += velBounceCir_2[0] * (rand() % 10)/7;
            if (posBounceCir_2[0] <= -0.95){
                velBounceCir_2[0] *= -1;
                JudgmentB_2 = 0;
            }
        }
    }
    
    if (score < 0){
        ;
    }
    else {
        if (JudgmentA_3 == 0){
            posBounceCir_3[1] += velBounceCir_3[1] * (rand() % 10)/6;
            if (posBounceCir_3[1] >= 1.0){
                velBounceCir_3[1] *= -1;
                JudgmentA_3 = 1;
                score++;
            }
        }
        if (JudgmentA_3 == 1){
            posBounceCir_3[1] += velBounceCir_3[1] * (rand() % 10)/6;
            if (posBounceCir_3[1] <= -0.88 && (fabs(right) - fabs(posBounceCir_3[0])) <= 0.25 && (fabs(posBounceCir_3[0]) - fabs(left) <= 0.25)){
                velBounceCir_3[1] *= -1;
                JudgmentA_3 = 0;
            }
            if (posBounceCir_3[1] <= -1.1){
                score -= 100;
                flag_gameover = 1;
            }
        }
        if (JudgmentB_3 == 0){
            posBounceCir_3[0] += velBounceCir_3[0] * (rand() % 10)/6;
            if (posBounceCir_3[0] >= 1.0){
                velBounceCir_3[0] *= -1;
                JudgmentB_3 = 1;
            }
        }
        if (JudgmentB_3 == 1){
            posBounceCir_3[0] += velBounceCir_3[0] * (rand() % 10)/6;
            if (posBounceCir_3[0] <= -0.95){
                velBounceCir_3[0] *= -1;
                JudgmentB_3 = 0;
            }
        }
    }
    
    if (score < 0){
        ;
    }
    else {
        if (JudgmentA_4 == 0){
            posBounceCir_4[1] += velBounceCir_4[1] * (rand() % 10)/4;
            if (posBounceCir_4[1] >= 1.0){
                velBounceCir_4[1] *= -1;
                JudgmentA_4 = 1;
                score++;
            }
        }
        if (JudgmentA_4 == 1){
            posBounceCir_4[1] += velBounceCir_4[1] * (rand() % 10)/4;
            if (posBounceCir_4[1] <= -0.88 && (fabs(right) - fabs(posBounceCir_4[0])) <= 0.25 && (fabs(posBounceCir_4[0]) - fabs(left) <= 0.25)){
                velBounceCir_4[1] *= -1;
                JudgmentA_4 = 0;
            }
            if (posBounceCir_4[1] <= -1.1){
                score -= 100;
                flag_gameover = 1;
            }
        }
        if (JudgmentB_4 == 0){
            posBounceCir_4[0] += velBounceCir_4[0] * (rand() % 10)/4;
            if (posBounceCir_4[0] >= 1.0){
                velBounceCir_4[0] *= -1;
                JudgmentB_4 = 1;
            }
        }
        if (JudgmentB_4 == 1){
            posBounceCir_4[0] += velBounceCir_4[0] * (rand() % 10)/4;
            if (posBounceCir_4[0] <= -0.95){
                velBounceCir_4[0] *= -1;
                JudgmentB_4 = 0;
            }
        }
    }
    
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
    
    if (score < 0){
        //スコアが0になった時ゲームオーバー判定とスコアを0よりも小さくしゲームの正常終了を行う
        flag_gameover = 1;
        score = -1;
    }
    if (start == 0){
        //10秒間の合間を作るためのスリープ関数とスタートを1にする処理
        sleep(second);
        start = 1;
    }
}

void display(void) {
    
    //文字列の描画のための変数とバッファのクリア
    glClear(GL_COLOR_BUFFER_BIT);
    char str[20];
    char strgameover[20];
    char startstr[50];
    unsigned int i;
    unsigned int m;
    
    if (start == 0){
        //スタートがゼロなら10秒間待ってもらう
        sprintf(startstr, "Pleace wait 10 second.");
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2i(-0.9, 0);
        for (i = 0; i < strlen(startstr); i++){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, startstr[i]);
        }
        glutSwapBuffers();
    }
    else if (start == 1) {
        //スタートがイチならゲームを開始しスコアを表示させる
        if (flag_gameover == 0){
            sprintf(str, "Score: %07d", score);
            glColor3f(1.0, 1.0, 1.0);
            glRasterPos2i(-0.5, 0);
            for (i = 0; i < strlen(str); i++){
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
            }
        }
        else if (flag_gameover == 1){
            sprintf(strgameover, "Game Over.");
            glColor3f(1.0, 1.0, 1.0);
            glRasterPos2i(-0.5, 0);
            for (m = 0; m < strlen(strgameover); m++){
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strgameover[m]);
            }
        }
        
        glColor3d(colSquare[0], colSquare[1], colSquare[2]); //四角形の色を描画
        drawSquare(); //四角形を描画
        glColor3d(colCir_1[0], colCir_1[1], colCir_1[2]); //描画色の指定
        drawBounceCircle(posBounceCir, 0.03, 0, 360); //円を描画
        glColor3d(colCir_2[0], colCir_2[1], colCir_2[2]); //描画色の指定
        drawBounceCircle(posBounceCir_2, 0.03, 0, 360); //円を描画
        glColor3d(colCir_3[0], colCir_3[1], colCir_3[2]); //描画色の指定
        drawBounceCircle(posBounceCir_3, 0.03, 0, 360); //円を描画
        glColor3d(colCir_0[0], colCir_0[1], colCir_0[2]); //描画色の指定
        drawBounceCircle(posBounceCir_4, 0.03, 0, 360); //円を描画
        
        glutSwapBuffers();
        
    }
}

void init(void) {
    //初期化関数
    //ウィンドウ幅を指定
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv); //GLUTライブラリを初期化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]); //ウィンドウを生成
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display); //ウィンドウの描画を行う関数を指定
    init();
    glutTimerFunc(1000, update, 0);
    glutMainLoop(); //メインループ
    return EXIT_SUCCESS;
}

