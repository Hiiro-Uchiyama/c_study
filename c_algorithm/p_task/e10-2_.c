/*
曜日を次の曜日または前の曜日に更新する関数を作成せよ。
*/


#include <stdio.h>

void decDayOfTheWeek(int *d){
    if (*d == 0){
        *d = 6;
    }
    else{
        *d = *d - 1;
    }
}

void incDayOfTheWeek(int *d){
    if (*d == 6){
        *d = 0;
    }
    else{
        *d = *d + 1;
    }
}

int main(void){
    int day[7] = {0, 1, 2, 3, 4, 5, 6};
    char *days[] = { "日", "月", "火", "水", "木", "金", "土" };
    int *Day;
    int WhatDay;
    Day = &WhatDay;
    //最初の曜日
    printf("現在の曜日を0から6で教えて下さい。0が日曜日で6が土曜日です。\n");
    scanf("%d", &WhatDay);
    printf("曜日: %d\n", day[*Day]);
    printf("曜日: %s\n", days[day[*Day]]);
    //前の日にする
    decDayOfTheWeek(Day);
    printf("前の曜日: %d\n", day[*Day]);
    printf("曜日: %s\n", days[day[*Day]]);
    //次の日にする
    incDayOfTheWeek(Day);
    printf("次の曜日: %d\n", day[*Day]);
    printf("曜日: %s\n", days[day[*Day]]);
    return 0;
}


/*

*/