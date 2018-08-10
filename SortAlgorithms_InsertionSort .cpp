//sap xep mang tang
#include<stdio.h>
void nhapmang(int a[],int &n){
	printf("nhap vao so phan tu cua mang: ");scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("nhap vao phan tu thu %d: ",i);scanf("%d",&a[i]);
	}
}
void xuatmang(int a[],int n){
	printf("\nmang: ");
	for(int i=0;i<n;i++) printf("%d ",a[i]);
}
void insertionsort(int a[],int n){
	int i;
	for(int i=1;i<n;i++){
	if(a[i]<a[i-1]){
		int j=i;
		int x=a[j];
	while(a[j-1]>x && j>0){
		a[j]=a[j-1];
		j--;
	}
	a[j]=x;
	}
	}
}
main(){
	int a[100],n;
	nhapmang(a,n);
	xuatmang(a,n);
	insertionsort(a,n);
	xuatmang(a,n);
}
