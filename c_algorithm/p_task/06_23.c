/*--
整数型のメンバーidと整数型のメンバーscoreを含む構造体を宣言せよ構造体recordを宣言しろ
構造体recordの配列playersをmain関数の中で作れ
要素数は3とすること
main関数においてplayersの第1要素のメンバーidに623を第2要素に624を三つ目に625を代入せよ
playersの第1から第三要素メンバーscoreに0から10までの乱数を代入すること
--*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*-- 構造体の宣言 --*/
struct record {
    int id;
    int score;
};

/*-- main関数 --*/
int main(void){
    //乱数の設定
    //int randam;
    srand(time(NULL));
    //構造体の指定
    int i = 0;
    int n = 623;
    int m = 0;
	struct record players[] = {
        {0, 0},
        {0, 0},
        {0, 0}
    };
    // idに任意の数値を代入
    for (i = 0; i < 3; i++){
        players[i].id = n;
        n++;
        printf("%d\n", players[i].id);
    }
    for (m = 0; m < 3; m++){
        players[m].score = rand() % 10;
        printf("%d\n", players[m].score);
    }
    return 0;
}


/*--
1回目
623
624
625
8
8
8
改善後
623
624
625
3
1
10
--*/