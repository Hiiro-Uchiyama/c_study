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

	//ƒtƒ@ƒCƒ‹‚©‚ç”’l‚ğ“Ç‚İæ‚é
	while (fscanf(fp, "%d", &t) == 1) {
		
		if (t % 2 == 1) {
			even[count1] = t;
			printf("%d:even‚ÉŠi”[\n", even[count1]);
			count1++;
		}
		else {
			odd[count2] = t;
			printf("%d:odd‚ÉŠi”[\n", odd[count2]);
			count2++;
		}
	}

	fclose(fp);

	return 0;
}

/*
43:even‚ÉŠi”[
78:odd‚ÉŠi”[
1823:even‚ÉŠi”[
328753:even‚ÉŠi”[
174:odd‚ÉŠi”[
438:odd‚ÉŠi”[
82752:odd‚ÉŠi”[
1274892:odd‚ÉŠi”[
348:odd‚ÉŠi”[
47387:even‚ÉŠi”[

*/