/*
2021/7/7日
文字列とポインタ
小テスト問題
与えられた文字列に含まれる’a’，’i’，’u’，’e’，’o’の文字全てを，’x’に書き換える関数 changer()を作成せよ． 
　任意の長さの文字列に対応できること．
　添字演算子[]を用いずに作成すること．
for文を使わずに作成すること．
また，構造体playerの配列allにおいて，すべての要素のメンバnameに関数changerを適用するmain関数を作成せよ．
struct player {
    char name[20];
    int score;
};
struct player all[] = {
    {“Nobita", 100},
    {“Doraemon", 200},
    {“Dekisugi", 300}
};
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*-- 関数 --*/
void changer(char *str){
    /*-- strのうちaiueoの時にxを代入する --*/
    while (*str){
        int i = 0;
        while(i == 0){
            if ('a' == *str || 'A' == *str){
                *str++ = 'x';
            }
            else if ('i' == *str || 'I' == *str){
                *str++ = 'x';
            }
            else if ('u' == *str || 'U' == *str){
                *str++ = 'x';
            }
            else if ('e' == *str || 'E' == *str){
                *str++ = 'x';
            }
            else if ('o' == *str || 'O' == *str){
                *str++ = 'x';
            }
            else {
                i = 1;
            }
        }
        *str++;
    }
    *str = '\0';
}

struct player {
    char name[20];
    int score;
};

/*-- main関数 --*/
int main(void){
    /*-- 構造体宣言 --*/
    struct player all[] = {
    {"Nobita", 100},
    {"Doraemon", 200},
    {"Dekisugi", 300}
    };
    /*-- 変数の宣言 --*/
    int n = 0;
    /*-- 処理 --*/
    while (n < 3){
        changer((all + n)->name);
        printf("%s\n", (all + n)->name);
        n++;
    }
    /*-- return --*/
    return 0;
}


/*
実行結果
Nxbxtx
Dxrxxmxn
Dxkxsxgx
*/