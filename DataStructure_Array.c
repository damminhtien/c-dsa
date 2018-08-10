#include <stdio.h>
#include "array.h"
int main(){
	int array[100],kichthuoc;
	nhapmang(array,&kichthuoc);
	xuatmang(array,&kichthuoc);
	bubblesort(array,&kichthuoc);
	printf("\n");
	xuatmang(array,&kichthuoc);
}
void nhapmang(int *array,int *kichthuoc){
	printf("nhap gia tri kich thuoc cua mang: ");scanf("%d",kichthuoc);
	for(int i=0;i<*kichthuoc;i++){
		printf("\nnhap vao phan tu thu %d: ",i);scanf("%d",array+i);
	}
}
void xuatmang(int *array,int *kichthuoc){
	for(int i=0;i<*kichthuoc;i++) printf("%d ",*(array+i));
}
void bubblesort(int *array,int *kichthuoc){
	for(int i=0;i<*kichthuoc-1;i++)
		for(int j=*kichthuoc;j>i;j--)
			if(array[j]<array[j-1]){
				int k=array[j];
				array[j]=array[j-1];
				array[j-1]=k;
			}
}
