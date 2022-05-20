/*
入力ファイルの内容を文字及び16進数で表示するプログラムを作成する
関数dumpとmain関数にて確認
*/

#include <stdio.h>

#define WIDTH 60
#define MASKCHR ','

void dump(char *filename, long from, long to){
    FILE *infile;
    int chr, pos = 0;
    long cnt = 0;
    char tblC[256], bufC[WIDTH + 1];
    char tblH[256], bufH[WIDTH + 1];
    char tblL[256], bufL[WIDTH + 1];
    char hex[] = "0123456789";
    for (chr = 0; chr <= 255; chr++){
        if((32 <= chr) && (chr <= 126)){
            tblC[chr] = chr;
        }
        else {
            tblC[chr] = MASKCHR;
        }
        //四ビットシフトはどう10進数に変換すればいいの
        tblH[chr] = hex[chr >> 4];
        tblL[chr] = hex[chr & 15];
    }
    bufC[WIDTH] = bufH[WIDTH] = bufL[WIDTH] = '\0';
    infile = fopen(filename, "rb");
    while (((chr = fgetc(infile)) != EOF) && ((to < 0) || (cnt <= to))){
          cnt++;
          if(cnt > from){
            bufC[pos] = tblC[chr];
            bufH[pos] = tblH[chr];
            bufL[pos] = tblL[chr];
            pos++;
            if(pos == WIDTH){
                printf("%10ld %s\n%12s%s\n12s%s\n\n", cnt - WIDTH, bufC, " ", bufH, " ", bufL);
                pos = 0;
            }
        }
    }
    if (pos > 0){
        bufC[pos] = bufH[pos] = bufL[pos] = '\0';            
        printf("%10ld %s\n%12s%s\n12s%s\n\n", cnt - pos, bufC, " ", bufH, " ", bufL);
    }
    if (chr == EOF){
        printf("END OF DATA ... %ld byte(s)\n", cnt - from);
    }
    else {
        printf("END OF DUMP ... %ld byte(s)\n", cnt - from);
    }
    fclose(infile);
}

int main(void){
    dump("06_23.c", 0L, -1L);
}