/*
rand()関数を使ってみよう。
*/

#include <stab.h>
#include <stdlib.h>

/*-- main関数  --*/
int main(void){
    //変数を宣言
    int N1 = 0;
    int N2 = 0;
    int N3 = 0;
    //3つの数値を入力させる
    printf("3つの整数値を入力して下さい。\n");
    scanf("%d", &N1);
    scanf("%d", &N2);
    scanf("%d", &N3);
    //
    printf("入力された数値のうち3の倍数となるのは: %d\n", getMuls(N1, N2, N3));
    return 0;
}