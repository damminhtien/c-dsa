#include <stdio.h>
main (){
	int n,a[10000];
	scanf ("%d",&n);
	for (int i = 1;i <= n;i++){
		a[i] = i;
	}
	
	a[1] = 0;
	for (int i = 2;i <= n;i++){
		if (a[i]){
			int j = 2 * i;
			while (j <= n){
				a[j] = 0;
				j += i;
			}
		}
		if (a[i] != 0) printf ("%5d",a[i]);
	}
}
