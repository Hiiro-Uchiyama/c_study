#include <stdio.h>

int printArRev(int d[], int num) {
	int i;

	for (i = num - 1; i >= 0; i--) {
		printf("%d\n", d[i]);
	}

}


int main(void) {

	int ar[] = {1, 2, 3, 4, 5};

    printArRev(ar, 5);

	return 0;
}

/*
5
4
3
2
1

*/