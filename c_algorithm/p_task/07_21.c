/*
右に示す線形リストに含まれるノードのなかでメンバnameが大文字から始まるノードの個数を数えて返す関数count_cap()を作成せよ．
関数の再帰呼び出しを用いてもよい（加点）．
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct node{
    char name[20];
    int score;
    struct node *next;
};
struct node *root;

void count_cap(struct node *cur, int *count){
    if (cur == NULL){
        return;
    }
    //一文字目が大文字かどうか判定する
    //小文字でないなら0を返す
    if (islower(cur->name[0]) == 0){
        *count += 1;
    }
    else{
        ;
    }
    count_cap(cur->next, count);
}

int main(void){
    int count = 0;
    int *counter;
    counter = &count;
    struct node all[4] = {
        { "Alice", 49, NULL },
        { "chris", 91, NULL },
        { "Dev", 82, NULL },
        { "eliza", 77, NULL }
    };
    root = &all[0];
    all[0].next = &all[1];
    all[1].next = &all[2];
    all[2].next = &all[3];
    //関数の呼び出し
    count_cap(root, counter);
    //大文字のノードの個数
    printf("%d\n", *counter);
    return 0;
}


/*
2
*/