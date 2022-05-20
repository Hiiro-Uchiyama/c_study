#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    /*--じゃんけんゲームというものを作っていきます--*/
    /*--rand()関数の乱数の生成を増やす--*/
    srand((unsigned int)time(NULL));
    /*--変数の宣言--*/
    int i = 0;
    int user = 0;
    /*--コンピュータの手--*/
    int com = rand() % 3 + 1;
    /*--ユーザからの入力を受け付ける。じゃんけんをする気のないやつは強制的に負けになる。--*/
    for (i = 0; i < 5; i++){
        printf("君の手を決めよう。1がグーで2がチョキで0がパーです。数値を入力して下さい。\n");
        scanf("%d", &user);
        printf("%d\n", user);
        if(user==1 || user==2 || user==3){
            break;
        }
        if(i == 2){
            printf("お前ジャンケンする気ないだろ。帰れ。");
            break;
        }
    }
    /*--コンピュータの選択した手を表示--*/
    switch (com){
    case 1:
        printf("comはグーを出しました。\n");
        break;
    case 2:
        printf("comはチョキを出しました。\n");
        break;
    case 3:
        printf("comはパーを出しました。\n");
        break;
    default:
        printf("何か問題が発生したようです。\n");
    }
    /*--勝利判断--*/
    if(com == user){
        printf("aikoです。\n");
    }
    else if(com==1 && user==3 || com==2 && user==1 || com==3 && user==2){
        printf("あなたの勝ちです。\n");
    }
    else{
        printf("あなたの負けです。罰金として500円支払っていただきます。\n");
    }
    return 0;
}
