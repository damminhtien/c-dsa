#include<stdio.h>
int n=3;
int a[3];
void backtrack(int i){
	for(int j=0;j<=1;j++){
	a[i]=j;
	if(i==n){ for(int i=1;i<=n;i++) printf("%d",a[i]); printf("\n");}
	else backtrack(i+1);
	 
}
}
main(){
	backtrack(1);
}
