/*
以下のような構造体playerを構造体として受け取りメンバnameの3文字目の文字を返す
get3rd()を作成すること。
名前が3文字に満たない場合はNULLを返すこと。
get3rd()を使って構造体playerの配列allのなかでメンバnameの3文字目がrとなる要素のnameを全て出力するmain関数を作成すること。
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct player {
    char name[20];
    int score;
};

char *get3rd(struct player *all_){
    // 繰り返し
	int i = 0;
    // 3文字目を格納する
    char *num;
    // 使い方がおかしいかも知れない
    num = (char *)malloc(sizeof(char) * 32);
    for (i = 0; i < 3; i++){
        num[i] = all_[i].name[2];
    }
    return num;
}

int main(void){
    int m;
    int n;
    int s;
    char *str;
    struct player all[] = {
        {"Taro", 100},
        {"Jiro", 200},
        {"Tako", 300}
    };
    // 3文字目を返す
    str = get3rd(all);
    for (s = 0; s < 3; s++){
        printf("name: %c\n", str[s]);
    }
    // 3文字目がrである要素を返す
    while (m < 3) {
        if (all[m].name[2] == 0){
            printf("NULL\n");
        }
        else {
            if (strncmp("r", &all[m].name[2], 1) == 0) {
			printf("name: %s\n", all[m].name);
		    }
            else {
                ;
            }
        }
		m++;
	}
	return 0;
}


/*
name: r
name: r
name: k
name: Taro
name: Jiro
*/