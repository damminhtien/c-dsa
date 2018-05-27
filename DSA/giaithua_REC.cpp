#include<stdio.h>
int Fact(int n);
int Fact(int n){
	if(n==0||n==1) return 1;
	else return n*Fact(n-1);
}
main(){
	printf("nhap vao n>=0: ");
	int n;
	scanf("%d",&n);
	printf("\ngia tri cua %d!=%d",n,Fact(n));
}
