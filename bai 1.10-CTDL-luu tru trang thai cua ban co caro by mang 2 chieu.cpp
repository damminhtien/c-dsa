/*input: toa do cua cac diem X;O tren ban co caro m hang n cot - coi X la 1 va O la 2; 
output: xuat ra X win neu tai trang thai do X thang va nguoc lai, neu ko ai thang thi xuat chua ai thang
think: luu tru bang mang 2 chieu voi i j la toa do cua diem hien hanh, tai moi diem cua mang duyet ngang, xuong, cheo de kiem tra. 5 phan tu tro len cung hang
la win */
#include<stdio.h>
#include<conio.h>
main(){
	int a[20][20],m,n,i,j,k;
	char c='c';
	printf("chon kich thuoc ban co: ");
	printf("\nm= ");scanf("%d",&m);
	printf("n= ");scanf("%d",&n);
	for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				a[i][j]=0;}}
	printf("\nnhap vao cac toa do cua X: ");
	while(c=='c'){
		do{
		printf("\nhoanh do= ");scanf("%d",&i); 
		if(i>=n) printf(" nhap lai: ");}while(i>=n);
		do{
		printf("tung do= ");scanf("%d",&j); 
		if(j>=m) printf(" nhap lai: ");}while(j>=m);
		a[i][j]=1;
		printf("\ncon X nao khac? go 'c' neu  con va 'k' neu khong? ");
		c=getche();
		}
	printf("\n\nnhap vao cac toa do cua O: ");c='c';	
	while(c=='c'){
		do{
		printf("\nhoanh do= ");scanf("%d",&i); 
		if(i>=n) printf(" nhap lai: ");}while(i>=n);
		do{
		printf("tung do= ");scanf("%d",&j); 
		if(j>=m) printf(" nhap lai: ");}while(j>=m);
		if(a[i][j]==1) printf("\ntai day da co X!");
		else a[i][j]=2;
		printf("\ncon O nao khac? go 'c' neu  con va 'k' neu khong? ");
		c=getche();
		}
	printf("\n_____________________________________");
	printf("\n           MAP da nhap:\n   ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==1) printf(" X");
			if(a[i][j]==2) printf(" O");
			if(a[i][j]==0) printf(" *");
		} printf("\n   ");}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==1){
				int d=0;
				for(k=j+1;k<j+5;k++){
					if(a[i][k]==1) d++;
					else break;
					}if(d>=4){ printf("\nX win :))");k=-1;}
				if (k==-1) break;
				d=0;
				for(k=i+1;k<i+5;k++){
					if(a[k][j]==1) d++;
					else break;
					}if(d>=4){ printf("\nX win :v");k=-1;}
				if (k==-1) break;
				d=0;
				for(k=i+1;k<i+5;k++){
					if(a[k][j+k-i]==1) d++;
					else break;
				}if(d>=4){printf("\nX win =))"); k=-1;}
				if (k==-1) break;
			if(a[i][j]==2){
				int d=0;
				for(k=j+1;k<j+5;k++){
					if(a[i][k]==2) d++;
					else break;
					}if(d>=4){ printf("\nO win :))");k=-1;}
				if (k==-1) break;
				d=0;
				for(k=i+1;k<i+5;k++){
					if(a[k][j]==2) d++;
					else break;
					}if(d>=4){ printf("\nO win :v");k=-1;}
				if (k==-1) break;
				d=0;
				for(k=i+1;k<i+5;k++){
					if(a[k][j+k-i]==2) d++;
					else break;
				}if(d>=4){printf("\nO win =))"); k=-1;}
				if (k==-1) break;
				}
				}
				}if (k==-1) break;
			}
		}	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
	
	
