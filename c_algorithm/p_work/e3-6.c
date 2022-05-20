#include <stdio.h>

int main(void) {
	int n1, n2, n3, n;
	int max, min;

	printf("３つ文字を打ち込め");
	scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

	if(n1 > n2){
		max = n1;
		min = n2;
	}
	else {
		min = n1;
		max = n2;
	}

	if (min > n3) {
		n = max - n3;
		printf("最大と最小の差は%d\n", n);
	}
	else {
		if (max > n3) {
			n = max - min;
			printf("最大と最小の差は%d\n", n);
		}
		else {
			n = n3 - min;
			printf("最大と最小の差は%d\n", n);
		}
	}

	return 0;
}

/*
３つ文字を打ち込め1
4
5
最大と最小の差は4
*/