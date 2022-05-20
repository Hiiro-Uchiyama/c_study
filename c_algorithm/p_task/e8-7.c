/*
数列の結果を返す
Fk = Fk-1 + Fk-2
*/


#include <stdio.h>

int NumberLineCalculation (int n, int i){
    int num = 1;
    int add = 0;
    if (n == 0 || n == 1){
        return 0;
    }
    while(i < n - 1){
        num += add;
        i++;
        add = num;
        add = NumberLineCalculation(n - 1, i);
    }
    return num;
}

int main(void){
    int ans = 0;
    //By changing the value of n, you can calculate a sequence of numbers.
    //Fk = Fk-1 + Fk-2
    int n = 6;
    int i = 0;
    if (n < 2){
        printf("You may not get the right answer.\n");
    }
    else{
        ans = NumberLineCalculation(n, i);
        printf("%d\n", ans);
    }
    return 0;
}


/*
n = 0;
You may not get the right answer.
n = 1;
You may not get the right answer.
n = 6;
8
n = 123;
242
*/