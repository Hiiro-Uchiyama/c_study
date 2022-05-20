/*
関数の再起呼び出し
5の階乗の計算
関数を内側から呼び出す処理
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int fact (int n){
    int val;
    if (n == 1){
        return ;
    }
    val = n * fact(n - 1);
}

int main(void){
    /*--変数の宣言--*/
    printf("Return value of func1(%d): %d\n", 3, fact(5));
}