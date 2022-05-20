#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int yourChoice;
    int CompChoice;
    srand((unsigned int) time (0)); //現在時刻をもとにランダム関数を作る
    //自分の手を入力する
    do{
        printf("あなたの手を入力して下さい。(0: グー, 1: チョキ, 2: パー;)");
        scanf("%d", &yourChoice);
    }
    while(yourChoice < 0 || yourChoice > 2);
    //CompChoiceに0〜2の値を代入する
    CompChoice = rand() % 3;//ランダムな値を で割ってあまりを求める
    //コンピュータの手を表示する
    printf("コンピュータの手:");
    switch (CompChoice){
    case 0:
        printf("グー\n");
        break;
    case 1:
        printf("チョキ\n");
        break;
    case 2:
        printf("パー\n");
        break;
    }
    //結果の表示
    if(yourChoice == CompChoice){
        printf("あいこでした。");
    }
    else if((yourChoice==1 && CompChoice==2) || (yourChoice==2 && CompChoice==0) || (yourChoice==0 && CompChoice==1)){
        printf("あなたの勝ちです。");
    }
    else {
        printf("あなたの負けです。");
    }
    return 0;
}