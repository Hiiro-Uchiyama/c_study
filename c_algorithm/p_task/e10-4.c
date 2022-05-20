/*--==
演習10-7: p281演習10-4のset_idxと同様の引数を持ち、配列vのなかに含まれる要素を全てを出力する関数printArrayを作成せよ。
ただし、関数printArrayの中では演算子[]を用いてはならない
printArrayの動作を確認すること
--==*/


#include <stdio.h>

/*-- 関数 引数 int型ポインタ --*/
void printArray(int *v, int n){
    //nは要素の数であるとしておこ
    int i = 0;
    for (i = 0; i < n; i++){
        //配列のポインタ版みたいな表記
        printf("%d\n", *(v + i));
    }
}

/*-- main関数 --*/
int main(void){
    //変数の宣言
    int number = 10;
    int Array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *d;
    //ポインタの指定
    d = &Array;
    //特に断りがなかった気がするので配列の中身はあらかじめ決めてみた
    printArray(d, number);
    return 0;
}


/*--==
1
2
3
4
5
6
7
8
9
10
==--*/