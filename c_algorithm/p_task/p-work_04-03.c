/*--配列の使い方--*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--課題3--*/
int main(void){
    /*--配列に格納するデータの数を10として要素の値は0から100の間で乱数を表示させて。--*/
    srand((unsigned int)time(NULL));
    int i;
    int x[10];

    for (i = 0; i < 10; i++){
        x[i] = rand() % 100 + 0;
    }
    for (i = 0; i < 10; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }
}
