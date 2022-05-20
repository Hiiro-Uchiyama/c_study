/*
3つの整数値を引数として受けてとり、そのうちの3の倍数の個数を返す関数を作成しろ。
*/

#include <stdio.h>

/*-- 3の倍数を求める --*/
int getMuls(int n1, int n2, int n3){
    //変数を宣言
    int num = 0;
    int n = 0;

    //3で割った値が0であれば合計値に1を加えていく
    //return 0;や continue; とelse文に書くと実行結果が正しく表示されないのでnという変数に3の倍数でない数値の数を代入している。

    if (n1 % 3 == 0){
        num = num + 1;
    }
    else {
        n = n + 1;
    }
    if (n2 % 3 == 0){
        num = num + 1;
    }
    else {
        n = n + 1;
    }
    if (n3 % 3 == 0){
        num = num + 1;
    }
    else {
        n = n + 1;
    }

    return num;

}

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

/*--
3つの整数値を入力して下さい。
9
6
3
入力された数値のうち3の倍数となるのは: 3
--*/
