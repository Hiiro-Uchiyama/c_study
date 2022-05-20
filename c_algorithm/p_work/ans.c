/*
以下のような構造体player（の値またはポインタ）を引数として受け取り，
メンバnameの3文字目の文字を返す関数get3rd()を作成せよ．
なお，メンバnameが3文字よりも短い場合は，NULLを返すようにせよ．
struct player {
   char name[20];
              int score;
};
また，get3rdを使って，構造体playerの配列allのなかで，
メンバnameの3文字目が’r’となる要素のnameをすべて標準出力に出力する
main関数を作成せよ．
           struct player all[] = {
                      {"Taro", 100},
                      {"Jiro", 200},
                      {"Tako", 300}
           };
*/

#include <stdio.h>
#include <string.h>
 
struct player {
           char name[20];
           int score;
};
 
char get3rd(struct player p) {
           if (strlen(p.name) < 3) {
                      return '\0';
           }
           return p.name[2];
}

int main(void) {
           int i;
           struct player all[] = {
                      {"Taro", 100},
                      {"Jiro", 200},
                      {"Tako", 300}
           };   
           char ret;
           for (i = 0; i < 3; i++) {
                      ret = get3rd(all[i]);
                      if (ret == 'r') {
                                  printf("%s \n", all[i].name);
                      }
           }
           return 0;
}

/*
Taro
Jiro
*/