/*--配列の使い方--*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--課題1--*/
int main(void){
    int input[100] = {};
    int i = 1;
    int cut = 0;
    int sum = 0;
    int retry;

    do {
        int total = 0;
        printf("整数値を入力して下さい。:");
        scanf("%d", &total);
        /*--配列を使用してみる--*/
        input[cut] = total;
        sum = sum + input[cut];
        printf("まだ?<Yes--0><No--9>");
        printf("input[%d] : %d : %d\n", cut, cut, input[cut]);
        scanf("%d", &retry);
        cut++;
    }
    /*--基本的な構文をしっかりしましょう。--*/
    while (retry == 0);

    printf("合計値は%dで平均は%.2fです。\n", sum, (double)sum/cut);
    return 0;
}


/*--配列の範囲を超えるとなんか大変なことになる。--*/