/* LinearSearch*/
#include<stdio.h>
int linearexhaustive(int a[],int n,int x){
	int i=0;
	while(a[i]!=x&&i<n) i++;
	if(i<n) return i;
	else return -1;
}
int linearsentinel(int a[],int n,int x){
	a[n]=x;
	int i;
	while(a[i]!=x) i++;
	if(i<n) return i;
	else return -1;
}
main(){
	int a[100],n,x;
	printf("nhap vao so phan tu cua day: ");scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("nhap vao phan tu thu %d cua day: ",i);scanf("%d",&a[i]);
	}
	printf("\nnhap vao phan tu can tim: ");scanf("%d",&x);
	int c;
		printf("\nchon phuong an tim kiem: 1.LinearExhaustive 2.LinearSentinel ");scanf("%d",&c);
	if(c==1){
		int k=linearexhaustive(a,n,x);
		if(k==-1) printf("\nkhong tim thay x");
		else printf("\nvi tri dau tien cua x trong day: %d",k);}
	if(c==2){
		int k=linearsentinel(a,n,x);
		if(k==-1) printf("\nkhong ton tai x trong day!");
		else printf("vi tri dau tien cua x trong day la: %d",k);}
}
