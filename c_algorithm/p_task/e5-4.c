/*
演習5-4: 配列をコピーする関数 copyArray を作成せよ. 以下の条件を満たすこと.
関数 copyArray が満たすべき条件: double型の配列(の先頭のアドレス)およびその要
素数を，引数 ar および n として受け取る. n個の要素を持つ別の配列 newAr(のメモリ領域)を
動的に確保する.
ar の全ての要素を newAr にコピーした上で，newA
r の先頭のアドレスを返す. main関数が満たすべき条件:
copyArray関数を呼び出して，その戻り値をポイン タ z に代入し，z を配列として利用できることを確 認するプログラムとせよ.
*/


#include <stdio.h>
#include <stdlib.h>

double *copyArray(double ar[], int n){
	//変数の宣言
	double *newAr;
    int i = 0;
    newAr = (double *)malloc(sizeof(double) * n);
    if (newAr == NULL){
        printf("Not enough memory.");
        exit("EXIT_FAILURE");
    }
    for (i = 0; i <= n; i++){
        newAr[i] = ar[i];
    }
    return newAr;
}

int main(void){
    //配列の宣言
	double *z;
    double array[4] = {1.2, 2.2, 3.2, 4.2};
    int Length = 4;
    int m = 0;
    z = copyArray(array, Length);
    for (m = 0; m < Length; m++){
        printf("%0.2f\n", z[m]);
    }
    return 0;
}


/*
ちなみにmalloc関数では(double *)malloc(sizeof(int) * n)とすると
1.20
2.20
0.00
0.00
となっていたので興味深かった

(double *)malloc(sizeof(double) * n)
正常に実行されていることが分かる
1.20
2.20
3.20
4.20
*/