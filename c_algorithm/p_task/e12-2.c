/*
演習12-2: List12-3のプログラムにおいて，静的に宣言さ れた構造体変数takaoのかわりに，student構造体を要素と して持つ配列grpを動的に宣言するプログラムを作成せよ.
構造体studentのメンバ変数nameは削除すること. (まだこの授業で文字列を取り上げていないため)
配列grpの要素数は3とすること.
配列grpの各要素のメンバ変数に，適当な値を代入する こと.
上記の代入がうまくいったことを，以下の様なfor文で 確認すること.
for(i = 0; i < ... ){
      printf(“...”, grp[i].id);
*/


#include <stdio.h>
#include <stdlib.h>
#define NAME_LEN 64

struct student {
    char id;
    int height;
    float weight;
};

int main(void){
    //構造体の宣言
	struct student *grp;
    grp = (struct student *)malloc(sizeof(struct student) * 3);
    int i;
    for (i = 0; i < 3; i++){
        grp[i].id = i * i * i * i;
        grp[i].height = 5 ^ i;
        grp[i].weight = 3.1415 * (i ^ 2);
        printf("id = %d\n", grp[i].id);
        printf("heigght = %d\n", grp[i].height);
        printf("weight = %f\n", grp[i].weight);
    };
    return 0;
}


/*
適当に式を書いているため非常にわかりにくいがおそらく正常に実行できていると考えられる
最後のweightがゼロになるのは怪しい気がする
表示範囲を越えたのかも知れない
id = 0
heigght = 5
weight = 6.283000
id = 1
heigght = 4
weight = 9.424500
id = 16
heigght = 7
weight = 0.000000
*/