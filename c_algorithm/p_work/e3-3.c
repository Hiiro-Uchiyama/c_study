#include <stdio.h>

int main(){

    int i;
    int n;

    printf("整数値を入力してください");
    scanf("%d", &n);

    if (n < 0){
        i = n * -1;
        printf("負の数値が入力されました。絶対値は: %d\n", i);
    }
    else {
        printf("絶対値は: %d\n", n);
    }
    return 0;
}

/*
整数値を入力してください3
絶対値は: 3
*/