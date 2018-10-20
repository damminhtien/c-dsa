#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int DataType;

typedef struct ListType{
	DataType data;
	ListType *next;
};

ListType *List;

int Size = 0;

void CreateTree(){
	printf("Input number of node(s): ");
	scanf("%d",&Size);
	List = (ListType*) malloc (Size*sizeof(ListType));
	
	for(int i = 0; i<Size; i++){
		int data;
		printf("Data of parent node %d:  ",i+1);
		scanf("%d",&data);
		(&List[i])->data = data;
		ListType *checkpoint;
		checkpoint = &List[i];
		int flag = 1;
		while(flag == 1){
			printf("Have another children? 1 or 0\n");
			fflush(stdin);
			scanf("%d",&flag);
			if(flag == 1){
				ListType *temp = NULL;
				temp = (ListType*) malloc (sizeof(ListType));
				printf("Input data: ");
				int data;
				scanf("%d",&data);
				temp->data = data;
				temp->next = NULL;
				checkpoint->next = temp;
			}
			checkpoint = checkpoint->next;	
		}
		
		
	}
}

ListType *Parent(DataType x){
	ListType *temp, *temp0;
	for(int i = 0; i < Size; i++){
		temp0 = &List[i];
		temp = (&List[i])->next;
		while(temp->data != x && temp->next != NULL){
			temp = temp->next;
		} 
		if(temp->data == x) break;
	}
	return temp0;
}
	
void Print(){
	for(int i = 0; i < Size; i++){
		printf("Parent: %d   ",(&List[i])->data);
	}
}

int main(){
	CreateTree();
	Print();
	printf("Find parent of? ");
	int fp;
	scanf("%d",&fp);
	printf("Parent of %d : %d",fp,*Parent(fp));
	free(List);
}
