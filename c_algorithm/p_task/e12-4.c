/*
演習12-4: List 12-4を書き換えて，構造体変数sanakaの代わりに，以下の構造体の配列membersに含まれる3人の身長と体重を(関数hirokoを呼び出すことで)変更するプログラムを作成せよ.main関数のみを変更すればよい.
struct student members[] = { {“Tom”, 153, 57.9, 200 }, {“John”, 179, 73.2, 200 }, {“Bob”, 172, 91.4, 200 }};
main関数のみを変更すること. for文を使って関数hirokoを繰り返し呼び出すこと.
*/


#include <stdio.h>
#include <stdlib.h>
#define NAME_LEN 64

struct student {
    char name[NAME_LEN];
    int height;
    float weight;
    long schools;
};

void hiroko(struct student *std){
    if ((*std).height < 200){
        (*std).height = 200;
    }
    if ((*std).weight > 50){
        (*std).weight = 50;
    }
}

int main(void){
    //構造体の宣言
    int i = 0;
	struct student members[] = {
        {"Tom", 153, 57.9, 200},
        {"John", 179, 73.2, 200},
        {"Bob", 172, 91.4, 200}
    };
    for (i = 0; i < 3; i++){
        hiroko(&members[i]);
        printf("height = %d, weight = %f\n", members[i].height, members[i].weight);
    }
    return 0;
}


/*
正常にプログラムが実行されていることがわかる
height = 200, weight = 50.000000
height = 200, weight = 50.000000
height = 200, weight = 50.000000
*/