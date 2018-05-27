#include<stdio.h>
int C(int,int);
int C(int n,int k){
	if(k==0||k==n) return 1;
	else return C(n-1,k)+C(n-1,k-1);
}
main(){
	int k,n;
	scanf("%d",&n);
	scanf("%d",&k);
	printf("to hop chap %d cua %d = %d",k,n,C(n,k));
}
