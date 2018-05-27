#include<stdio.h>
#include<math.h>

void IsPrimeNumber(int x){
	int temp = sqrt(x);
	int k = 1;
	for(int i = 2; i <= temp; i++){
		if(x % i == 0){
			k = 0;
			break;
		} 
	}
	if(k == 0) printf("NO, %d isn't prime number!",x);
	else printf("YES, %d is prime number!",x);
}

int main(int argc, char *argv[]){
	int x;
	printf("Input x: ");
	scanf("%d",&x);
	if(x <= 1) printf("NO, %d isn't prime number!",x);
	else IsPrimeNumber(x);
	return 0;
}
