/*
ソートする整数を4つにしたsort関数を作成しましょう。
*/


#include <stdio.h>

void swap(int *p1, int *p2){
	//変数の宣言
	int temp;
	if (*p1 >= *p2){
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	else{

	}
}

void sort4(int *n1, int *n2, int *n3, int *n4){
	//昇順に並び替える
	//めんどくさいからひたすらに関数を呼び出す
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
	swap(n1, n2);
	swap(n2, n3);
	swap(n3, n4);
}

int main(void){
	//変数
	int na;
	int nb;
	int nc;
	int nd;

    //配列の宣言
	puts("4つの整数を入力して下さい。");
	printf("整数A: "); scanf("%d", &na);
	printf("整数B: "); scanf("%d", &nb);
	printf("整数C: "); scanf("%d", &nc);
	printf("整数D: "); scanf("%d", &nd);

    //sort4を使用
	sort4(&na, &nb, &nc, &nd);

	puts("整数を昇順にソートしました。");
	printf("整数Aは%d\n", na);
	printf("整数Bは%d\n", nb);
	printf("整数Cは%d\n", nc);
	printf("整数Dは%d\n", nd);

	return 0;
}


/*
整数Aは1
整数Bは322
整数Cは432
整数Dは456
*/