#include <stdio.h>

int getQuarter(int month){
    if (1 <= month && month <= 3){
        return 1;
    }
    else if(4 <= month && month <= 6){
        return 2;
    }
    else if(7 <= month && month <= 9){
        return 3;
    }
    else if(10 <= month && month <= 12){
        return 4;
    }
    else{
        return printf("入力が正しくないようです。");;
    }
}

int main(){

    int Month = 0;

    printf("1から12の月から一つ入力して下さい。");
    scanf("%d", &Month);
    printf("getQuarter動作確認: %d\n", getQuarter(Month));
 
}

/*--
1から12の数値から一つ入力して下さい。3
getQuarter動作確認: 1
--*/