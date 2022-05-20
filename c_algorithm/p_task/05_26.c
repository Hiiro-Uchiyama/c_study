/*
5月26日小テスト内容
行列Aを受け取りAの各要素を五倍した行列B及びAの各要素を10倍した行列Cを計算するcalcMatを呼び出せ
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--グローバル変数があれば--*/
int b[2][2] = {};
int c[2][2] = {};
/*----*/
void calcMat(int a_a[2][2]){
    //変数の宣言
    int i = 0;
    int j = 0;
    //関数ないの処理
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            b[i][j] = a_a[i][j]*5;
            c[i][j] = b[i][j]*2;
        }
    }
}

int main(void){
    //変数の宣言
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    //行列A
    int a[2][2] = {{1,2},
                   {3,4}};
    //main処理
    calcMat(a);
    printf("行列b\n");
    for (k = 0; k < 2; k++){
        for (l = 0; l < 2; l++){
            printf("%d ", b[k][l]);
        }
        printf("\n");
    }
    printf("行列c\n");
    for (m = 0; m < 2; m++){
        for (n = 0; n < 2; n++){
            printf("%d ", c[m][n]);
        }
        printf("\n");
    }
}


/*
行列b
5 10 
15 20
行列c
10 20 
30 40 
*/