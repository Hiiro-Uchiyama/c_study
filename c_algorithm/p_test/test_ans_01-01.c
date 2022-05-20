#include <stab.h>

int main(void){
    int n1, n2, min, max, i;

    //2つの数をscanfで読み取る
    printf("2つの数を入力して下さい。");
    scanf("%d %d", &n1, &n2);

    //どちらの数が小さいか確認する
    if (n1 > n2){
        max = n1;
        min = n2;
    }
    else {
        max = n2;
        min = n1;
    }

    for (i = min; i <= max; i++){
        //7の倍数以外の時は表示させない
        //7倍数のときは表示する
        if (i % 7 == 0)
            printf("%d", i);
    }
    return 0;
}