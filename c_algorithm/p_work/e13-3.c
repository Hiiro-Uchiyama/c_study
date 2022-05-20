#include <stdio.h>

int main(void) {
	FILE* fp;

	int t;
	int count1 = 0;
	int count2 = 0;

	int even[50] = {0};
	int odd[50] = {0};

	fp = fopen("num.txt", "r");
	if (fp == NULL) {
		printf("Failed to open num.txt. \n");

		return -1;
	}

	//�t�@�C�����琔�l��ǂݎ��
	while (fscanf(fp, "%d", &t) == 1) {
		
		if (t % 2 == 1) {
			even[count1] = t;
			printf("%d:even�Ɋi�[\n", even[count1]);
			count1++;
		}
		else {
			odd[count2] = t;
			printf("%d:odd�Ɋi�[\n", odd[count2]);
			count2++;
		}
	}

	fclose(fp);

	return 0;
}

/*
43:even�Ɋi�[
78:odd�Ɋi�[
1823:even�Ɋi�[
328753:even�Ɋi�[
174:odd�Ɋi�[
438:odd�Ɋi�[
82752:odd�Ɋi�[
1274892:odd�Ɋi�[
348:odd�Ɋi�[
47387:even�Ɋi�[

*/