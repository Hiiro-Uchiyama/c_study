/*--配列の使い方--*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--課題2--*/

int a[100] = {};
int b[100] = {};

/*--getAve関数--*/
int getAve(int a_0[100], int b_0[100], int a_num, int b_num){
    /*--変数の宣言--*/
    int i_a = 0;
    int i_b = 0;
    int total_a = 0;
    int total_b = 0;

    for (i_a = 0; i_a < a_num; i_a++){
        total_a = total_a + a_0[i_a];
    }
    for (i_b = 0; i_b < b_num; i_b++){
        total_b = total_b + a_0[i_b];
    }
    return printf("一つ目の集合の合計値は%dで平均は%f\n二つ目の集合の合計値は%dで平均は%f\n", total_a, (double)total_a/a_num,total_b, (double)total_b/b_num);
}

int main(void){
    int num_a = 0;
    int num_b = 0;
    int a_i = 0;
    int b_i = 0;
    /*--2つの配列aとbとそれぞれの配列の長さを受け取り
    配列aと配列bの全要素の平均を返すgetAveを作成しろ。またその動作を確認するmain関数を書け--*/
    printf("一つの集合における入力可能な合計数は100までです。\n");
    printf("有効数字まじ卍高校。卍っ。(๑╹ω╹๑ )\n");
    printf("一つ目の集合に入力する数値の合計数を入力して下さい。\n");
    scanf("%d", &num_a);
    while(a_i < num_a){
        int a_total = 0;
        printf("数値を入力して下さい。");
        scanf("%d", &a_total);
        a[a_i] = a_total;
        a_i++;
    }
    printf("次に二つ目の集合に入力する数値の合計数を入力して下さい。");
    scanf("%d", &num_b);
    while(b_i < num_b){
        int b_total = 0;
        printf("数値を入力して下さい。");
        scanf("%d", &b_total);
        b[b_i] = b_total;
        b_i++;
    }
    printf("それぞれの平均は\n");
    /*--関数に配列を渡す時ってアドレス演算子いるの?--*/
    getAve(&a[100], &b[100], num_a, num_b);
}
