/*
input: da thuc bac n, he so cua cac bac; gia tri cua x
output: gia tri cua da thuc tai x
think: luu tru he so bang mang
 */
#include<stdio.h>
#include<math.h>
void nhapxuatdathuc(float a[],int &n){
	printf("nhap bac cao nhat cua da thuc: ");scanf("%d",&n);
	for(int i=n;i>=0;i--){
		printf("nhap he so cua x^%d: ",i);scanf("%f",&a[i]);
	}
	printf("da thuc vua nhap: f(x)=%0.1f*x^%d",a[n],n);
	for(int i=n-1;i>=0;i--)
	printf(" + %0.1f*x^%d",a[i],i);
}
void tinhgiatri(float a[],float x,int n){
	float s=0;
	printf("\nnhap gia tri cua x: ");scanf("%f",&x);
	for(int i=0;i<=n;i++){
		s+=a[i]*pow(x,i);
	}
	printf("\ngia tri cua da thuc tai x la: %.1f",s);	
}
void cong_nhan_dathuc(float a[],float b[],int n,int m){
	//cong da thuc
	float c[100];
	int k;k= m>n?m:n;
	for(int i=0;i<=k;i++){
		c[i]=a[i]+b[i];}
	printf("\ntong hai da thuc: f(x)=%0.1f*x^%d",c[k],k);
	for(int i=k-1;i>=0;i--)
	printf(" + %0.1f*x^%d",c[i],i);
	float d[100];
	//nhan da thuc
	for(int i=0;i<m+n;i++) d[i]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			d[i+j]+=a[i]*b[j];
		}
	}
	printf("\ntich hai da thuc: f(x)=%0.1f*x^%d",d[m+n],m+n);
	for(int i=m+n-1;i>=0;i--)
	printf(" + %0.1f*x^%d",d[i],i);
}
main() {
	int n,m;
	float x;
	float a[100];
	float b[100];
	printf("Da thuc 1: ");nhapxuatdathuc(a,n);
	tinhgiatri(a,x,n);
	printf("\n\nDa thuc 2: ");nhapxuatdathuc(b,m);
	tinhgiatri(b,x,n);
	cong_nhan_dathuc(a,b,n,m);
	
}
