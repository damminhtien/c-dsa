#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int rows=0;
int *array=NULL;
void Create(){
	printf("Enter the number of elements in array: ",&rows);
	scanf("%d",&rows);
	if(rows<=0){
		printf("Try again:\n");
		Sleep(200);
		Create();
	}
	array=(int *) malloc(rows * sizeof(int));
	for(int i=0;i<rows;i++){
		printf("Import element %d: ",i);
		scanf("%d",(array+i));
	}
	printf("\nImported Array: ");
	for(int i=0;i<rows;i++) printf("%d ",array[i]);
}
void Insert(){
	system("COLOR B5");
	int value=0;
	int pos=0;
	printf("\nWhat number will u Insert in array? ");
	scanf("%d",&value);
	printf("What position are u Insert to: ");
	scanf("%d",&pos);
	while(pos<0||pos>rows){
		printf("Try again: ");
		scanf("%d",&pos);
	}
	rows++;
	for(int i=rows-1;i>pos;i--) *(array+i)=*(array+i-1);
	*(array+pos)=value;
	printf("Inserted Array: ");
	for(int i=0;i<rows;i++) printf("%d ",array[i]);
}
void Remove(){
	system("COLOR C9");
	int pos=0;
	printf("\nPostion of Number that u want to remove: ");
	scanf("%d",&pos);
	for(int i=pos;i<rows;i++) *(array+i)=*(array+i+1);
	rows--;
	printf("Removed: ");
	for(int i=0;i<rows;i++) printf("%d ",array[i]);
}
int Size(){
	system("COLOR EC");
	return rows;
}
void Find(){
	system("COLOR E9");
	int x; 
	printf("Which number u want to get?  ");
	scanf("%d",&x);
	for(int i=0;i<rows;i++){
		if(*(array+i)==x) printf("\nFind %d in %d",x,i);
	}
}
void Get(){
	system("COLOR E8");
	int pos=0;
	printf("\nImport position of Array: ");
	scanf("%d",&pos);
	if(pos<0||pos>=rows) Get();
	else printf("In %d is element: %d",pos,*(array+pos));
}
main(){
	system("COLOR F0");
	Create();
	int choose=0;
	int k=0;
	do{
	printf("\n\n_____________List action:_________________ ");
	printf("\n1.Insert ele: ");
	printf("\n2.Remove ele: ");
	printf("\n3.Size: ");
	printf("\n4.Find pos: ");
	printf("\n5.Get ele: ");
	printf("\nChoose 1 in 5: ");
	do{
		scanf("%d",&choose);
	}while(choose<1||choose>5);
	switch(choose){
		case 1: Insert();break;
		case 2: Remove();break;
		case 3: printf("Number of elements: %d",Size);
		case 4: Find();break;
		case 5: Get();break;
	}
	printf("\nDo u want to do again: 1.Yes 0.No ");
	scanf("%d",&k);
	}while(k==1);
	free(array);
}
