/*
配列を逆にして返す
*/


#include <stdio.h>

int printArRev(int after[], int num){
	//変数の宣言
	int i = 0;
    //デクリメントによって後ろから代入
	for (i = num - 1; i >= 0; i--){
		printf("%d,", after[i]);
	}
}

int main(void){

    //配列の宣言
	int n[5] = {12, 23, 34, 45, 56};

    //関数の呼び出し
    printArRev(n, 5);

	return 0;
}


/*
56,45,34,23,12,%
*/