/*
ファイルから読み出したデータを線形リストに追加する
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char name[20];
    int point;
    struct node *next;
};
struct node *root = NULL;

void printList(struct node *cur){
    if (cur == NULL){
        return;
    }
    printf("Name: %s, Point: %d\n", cur->name, cur->point);
    printList(cur->next);
}

void add_data(struct node *new){
    struct node *cur = root;
    if (root == NULL){
        root = new;
        return;
    }
    while (cur->next != NULL){
        cur = cur->next;
    }
    cur->next = new;
}

int main(void){
    int point;
    char buffer[25] = {};
    struct node *new;
    FILE *fp;
    fp = fopen("data.txt","r");
    if (fp == NULL){
        printf("Can't Open Your File");
        return -1;
    }
    while (fscanf(fp, "%s %d", buffer, &point) == 2){
        new = (struct node *)malloc(sizeof(struct node));
        strcpy(new->name, buffer);
        new->point = point;
        new->next = NULL;
        add_data(new);
    }
    printList(root);
    fclose(fp);
    return 0;
}


/*
Name: Federer, Point: 6630
Name: Nadal, Point: 9850
Name: Djokovic, Point: 10220
Name: Zverev, Point: 3630
Name: Thiem, Point: 7045
Name: Medvedev, Point: 5890
*/
