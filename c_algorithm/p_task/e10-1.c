/*
2つのdouble方のポインタを受け取りそれらが差すオブジェクトを入れ替える関数swapD()を作成しろ
*/


#include <stdio.h>

void swapD(double *p_01, double *p_02){
    double *p__01;
    /*-- 入れ替え --*/
    /*-- ポインタを入れ替える --*/
    *p__01 = *p_01;
    *p_01 = *p_02;
    *p_02 = *p__01;
}

int main(void){
    /*-- 変数の宣言 --*/
    double Kagoshima = 12;
    double UV = 13;
    double *N, *M;
    /*-- アドレスの指定 --*/
    N = &Kagoshima;
    M = &UV;
    printf("%p\n", &N);
    printf("%p\n", &M);
    printf("%f\n", *N);
    printf("%f\n", *M);
    swapD(N, M);
    printf("%p\n", &N);
    printf("%p\n", &M);
    printf("%f\n", *N);
    printf("%f\n", *M);
}


/*
-----------------------------
実行結果
-----------------------------
0x7ffee8b528f8
0x7ffee8b528f0
12.000000
13.000000
0x7ffee8b528f8
0x7ffee8b528f0
13.000000
12.000000
-----------------------------
*/