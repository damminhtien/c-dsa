//sx tang
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
void selectionsort(int a[],int n){
	int k;
	for(int i=0;i<n-1;i++){
		k=i;
		int min=a[i];
		for(int j=i;j<n;j++){
			if(a[j]<min){k=j;min=a[j];}
		}
		int m=a[k];
		a[k]=a[i];
		a[i]=m;
	}
}

main(){
	int a[100],n;
	nhapmang(a,n);
	xuatmang(a,n);
	selectionsort(a,n);
	xuatmang(a,n);
}
