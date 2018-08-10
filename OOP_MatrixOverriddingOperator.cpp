#include<stdio.h>
#include<stdlib.h>

struct mt{
	int **data;
	int m;
	int n;
};

void InputMatrix(mt &a){
	for(int i=0;i<a.m;i++){
		for(int j=0;j<a.n;j++){
			printf("Nhap phan tu [%d][%d]: ",i,j);scanf("%d",&a.data[i][j]);
		}
	}
}

void Display(mt a){
	for(int i=0;i<a.m;i++){
		printf("\n");
		for(int j=0;j<a.n;j++)
			printf("%d ",a.data[i][j]);
	}		
}

mt operator + (mt a,mt b){
	mt c;
	c.m = a.m ; c.n = a.n;
	c.data = new int*[c.m];
	for(int i = 0; i<c.m; i++)
   		c.data[i] = new int[c.n];
	for(int i=0;i<c.m;i++){
		for(int j=0;j<c.n;j++){
			c.data[i][j] = a.data[i][j] + b.data[i][j];
		}
	}
	return c;
}

mt operator - (mt a,mt b){
	mt c;
	c.m = a.m ; c.n = a.n;
	c.data = new int*[c.m];
	for(int i = 0; i<c.m; i++)
   		c.data[i] = new int[c.n];
	for(int i=0;i<c.m;i++){
		for(int j=0;j<c.n;j++){
			c.data[i][j] = a.data[i][j] - b.data[i][j];
		}
	}
	return c;
}

mt operator * (mt a, mt b){
	mt c;
	c.m = a.m;
	c.n = a.n;
	c.data = new int*[c.m];
	for(int i=0;i<c.m;i++){
		c.data[i] = new int[c.n];
	}
	for(int i=0;i<c.m;i++){
		for(int j=0;j<c.n;j++){
			c.data[i][j] = 0;
			for(int k=0;k<c.m;k++){
				c.data[i][j] += a.data[i][k]*b.data[k][j];	
			}
		}
	}
	return c;
}

int main(int argc, char *argv[]){
	mt a,b;
	printf("Nhap vao so hang m cua A: "); scanf("%d",&a.m);
	printf("Nhap vao so cot  n cua A: "); scanf("%d",&a.n);
	printf("Nhap vao so hang m cua B: "); scanf("%d",&b.m);
	printf("Nhap vao so cot  n cua B: "); scanf("%d",&b.n);
	//alloc maxtrix
	a.data = new int*[a.m];
	for(int i = 0; i<a.m; i++)
   		a.data[i] = new int[a.n];
	b.data = new int*[b.m];
	for(int i = 0; i<b.m; i++)
   		b.data[i] = new int[b.n];
	printf("\n-----------------\nNhap ma tran A: \n"); InputMatrix(a);
	printf("\n-----------------\nNhap ma tran B: \n");InputMatrix(b);
	printf("\n-----------------\nMang A da nhap: "); Display(a);
	printf("\nMang B da nhap: "); Display(b);
	for(int i = 0; i < 2000; i++){
		printf("\n-----------------\nMang C= A+B: "); mt c = a + b; Display(c);
		printf("\n-----------------\nMang C= A*B: "); mt d = a * b; Display(d);	
	}
	//detele
	for(int i = 0; i<a.m; i++){
		delete []a.data[i];
		delete []b.data[i];
	} 
	delete []a.data;
	delete []b.data;
	return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>

struct mt{
	int *data;
	int m;
	int n;
};

void InputMatrix(mt &a){
	for(int i=0;i<a.m;i++){
		for(int j=0;j<a.n;j++){
			printf("Nhap phan tu [%d][%d]: ",i,j);scanf("%d",&a.data[i*a.n+j]);
		}
	}
}

void Display(mt a){
	for(int i=0;i<a.m;i++){
		printf("\n");
		for(int j=0;j<a.n;j++)
			printf("%d ",a.data[i*a.n+j]);
	}		
}

mt operator + (mt a,mt b){
	mt c;
	c.m = a.m ; c.n = a.n;
	c.data = (int*) malloc (c.m*c.n*sizeof(int));
	for(int i=0;i<c.m*c.n;i++){
		c.data[i]=a.data[i] + b.data[i];
	}
	return c;
}

mt operator - (mt a,mt b){
	mt c;
	c.m = a.m ; c.n = a.n;
	c.data = (int*) malloc (c.m*c.n*sizeof(int));
	for(int i=0;i<c.m*c.n;i++){
		c.data[i]=a.data[i] - b.data[i];
	}
	return c;
}

int main(int argc, char *argv[]){
	mt a,b;
	printf("Nhap so hang m: "); scanf("%d",&a.m);
	printf("Nhap so hang n: "); scanf("%d",&a.n);
	b.m = a.m;
	b.n = a.n;
	a.data = (int*) malloc (a.m*a.n*sizeof(int));
	b.data = (int*) malloc (b.m*b.n*sizeof(int));
	printf("\n----------------\nNhap ma tran A: \n"); InputMatrix(a);
	printf("\nNhap ma tran B: \n");InputMatrix(b);
	printf("\n----------------\nMang A: "); Display(a);
	printf("\nMang B: "); Display(b);
	printf("\n----------------\nC= A+B: "); Display(a+b);
	printf("\n\nC= A-B: "); Display(a-b);
	return 0;
}*/
