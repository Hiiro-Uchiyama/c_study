/*
下記のような構造体 node により構成される双方向リストを用いるプログラムにおいて，任意のノ
ード（先頭とは限らない）を与えられたときに，リスト全体を先頭から順に出力する関数 printList()を作
成せよ．
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct node {
    char name[20];
    int wins;
    struct node* next;
    struct node* prev;
};

void printList(struct node* cur, int mode) {
    if (mode == -1) {
        //先頭のノードでないとき
        if (cur->prev != NULL) {
                    printList(cur->prev, mode);
        }
        //先頭のノードに到達したとき
        else {
                    mode = 1;
        }
    }
    if (mode == 1) {
        printf("%s: %d\n", cur->name, cur->wins);
        if (cur->next != NULL) {
                    printList(cur->next, mode);
        }
    }
}

int main(void) {
    struct node all[] = {
                {"Federer", 16, NULL, NULL},
                {"Nadal", 13, NULL, NULL},
                {"Dokovic", 13, NULL, NULL},
                {"Murray", 9, NULL, NULL},
                {"Ferrer", 8, NULL, NULL},
                {"del_Potro", 7, NULL, NULL},
                {"Nishikori", 6, NULL, NULL}
    };
    int i;
    // 双方向リストを作成
    for (i = 0; i < 6; i++) {
                all[i].next = &all[i + 1]; all[i + 1].prev = &all[i];
    }
    printList(&all[3], -1);
    return 0;
}

/*
Federer: 16
Nadal: 13
Dokovic: 13
Murray: 9
Ferrer: 8
del_Potro: 7
Nishikori: 6
*/