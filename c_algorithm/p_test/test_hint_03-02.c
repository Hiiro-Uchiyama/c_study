#include <stdio.h>
 
int main(void) {
           FILE* fp;
           FILE* fpr;
 
           int i;
 
           fp = fopen("odd.txt", "w");
           if (fp == NULL) {
                      printf("Failed to open odd.txt. \n");
                     
                      return -1;
           }
           fpr = fopen("even.txt", "w");
           if (fpr == NULL) {
                      printf("Failed to open even.txt. \n");
 
                      return -1;
           }
 
           for (i = 0; i <= 10; i++) {
                      if (i % 2 == 1) {
                                  fprintf(fp, "%d\n", i);
                      }
                      if (i % 2 == 0) {
                                  fprintf(fpr, "%d\n", i);
                      }
           }
 
           fclose(fp);
           fclose(fpr);
 
           return 0;
}
 
/*
C:\Users\aya\Downloads\プログラミング言語Ⅰ演習\Project8\Debug\Project8.exe (プロセス 11808) は、コード 0 で終了しました。
*/
 
/*
even.txt
 
0
2
4
6
8
10
*/
 
/*
odd.txt
 
1
3
5
7
9
*/