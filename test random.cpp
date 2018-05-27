#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 100
#define min 50
main(){
	srand((time(NULL)));
	int sobimat=rand()%(max-min+1)+min;
	printf("%d",sobimat);
}
