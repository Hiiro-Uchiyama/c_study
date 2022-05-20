/*
文字列strないの全ての数字文字を削除する
削除した文字列を第2引数のstr2に代入すること
[]を使うな。
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void del_digit(const char *str, char *str2){
    while (*str){
        int i = 0;
        while(i == 0){
            if ('0' <= *str && *str <= '9'){
                *str++;
            }
            else {
                i = 1;
            }
        }
        *str2++ = *str++;
    }
    *str2 = '\0';
}

int main(void){
    /*--変数の宣言--*/
    const char *str = "cafa1121b123456789fdw3323iuvsv21";
    char *str2;
    printf("%s\n", str);
    del_digit(str, str2);
    printf("削除後の文字列は: %s\n", str2);
}


/*
cafa1121b123456789fdw3323iuvsv21
削除後の文字列は: cafabfdwiuvsv
*/