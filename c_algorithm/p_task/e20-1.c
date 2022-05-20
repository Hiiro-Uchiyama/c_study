/*
木構造を表示する関数printTree()の作成
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* 木構造２つのポインタを持つ */
struct node{
    char name[20];
    int point;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

void printTree(struct node *cur, int n){
    if (cur == NULL){
        return;
    }
    printTree(cur->left, n + 1);
    if (n == 1){
        printf("Name: %s, Point: %d, first\n", cur->name, cur->point);
    }
    if (cur->right != NULL){
        printf("%*sName: %s, Point: %d, right\n", n, "",  cur->right->name, cur->right->point);
        printTree(cur->right, n + 1);
    }
    if (cur->left != NULL){
        printf("%*sName: %s, Point: %d, left\n", n, "", cur->left->name, cur->left->point);
        printTree(cur->left, n + 1);
    }
}

int main(void){
    struct node d = {"Djokovic", 10220, NULL, NULL};
    struct node n = {"Nadal", 9850, NULL, NULL};
    struct node t = {"Thiem", 7045, NULL, NULL};
    struct node f = {"Federer", 6630, NULL, NULL};
    struct node m = {"Medvedev", 5890, NULL, NULL};
    struct node z = {"Zverev", 3630, NULL, NULL};
    //先頭
    root = &d;
    d.left = &t;
    d.right = &n;
    n.right = &f;
    t.left = &m;
    t.right = &z;
    printTree(root, 1);
    return 0;
}


/*
実行結果
Name: Djokovic, Point: 10220, first
 Name: Nadal, Point: 9850, right
  Name: Federer, Point: 6630, right
 Name: Thiem, Point: 7045, left
  Name: Zverev, Point: 3630, right
  Name: Medvedev, Point: 5890, left
*/