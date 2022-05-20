/*
文字列sのなかに文字c1,c2が含まれている個数を返す関数を作成すること
なおstrcmpやstrncmp関数を使用しない
動作を確認するmain関数
また添字演算子[]を使用しないこと
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int str_chnum(const char *str, char c1, char c2){
    // 変数の宣言
    int lenght;
    int i = 0;
    int num = 0;
    lenght = strlen(str);
    while (i < lenght){
        if (*(str + i) == c1){
            if (*(str + (i + 1)) == c2){
                num++;
            }
        }
        i++;
    }
    return num;
}

int main(void){
    /*--変数の宣言--*/
    const char *str = "cdaafac1c2jii2c2";
    char c1 = 'd';
    char c2 = 'a';
    printf("strに含まれている任意の文字列の連続数は: %d\n", str_chnum(str, c1, c2));
}

size_t strlen(const char *s){
    size_t len = 0;
    while (*s++){
        len++;
    }
    return len;
}


/*
strに含まれている任意の文字列の連続数は: 1
*/