#include <stdio.h>

int main(){

    int I, Num;

    //整数値をゲットする
    printf("整数値を入力してください。");
    scanf("%d", &Num);

    for(I=0; I<=Num; I++){
        if(Num % 2 == 1){
            printf("%d", Num);
        }
    }

    return 0;

}

/*
整数値を入力してください。2
*/