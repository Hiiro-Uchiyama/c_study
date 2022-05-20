/*
演習6-10:
配列vの要素のうち偶数の値を持つ要素を全てdata.txtに書き出す関数writeAllEven()を作成せよ。main関数もかけ。
*/


#include <stdio.h>



//関数の作成
void writeAllEven(int v_[5], int n){
    int i = 0;
    FILE *fp;
    fp = fopen("data.txt", "w");
    for (i = 0; i < n; i++){
        //条件分岐
        if (v_[i] % 2 == 0){
            fprintf(fp, "%d\n", v_[i]); 
        }
    }
    fclose(fp);
}

//main関数
int main(void){
    
    //変数の定義
    ////nの値は要素の数やで。
    //これって多重配列じゃなくていいの?
    int n = 5;
    int v[5] = {1, 2, 3, 4, 5};

    writeAllEven(v, n);
    
    return 0;
}



/*
2
4
*/
