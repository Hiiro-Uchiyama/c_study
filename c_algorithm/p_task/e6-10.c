/*
演習6-10:
<教科書p153の問題文>
要素数がnであるint形の配列vの要素の並びを反転する関数を作成せよ．
void intary_rcpy(int v1[], const int v2[], int n){}
<講義資料の問題文>
配列v1とv2を2×2の⾏列(2次元配列)に変更し， v2の逆⾏列を計算してv1に格納する関数calcInvMatrix( )を作成せよ．
・引数は自分で考えること
・main関数も作成すること
・逆⾏列が存在しない場合はv1の全ての要素を0にすること
・calcInvMatrixでは，逆⾏列を求める以外の処理を⾏っ てはならない（標準出⼒への出⼒など）．
*/


#include <stdio.h>



//関数の作成
int v__1[2][2];
void calcInMatrix(int v2[2][2]){
    int i = 0;
    int j = 0;
    for (i = 0; i < 2; i++){
        for (j = 1; 0 <= j && j <= 1; j--){
            v__1[i][j] = v2[j][i];
        }
    }
}

//main関数
int main(void){
    
    //配列の定義
    int v_2[2][2] = {{11,23},
                     {12,24}};

    int n = 0;
    int m = 0;

    calcInMatrix(v_2);
    
    for (n = 0; n < 2; n++){
        for (m = 0; m < 2; m++){
            printf("%d ", v__1[n][m]);
        }
        printf("\n");
    }
    return 0;
}



/*
11 12 
23 24
*/
