/*--==
演習5-7: データ数と各データを標準入力から読みとり、malloc関数を使用して配列の領域確保を行いその先頭のアドレスを返す関数makeArrayを作成せよ。
配列のサイズは標準入力で入力された要素数とすること。
makeArrayの動作確認をせよ
--==*/


#include <stdio.h>
#include <stdlib.h>

/*-- 関数 引数 int型ポインタ --*/
int *makeArray(int n){
    int *maker;
    maker = (int *)malloc(sizeof(int) * n);
    if (maker == NULL) {
        printf("メモリが足りないよ");
        exit("EXIT_FAILURE");
    }
    return maker;
}

/*-- main関数 --*/
int main(void){
    //変数の宣言
    int *integer;
    int i = 0;
    int n = 0;
    int m = 0;
    int s = 0;
    //ユーザビリティは低いものの楽なので要素数を聞いちゃう
    printf("入力したいデータの数を自然数で入力してください");
    scanf("%d", &n);
    s = n;
    integer = makeArray(n);
    //格納するための配列を生成
    int Total[n];
    //アドレスを指定
    while(0 < n){
        printf("入力どうぞ");
        scanf("%d", &integer[i]);
        //nを1ずつ減少させることで繰り返しを実行
        n--;
        //iは増加させることで配列の中に順に格納していく
        i++;
    }
    //中身みたい
    while(0 < s){
        printf("%d\n", integer[m]);
        //nを1ずつ減少させることで繰り返しを実行
        s--;
        //iは増加させることで配列の中に順に格納していく
        m++;
    }
    return 0;
}


/*--==
実行結果
入力したいデータの数を自然数で入力してください4
入力どうぞ1
入力どうぞ2
入力どうぞ3
入力どうぞ4
1
2
3
4
==--*/