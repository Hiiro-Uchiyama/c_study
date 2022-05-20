/*
与えられた文字列に含まれる’a’を，’x’，’y’および’z’に変更したときにできる文字列すべてを表示する関数 print_repを作成せよ．
 - 関数の再帰呼び出しを使用すること．
 - 文字列に含まれるすべての’a’の文字を置き換えること．
 - 可能な文字列をすべて出力すること．
 - 例: 引数として受け取る文字列が“kasa”の場合，出力する文字列は   “kxsx”，”kxsy”,“kxsz”,“kysx”,”kysy”,”kysz”,”kzsx”,”kzsy”,”kzsz” の9種類となる．
 - print_repのなかで，標準出力に出力を行ってよい．
右のmain関数を実行し，その結果をコメント形式でソースコードの末尾に貼り付けよ．
int main(void) {
    char s[5];
    strcpy(s, "kasa");
    print_rep(引数);
    return 0;
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*-- 関数 --*/
void print_rep(char *a, int n){
    //再起呼び出しによって文字列を参照するのですが。
    if (n == 0){
        printf("%s\n", a);
        return;
    }
    if ('a' == a[n]){
        a[n] = 'x';
        print_rep(a, n - 1);
        a[n] = 'y';
        print_rep(a, n - 1);
        a[n] = 'z';
        print_rep(a, n - 1);
        a[n] = 'a';
    }
    else {
        print_rep(a, n - 1);
    }
}

/*-- main関数 --*/
int main(void){
    //変数の宣言
    char s[5];
    //文字列の長さから注目文字について試行する
    int n;
    strcpy(s, "kasa");
    n = strlen(s);
    print_rep(s, n);
    return 0;
}


/*
実行結果
kxsx
kysx
kzsx
kxsy
kysy
kzsy
kxsz
kysz
kzsz
*/