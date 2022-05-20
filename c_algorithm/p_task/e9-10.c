/*
文字列中に含まれる数字ではなくアルファベットを削除すること
*/


#include <stdio.h>
#include <ctype.h>

void del_digit(char *str){
    char *p = str;
    char *p_= str;
    while (*p_){
          // 文字列をずらす
          // 数字ではないときに該当文字を削除する
          while(isdigit(*p_) == 0){
                *p_++;
          }
          *p++ = *p_++;
    }
    *p = '\0';
}

int main(void){
    char str[100];
    printf("英数字列を入力して下さい: ");
    scanf("%s", str);
    del_digit(str);
    printf("数字を取り除いた文字列は: %s\n", str);
    return 0;
}


/*
英数字列を入力して下さい: daga23
数字を取り除いた文字列は: 23
*/