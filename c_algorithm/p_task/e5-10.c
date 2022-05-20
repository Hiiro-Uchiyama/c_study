/*
演習5-10:
2つの行列をファイルmat1.txt, mat2.txtから読み込むようにプログラムを変更せよ。
*/


#include <stdio.h>


int main(void) {
	FILE* fp_1;
	FILE* fp_2;

	int i=0;
	int j=0;
	int k=0;
	int mat1[4][3];
	int mat2[3][4];
	int mat[4][4] = {};



    //ファイルの読み込み処理
	fp_1 = fopen("mat1.txt", "r");
	fp_2 = fopen("mat2.txt", "r");

	if (fp_1 == NULL) {
		printf("Failed to open mat1.txt. \n");
		return -1;
	}
	if (fp_2 == NULL) {
		printf("Failed to open mat2.txt. \n");
		return -1;
	}



	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			fscanf(fp_1, "%d", &mat1[i][j]);			
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			fscanf(fp_2, "%d", &mat2[i][j]);
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 3; k++) {
				mat[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	printf("mat1\n");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", mat[i][j]);
			if (j == 3)
				printf("\n");
		}
	}

	fclose(fp_1);
	fclose(fp_2);

	return 0;
}


/*

*/