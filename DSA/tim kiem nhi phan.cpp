#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int a[],int first,int last,int x){
	int mid=(first+last)/2;
	if(first==last){
	if(x==a[mid]) return mid; else return -1; }
	if(x==a[mid]) return mid;
	else{
	 if(x<a[mid]) return BinarySearch(a,first,mid-1,x);
	 else return BinarySearch(a,mid+1,last,x);}
}
main(){
	int n;
	int x;
	int *a=NULL;
	printf("nhap n: ");
	scanf("%d",&n);
	if(n>0){
 	a=(int *)malloc(n *sizeof(int));
	}
	printf("\nnhap mang:\n");
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("\nnhap x :");
	scanf("%d",&x);
	printf("vi tri so can tim: ");
	printf("%d",BinarySearch(a,0,n-1,x));
	free(a);
	}
