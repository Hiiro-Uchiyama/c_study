/*
曜日を次の曜日または前の曜日に更新する関数を作成せよ。
*/


#include <stdio.h>
#include <time.h>

void decDayOfTheWeek(struct tm *t_st){
	//変数の宣言
	if (t_st->tm_wday == 0){
		t_st->tm_wday = t_st->tm_wday + 6;
	}
	else{
        t_st->tm_wday = t_st->tm_wday - 1;
	}
}

void incDayOfTheWeek(struct tm *t_st){
	//変数の宣言
	if (t_st->tm_wday == 6){
		t_st->tm_wday = t_st->tm_wday - 6;
	}
	else{
		t_st->tm_wday = t_st->tm_wday + 1;
	}
}

int main(void){
	time_t timer;
	struct tm *t_st;
	char *wday[] = {"日", "月", "火", "水", "木", "金", "土"};
	time(&timer);
	//現在時刻を取得
	//最初の曜日
	t_st = localtime(&timer);
	printf("曜日: %s\n", wday[t_st->tm_wday]);
	//前の日にする
	decDayOfTheWeek(t_st);
	printf("曜日: %s\n", wday[t_st->tm_wday]);
	//前の日にした後に次の日にする
	incDayOfTheWeek(t_st);
	printf("曜日: %s\n", wday[t_st->tm_wday]);
}


/*
構造体を渡すプログラムしか思い浮かばなかった。
ポインタはt_stで使っているからいいかなと思った。
提示された課題を満たすプログラムを思いつかなかった。

曜日: 月
曜日: 日
曜日: 月
*/