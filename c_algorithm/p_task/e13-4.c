/*
身長が格納された配列hと体重が格納された配列wがあるとする。
data.txtに書き出すプログラムを作成すること。
hとwの数値は決めていい。
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    /*--変数の宣言--*/
    int i = 0;
    double h[5] = {123.3, 135,167,189,200};
    double w[5] = {32.3, 21, 53, 76, 100};

    FILE* fp;

    /*--num.txtをリーディングモードで読み込み--*/
    fp = fopen("data.txt", "w");

    /*--開けなかった時の処理--*/
    if (fp == NULL){
        printf("開けないようだぜ");
        return -1;
    }
    /*--開けた場合には以下の処理を行う--*/
    else {
        /*--配列の値を書き出す--*/
        for(i = 0; i < 5; i++){
            fprintf(fp, "H : %.1f, W : %.1f\n", h[i], w[i]);
        }
    }
    fclose(fp);
    return 0;
}


/*
H : 123.3, W : 32.3
H : 135.0, W : 21.0
H : 167.0, W : 53.0
H : 189.0, W : 76.0
H : 200.0, W : 100.0
*/