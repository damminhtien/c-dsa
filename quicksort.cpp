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
void quicksort(int a[],int n,int first,int last){
	if(first>=last) return;
	int mid=(first+last)/2;
	int i=first,j=last;
	while(i<=j){
		while(a[mid]>a[i]) i++;
		while(a[mid]<a[j]) j--;
		if(i<=j){
		int k=a[i];
		a[i]=a[j];
		a[j]=k;
		i++;j--;	
		}
		
	} 
	quicksort(a,n,first,j);
	quicksort(a,n,i,last);
	return;
}
main(){
	int a[100],n;
	nhapmang(a,n);
	int first=0,last=n-1;
	xuatmang(a,n);
	quicksort(a,n,first,last);
	xuatmang(a,n);
}
