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
void bubblesort(int a[],int n){
	for(int i=0;i<n-1;i++)
	for(int j=n-2;j>i;j--)
	if(a[j]>a[j+1]){
		int k=a[j];
		a[j]=a[j+1];
		a[j+1]=k;
	}
}
main(){
	int a[100];
	int n;
	nhapmang(a,n);
	xuatmang(a,n);
	bubblesort(a,n);
	xuatmang(a,n);
}
