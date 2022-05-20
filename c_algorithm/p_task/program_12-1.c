/*
復習
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int func2 (int val) {
    return val * 2;
}

int func1 (int val){
    return func2(val) * func2(val - 1);
}

int main(void){
    /*--変数の宣言--*/
    printf("Return value of func1(%d): %d\n", 3, func1(3));
}