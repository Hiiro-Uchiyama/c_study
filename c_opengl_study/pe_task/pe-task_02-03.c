#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    FILE * fp;//ポインタ宣言
    time_t timer = time(NULL);//time関数によって時刻を取得
    struct tm *t; //tm構造体へのポインタ()
    char memo[140]; //記録するメモを格納する配列

    //現在時刻より時と分を取得
    t = localtime(&timer);

    //記録用ファイルを書き込み可能(=オープン)にする
    if((fp = fopen("memo.txt", "a")) == NULL){
        printf("ファイルのオープンに失敗しました。");
        exit(1);
    }
    //キーボードからの入力をmem配列に格納する
    printf("記録する内容を入力して下さい:");
    fgets(memo, sizeof(memo), stdin);
    //ファイルに現在日時とmemo配列の内容を書き込む
    fprintf(fp, "[%d月%d日 %d時%d分]\n", t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);
    fprintf(fp, "%s\n", memo);
    
    //記録用ファイルを閉じる
    fclose(fp);

    return 0;
}