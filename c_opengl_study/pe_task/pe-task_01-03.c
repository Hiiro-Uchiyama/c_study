#include <stdio.h>

int main(){

    int i = 1;
    int total = 0;

    total = total + i;

    while (i < 100){
        i++;
        total = total + i;
    }

    printf("1から100までの和は%d\n", total);

    return 0;
}