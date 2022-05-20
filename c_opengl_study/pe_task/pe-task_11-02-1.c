#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h> // OpenGL
#include <GLUT/GLUT.h> // 表示等を行う
#include <math.h> //sin(), cos()を使用するためのヘッダファイルの読み込み
#include <string.h>// 文字表示用
//稀に生じる文字表示用のライブラリのエラーを回避する
#pragma warning (disable: 4996)
#define NUM_ENEMIES 3 //文字列を任意のマクロ名に書き換える
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
int isCrushingEnemy = 0;//敵との当たり判定
double posPlayer[2] = { 0,0 };  //プレーヤー図形の位置を格納する配列変数
double distance[NUM_ENEMIES] = { 0,0,0 };            //プレーヤー図形と敵図形の距離を格納する変数
double posEnemy[NUM_ENEMIES][2]; //敵の図形の位置を格納する配列変数
GLfloat colEnemy[NUM_ENEMIES][3];
//グローバル変数の宣言
int score = 200;//スコア用のグローバル変数を定義
int flag_gameover = 0;// ゲームオーバー判定のフラグ
// 敵の移動量を格納する
double velEnemy[NUM_ENEMIES][2];

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
    int enemyID;
    int i;
    if (score <= 0){
        ;
    }
    else {
        //点の位置の更新
        for (enemyID = 0; enemyID < 3; enemyID++){
            for (i = 0; i < 2; i++){
                posEnemy[enemyID][i] += velEnemy[enemyID][i];
            }
        }
        //画面の端まで移動したときは方向変換
        for (enemyID = 0; enemyID < 3; enemyID++){
            for (i = 0; i < 2; i++){
                if (posEnemy[enemyID][i] >= 1.0 || posEnemy[enemyID][i] <= -1.0){
                    velEnemy[enemyID][i] *= -1;
                }
                else if (rand() % 20 == 1){
                    velEnemy[enemyID][i] *= -1;
                }
            }
        }
    }
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
    //posCir[]の値をposPlayer[]へ代入
    posPlayer[0] = posCir[0];
    posPlayer[1] = posCir[1];
    //枠との当たり判定
    isCrushingFrame = 0;
    if (pow(posPlayer[0], 2.0) > 0.6 || pow(posPlayer[1], 2.0) > 0.6) {
                isCrushingFrame++;
                score--;
    }
    //距離の計算を行う
    for (enemyID = 0; enemyID < 3; enemyID++){
        distance[enemyID] = sqrt(pow((posPlayer[0] - posEnemy[enemyID][0]), 2.0) + pow((posPlayer[1] - posEnemy[enemyID][1]), 2.0));
    }
    //敵との当たり判定
    isCrushingEnemy = 0;
    for (enemyID = 0; enemyID < 3; enemyID++){
        if (distance[enemyID] < 0.15) {
            isCrushingEnemy++;
            score -= 10;
            if (score < 0){
                flag_gameover = 1;
                score = 0;
            }
        }
    }
    printf("posEnemy[0]=%4.2f, posEnemy[1]=%4.3f, !Frame(%d)\n",
                distance[0], distance[1], isCrushingFrame);
    glutPostRedisplay();
    glutTimerFunc(100, updatePos, 0);
}

//画面を描画
void display(void) {
    char str[20];//スコア表示用
    char strgameover[20];//GameOver表示用
    int enemyID;
    unsigned int i;//繰り返し用
    unsigned int m;//繰り返し用
    glClear(GL_COLOR_BUFFER_BIT); //バッファをクリア
    //スコア表示
    if (flag_gameover == 0){
        sprintf(str, "Scotr: %07d", score);
        glColor3f(0.6, 0.6, 0.6);
        glRasterPos2i(-1.0, -1.0);
        for (i = 0; i < strlen(str); i++){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
        }
    }
    else if (flag_gameover == 1){
        sprintf(strgameover, "Game Over");
        glColor3f(0.6, 0.6, 0.6);
        glRasterPos2i(-1.0, -1.0);
        for (m = 0; m < strlen(strgameover); m++){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strgameover[m]);
        }
    }
    for (enemyID = 0; enemyID < 2; enemyID++){
        glColor3d(colEnemy[enemyID][0], colEnemy[enemyID][1], colEnemy[enemyID][2]);// 描画色の指定
        drawDot(posEnemy[enemyID]);// 点の描画
    }
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
    int enemyID;
    int i;
    glClearColor(0.0, 0.0, 0.0, 1.0); //背景色を指定
    for (enemyID = 0; enemyID < 3; enemyID++){
        for (i = 0; i < 2; i++){
            posEnemy[enemyID][i] = 2.0 * rand() / RAND_MAX - 1.0;
            velEnemy[enemyID][i] = 0.1 * rand() / RAND_MAX - 0.05;
        }
        for (i = 0; i < 3; i++){
            colEnemy[enemyID][i] = (double)rand() / RAND_MAX;
        }
    }
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
