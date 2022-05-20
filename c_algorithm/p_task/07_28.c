/*
下記のような構造体nodeにより構成される双方向リストを用いるプログラムにおいて，
任意のノード(先頭とは限らない)を与えられたときに，リスト全体を先頭から順に出力する関数 printList()を作 成せよ.
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct node {
        char name[20];
        int wins;
        struct node *next;
        struct node *prev;
};

/*
printList の引数は，構造体nodeへのポインタに加えて，
第2引数としてmodeを受け取る. modeが-1の場合は線形リストを先頭に遡り，
modeが1の場合は，線形リストを後ろに辿りながら表示を行うようにする.
データの個数は未知であるとする。
*/
void printList(struct node *cur, int mode){
    if (cur == NULL){
        return;
    }
    if (mode == 1){
        printf("%s: %d\n", cur->name, cur->wins);
        printList(cur->next, mode);
    }
    else if (mode == -1) {
        printList(cur->prev, mode);
        if (cur->prev == NULL) {
            printf("%s: %d\n", cur->name, cur->wins);
            return;
        }
    }
}

int main(void) {
struct node all[] = {
    {"Federer", 16, NULL, NULL}, {"Nadal", 13, NULL, NULL},
    {"Dokovic", 13, NULL, NULL}, {"Murray", 9, NULL, NULL},
    {"Ferrer", 8, NULL, NULL}, {"del_Potro", 7, NULL, NULL},
    {"Nishikori", 6, NULL, NULL}
};
int i;
// 双方向リストを作成
for (i = 0; i < 6; i++) {
    all[i].next = &all[i + 1];
    all[i + 1].prev = &all[i];
}
printList(&all[3], -1);
return 0;
}


/*
9:19
mode == 1
Murray: 9
Ferrer: 8
del_Potro: 7
Nishikori: 6
mode == -1
Murray: 9
Dokovic: 13
Nadal: 13
Federer: 16
*/