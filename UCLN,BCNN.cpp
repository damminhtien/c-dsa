#include <stdio.h>
void nhap(int &a,int&b){
	printf ("moi ban nhap vao 2 so a,b:\n ");
	scanf ("%d%d",&a,&b);
}
main(){
	int a,e,b,m,f,c;
	nhap(a,b);
	e=a;f=b;
	while(c!=0){
		c=a%b;
		a=b;
		m=b;
		b=c;printf("\n%d",b);
	}
	printf ("UCLN cua 2 so a,b la: %d",b);
	printf ("\nBCNN cua 2 so a,b la: %d",(e*f)/a);
}
