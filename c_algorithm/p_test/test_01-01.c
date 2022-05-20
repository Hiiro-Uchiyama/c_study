#include <stdio.h>

int main(){

    int get_01 = 0;
    int get_02 = 0;
    int i = 0;

    scanf("%d", get_01);
    scanf("%d", get_02);

    if(get_01<=get_02){
        printf("大きい方の数値はget_02です。");
        for(i <= get_02;  i++; get_01 <= i){
            /*--get_01の情報が参照できませんでした。--*/
            if(i % 7 == 0){
                printf("%d", i);
                /*--7の倍数を表示--*/
            }
        }
    }
    else{
        printf("大きい方の数値はget_01です。");
        for(i <= get_01; i++; get_02 <= i){
            if(i % 7 == 0){
                print("%d", i);
            }
        }
    }
    return 0;
}