#include <stdio.h>

int main(void) {
	int n1, n2, n3, n;
	int max_tmp, min_tmp;

	printf("３つ文字を打ち込め");
	scanf("%d\n", &n1);
    scanf("%d\n", &n2);
    scanf("%d\n", &n3);

	if(n1 > n2){
		max_tmp = n1;
		min_tmp = n2;
	}
	else {
		min_tmp = n1;
		max_tmp = n2;
	}

	if (min_tmp > n3) {
		n = max_tmp - n3;
		printf("%d", n);
	}
	else {
		if (max_tmp > n3) {
			n = max_tmp - min_tmp;
			printf("%d", n);
		}
		else {
			n = n3 - min_tmp;
			printf("%d", n);
		}
	}

	return 0;
}