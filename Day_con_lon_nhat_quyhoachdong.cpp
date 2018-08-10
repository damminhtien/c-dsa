#include<stdio.h>
int quyhoachdong(int a[],int n){
	int smax=a[0]; //gia tri can tra ve, tai cac buoc se ss voi maxendhere de lay gia tri lon hon
	int maxendhere=a[0]; //gia tri luu tru tong lon nhat, tai moi buoc se cap nhat
	for(int i=1;i<n;i++){
		int u=maxendhere+a[i];
		int v=a[i];
		if(u>v) maxendhere=u;
		else maxendhere=v;
		if(maxendhere>smax) smax=maxendhere;
	}
	return smax;
}
main(){
	int a[100];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("day con lon nhat: %d",quyhoachdong(a,n));
}
