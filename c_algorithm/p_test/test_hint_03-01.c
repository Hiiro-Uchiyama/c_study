
#include <stdio.h>
 
int main(void) {
           FILE* fp;
 
           int sum = 0;
           int cnt = 0;
           int t, i;
 
           fp = fopen("data.txt", "r");
           if (fp == NULL) {
                      printf("Failed to open data.txt. \n");
 
                      return -1;
           }
 
           while (fscanf(fp, "%d", &t) == 1) {
                      sum += t;
                      cnt++;
           }
 
           fclose(fp);
           printf("合計は%dで平均は%.2fです。\n", sum, (double)sum / cnt);
 
           return 0;
}
 
/*
合計は741で平均は148.20です。
*/