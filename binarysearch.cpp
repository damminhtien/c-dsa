// Binary Search
#include<stdio.h>
int nonRECbinarysearch1(int a[],int n,int x){
	int mid=(n-1)/2,left=0,right=n-1;
	while(right>=left){
		if(a[mid]==x) return mid;
		if(a[mid]>x) right=mid-1;
		if(a[mid]<x) left=mid+1;
		mid=(left+right)/2;
	}return -1;
}
/* dequy
int left=0,right=n-1;
int RECbinarysearch1(int a[],int n,int x,int left,int right){
	if(left>right) return -1;
	int mid=(left+right)/2;
	if(a[mid]==x) return mid;
	if(a[mid]>x) return RECninarysearch(a,n,x,left,right=mid-1);
	if(a[mid]<x) return RECbinarysearch(a,n,x,left=mid+1;right);	
	
	
}*/
int nonRECbinarysearch2(int a[],int n,int x){
	int mid=(n-1)/2,left=0,right=n-1;
	if(n==1) if(a[0]==x) return 0;
	while(right>=left){
		if(a[mid]==x) return mid;
		if(a[mid]<x) right=mid-1;
		if(a[mid]>x) left=mid+1;
		mid=(left+right)/2;
	}return -1;
}
main(){
	int a[100],n,x;
	printf("nhap vao so phan tu cua day: ");scanf("%d",&n);
	printf("\nnhap vao phan tu can tim: ");scanf("%d",&x);
	printf("\nmang can nhap la day tang hay day giam: 1.tang 2.giam  ");
	int c;
	scanf("%d",&c);
	if(c==1){
		printf("\nnhap vao 1 day tang: ");
			for(int i=0;i<n;i++){
			printf("\nnhap vao phan tu thu %d: ",i);scanf("%d",&a[i]);
			if(a[i]<=a[i-1]&&i!=0){
				i--;printf("\nnhap lai!");
			}
		}
		printf("\nmang da nhap: ");
			for(int i=0;i<n;i++) printf(" %d",a[i]);
		int k=nonRECbinarysearch1(a,n,x);
			if(k!=-1 )printf("\nvi tri cua phan tu can tim la: %d",k);
			else printf("\nko co x trong day :( ");
		}
	if(c==2){
		printf("\nnhap vao 1 day giam: ");
			for(int i=0;i<n;i++){
			printf("\nnhap vao phan tu thu %d: ",i);scanf("%d",&a[i]);
			if(a[i]>=a[i-1]&&i!=0){
				i--;printf("\nnhap lai!");
			}
		}
		printf("\nmang da nhap: ");
			for(int i=0;i<n;i++) printf(" %d",a[i]);
		int k=nonRECbinarysearch2(a,n,x);
			if(k!=-1 )printf("\nvi tri cua phan tu can tim la: %d",k);
			else printf("\nko co x trong day :( ");
		}	
		
		
		
		
		
		
		
		
		
		
		
}
