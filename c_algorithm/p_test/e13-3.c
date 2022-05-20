/*
List13-2を書き換えて以下のような構造体memberにファイルから読み込んだデータを書き込むようなプログラムを記述せよ
名前は構造体に書かなくていい
member配列studentをメイン関数で宣言せよ
要素数は10とする
ファイル内のデータをstudentに全て格納して身長と体重の合計を計算すること
*/

#include <stdio.h>

struct member{
    double height;
    double weight;
};

int main(void){
    struct member student[10];
    FILE *fp; // ファイルポインタ
    double heights;
    double weights;
    int i = 0;
    int m = 0;
    fp = fopen("hw.dat", "r");
    if (fp == NULL)
    {
        printf("ファイルをオープンできないようだ\n");
    }
    else {
        while(i < 10){
            fscanf(fp, "%lf%lf", &student[i].height, &student[i].weight);
            i++;
        }
    }
    fclose(fp);
    for (m = 0; m < 10; m++){
        heights += student[m].height;
        weights += student[m].weight;
    }
    printf("%0.3f\n", heights);
    printf("%0.3f\n", weights);
    return 0;
}