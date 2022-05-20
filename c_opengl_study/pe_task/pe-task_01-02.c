#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

int main(){

    time_t timer = time(NULL);
    struct tm *t;
    int hour;
    int min;
    
    t = localtime(&timer);
    hour = t->tm_hour;
    min = t->tm_min;

    printf("現在%d時%d分です。\n", hour, min);

    if (hour < 12){
        printf("毎日一限で睡眠時間が限界だよね。わかる。\n");
    }
    if (12 < hour && hour < 18){
        printf("最近やけに課題多いよね。\n");
    }
    if (hour == 2){
        printf("寝ろ。死ぬぞ。\n");
    }
    if (hour == 15){
        printf("おやつ食べる暇もないなあ。\n");
    }
    else{
        printf("お菓子食べたい。\n");
    }
    return 0;
}
