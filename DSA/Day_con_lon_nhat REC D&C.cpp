#include<stdio.h>
int maxleft(int a[],int i,int j){
	int S=0,max=-1000000;
	for(int k=j;k>=i;k--){
		S+=a[k];
		if(S>max) max=S;
	}
	printf("\n%d",max);
	return max;
}
int maxright(int a[],int i,int j){
	int S=0,max=-1000000;
	for(int k=i;k<=j;k++){
		S+=a[k];
		if(S>max) max=S;
	}
	printf("\n%d",max);
	return max;
}
int max(int a[],int i,int j){
	if(i==j) return a[j];
	else{
		int m=(i+j)/2;
		int maxR=max(a,m+1,j);
		int maxL=max(a,i,m);
		int maxM=maxleft(a,i,m)+maxright(a,m+1,j);
		return (maxR>maxL?maxR:maxL)>maxM?(maxR>maxL?maxR:maxL):maxM;
	}
	
}
main(){
	int a[100];
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("\n%d",max(a,0,n-1));	
}
