#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char fileName[20];
    char buffer[256];

    FILE *fp;
    //ファイル名を取得する
    printf("表示するファイルの名前を入力して下さい。\n");
    scanf("%s", &fileName);

    //ファイルを開く
    if((fp = fopen(fileName, "r")) == NULL){
        printf("ファイルのオープンに失敗しました。\n");
        exit(1);
    }
    while(fgets(buffer, 256, fp) != NULL){
        printf("%s", buffer);
    }
    fclose(fp);

    return 0;
}