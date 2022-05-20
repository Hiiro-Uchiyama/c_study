/*
小テスト内容
data.txtからdouble型の実数データを読み込み負の値をnegs.txtに書き込み、0以上の数字は配列valuesに格納する。
*/


#include <stdio.h>
#define SIZE 500

//main関数
int main(void){
    //変数の宣言
    double values[500] = {};
    double Num = 0;
    int i = 0;
    int n;
    int nn;
    char LINE[SIZE];
    int line = 0;
    int arrayNumber = sizeof values / sizeof values[0];
    //ファイルの読み込みと書き込みの設定
    FILE* fp_data;
    FILE* fp_negs;
    fp_data = fopen("data.txt", "r");
    fp_negs = fopen("negs.txt", "w");

    /*--ファイルの行数を把握--*/
    while (fgets(LINE, SIZE, fp_data) != NULL){
        line++;
    }
    printf("%d\n", line);
    fclose(fp_data);
    fp_data = fopen("data.txt", "r");
    //ファイルを開く処理
    if (fp_data == NULL){
        printf("開けないね");
        return -1;
    }
    //ここの処理が無駄に長くなっている。
    //補填課題にあったfscanfの戻り値ってどうやったらいいんでしょうか。
    //valuesに0入っちゃう。
    else {
        for(i = 0; i < line; i++){
            fscanf(fp_data, "%lf", &Num);
            if(Num < 0){
                fprintf(fp_negs, "%.2f\n", Num);
            }
            else {
                values[i] = Num;
            }
        }
        for (n = 0; n < i; n++){
            
        }
        //配列の0で埋められている箇所を消したい。
        for (nn = 0; nn < arrayNumber; nn++){
            if (values[nn]==0){
                values[nn] = values[nn+1];
                // nn++;
            }
            else{
                continue;
            }
            printf("values : %.2f\n", values[nn]);
        }
    }
    //ファイルを閉じる
    fclose(fp_data);
    fclose(fp_negs);
    return 0;
}


/*
data.txt
12321.5
2132.5
21421.5
0.7
-12.3
-34
-4
-2
13.0

negs.txt
-12.30
-34.00
-4.00
-2.00

values : 12321.50
values : 2132.50
values : 21421.50
values : 0.70
values : 0.00
values : 0.00
values : 0.00
values : 0.00
values : 13.00
*/

/*
valuesから0取りたい
for (i = 0; i < values_long; i**){
    if(values[i]==0){
        
    }
    else{

    }
}
*/