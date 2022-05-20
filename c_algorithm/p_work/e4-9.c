#include <stdio.h>

int main(){

    int I, Num;

    printf("数値を入力して下さい。");
    scanf("%d", &Num);

    for(I = 1; I <= Num; I++){
        if(I % 2 == 1){
            printf("+");
        }
        else if (I % 2 == 0){
            printf("-");
        }
    }

    return 0;

}

/*
数値を入力して下さい。7
+-+-+-+
*/