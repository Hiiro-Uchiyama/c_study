/*
文字列sの中に、文字列caが含まれている個数を返す関数を作成せよ。
strcmp関数を用いること。
*/


#include <stdio.h>
#include <string.h>

int str_chnum(const char* s){
	int i = 0;
	int num = 0;
	while (i < 13) {
		if (strncmp("c", &s[i], 1) == 0) {
			if (strncmp("a", &s[i + 1], 1) == 0) {
				num++;
			}
		}
		i++;
	}
	return num;
}

int main(void){
	const char s[] = "abcabcabcabc";
	printf("caの個数: %d\n", str_chnum(s));
	return 0;
}


/*
caの個数: 3
*/