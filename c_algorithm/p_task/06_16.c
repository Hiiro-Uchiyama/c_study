/*--==
小テスト問題 第8回(6/9) ポインター
二つのint型の値a、bを受け取る。引数a、bは値渡しをすること。
戻り値は演算を行った回数を定数2を表す。
--==*/


#include <stdio.h>

/*-- 関数 引数 int型ポインタ --*/
int multiCal(int *add, int *mul, int a_, int b_){
    //足し算をaddに格納
    *add = a_ + b_;
    //掛け算をmulに格納
    *mul = a_ * b_;
    //2を返せばいいらしい
    return 2;
}

/*-- main関数 --*/
int main(void){
    //変数の宣言
    int addition = 0;
    int multiplication = 0;
    int a = 5;
    int b = 6;
    int *added;
    int *muled;
    //なんか忘れてた処理
    int x;
    x = multiCal(added, muled, a, b);

    //ポインタを指定
    added = &addition;
    muled = &multiplication;
    
    //実行結果を示す
    printf("%d\n", x);
    printf("%d\n", *added);
    printf("%d\n", *muled);
    
    return 0;
}


/*--==
予測値
2
11
30
コード実効結果
2
11
30
==--*/