#include<stdio.h>
int count;
void chuyen(int n,char a,char c);
void thapHN(int n,char a,char b,char c);

void thapHN(int n,char a,char b,char c){
	if(n==1) chuyen(1,a,c);
	else{
		thapHN(n-1,a,c,b);
		chuyen(n,a,c);
		thapHN(n-1,b,a,c);
	}
}


void chuyen(int n,char a,char c){
	printf("chuyen dia %d tu %c sang %c! \n",n,a,c);
	count++;
}
main(){
	int n;
	char a='A',b='B',c='C';
	printf("Scan Number of Disk(s): ");
	scanf("%d",&n);
	thapHN(n,a,b,c);
	printf("\nNumber of Moving(s): %d",count);
}
