#include<stdio.h>
#include<conio.h>

struct time{
	int hour;
	int minute;
	int second;
};

void display(time t){
	printf("\%d:%d:%d",t.hour,t.minute,t.second);
}

time operator + (time t1, time t2){
	time t;
	int s = t1.second + t2.second;
	t.second = s%60;
	if(s>=60) (t2.minute)++;
	int m = t1.minute + t2.minute;
	t.minute = m%60;
	if(m>=60) (t2.hour)++;
	t.hour = (t1.hour + t2.hour)%24;
	return t;
}

time operator - (time t1, time t2){
	time t;
	int s = t1.second - t2.second + 60;
	t.second = s%60;
	if(t1.second < t2.second) (t2.minute)++;
	int m = t1.minute - t2.minute + 60;
	t.minute = m%60;
	if(t1.minute < t2.minute) (t2.hour)++;
	t.hour = (t1.hour - t2.hour + 24)%24;
	return t;
}

int main(int argc, char *argv[]){
	time t1,t2;
	t1.hour=0;t1.minute=0;t1.second=0;t2.hour=0;t2.minute=0;t2.second=0;
	do{
		printf("t1: \nhour(0-23):   ");	scanf("%d",&t1.hour);
	}while(t1.hour >= 24 || t1.hour < 0);
	do{
		printf("minute(0-59): ");			scanf("%d",&t1.minute);
	}while(t1.minute >= 60 || t1.minute < 0);
	do{
		printf("second(0-59): ");			scanf("%d",&t1.second);
	}while(t1.second >= 60 || t1.second < 0);
	do{
		printf("t2: \nhour(0-23):   ");	scanf("%d",&t2.hour);
	}while(t2.hour >= 24 || t2.hour < 0);
	do{
		printf("minute(0-59): ");			scanf("%d",&t2.minute);
	}while(t2.hour >= 60 || t2.hour < 0);
	do{
		printf("second(0-59): ");			scanf("%d",&t2.second);
	}while(t2.second >= 60 || t2.second < 0);
	printf("\n----------------------\nYou input: t1: "); display(t1); printf("  t2: "); display(t2);
	printf("\n"); display(t1); printf(" + "); display(t2); printf(" = "); display(t1+t2);
	printf("\n"); display(t1); printf(" - "); display(t2); printf(" = "); display(t1-t2);
	return 0;
}


















