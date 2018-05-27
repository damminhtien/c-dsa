#include<stdio.h>
int dayconmax(int a[],int n){
	int max=a[0];
	for(int i=0;i<n;i++){
		int S=0;
		for(int j=i;j<n;j++){
			S+=a[j];
			printf("%d",S);
			if(S>max) max=S;
		}
	}
	return max;
}
void nhapxuatmang(int a[],int &n){
	scanf("%d",&n);
	printf("nhap vao cac phan tu cua mang: \n");
	for(int i=0;i<n;i++){
		printf("nhap vao phan tu thu %d: ",i);
		scanf("%d",&a[i]);
	}
	printf("\nmang: ");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
main(){
	int a[100];
	int n;
	nhapxuatmang(a,n);
	printf("\nday con lon nhat: %d",dayconmax(a,n));
}
