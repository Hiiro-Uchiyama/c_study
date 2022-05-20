#include <stdio.h>

int ave(int Qty, int total){
    //aveを宣言
    int ave = 0;
    //aveに第1引数の入力する整数値の個数で合計を割っている
    ave = total / Qty;
    return ave;

}

int main(void){
    
    //変数を宣言
    int i = 1;
    int Total = 0;
    int Num = 0;
    int T = 0;

    printf("入力したい数値の数を入力して下さい");
    scanf("%d", &Num);
    while(i <= Num){
        printf("数値を入力して下さい");
        scanf("%d", &T);
        Total = Total + T;
        i++;
    }
    //int型で計算しているため小数点は表示しない
    //double型にする必要
    printf("入力された数値の平均は: %d\n", ave(Num, Total));
    return 0;

}

/*--
入力したい数値の数を入力して下さい3
数値を入力して下さい1
数値を入力して下さい2
数値を入力して下さい3
入力された数値の平均は: 2
--*/
