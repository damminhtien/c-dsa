#include<stdio.h>
void PaintColor(int n){
	if(n==1){
		printf("Draw %dst straight line\n",n);
		printf("Consider the straight line %d divide plane to 2 part: A%d and B%d \n",n,n,n);
		printf("Paint A%d with red & B%d with blue \n",1,1);
	}
	else{ PaintColor(n-1);
	printf("Draw straight line %d\n",n);
	printf("Consider the straight line %d divide plane to 2 part: A%d and B%d \n",n,n,n);
	printf("change red=> blue & blue => red in A%d\n",n);
	}
}
main(){
	int n;
	printf("Scan number of line(s): ");
	scanf("%d",&n);
	printf("--------------------------------\n");
	PaintColor(n);
}
