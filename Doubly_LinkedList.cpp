#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef int ElementType;
typedef struct NodeType{
	ElementType Data;
	NodeType *Next;
	NodeType *Prev;
};
NodeType *pHead,*pTail;
NodeType *InsertToHead(NodeType *pHead,ElementType X){
	printf("Insert %d To Head\n",X);
	NodeType *Tempnode;
	Tempnode=(NodeType*) malloc(sizeof(NodeType));
	if(Tempnode==NULL) exit(1);
	if(pHead==NULL){
		pTail=Tempnode;
		pHead=Tempnode;
		Tempnode->Next=NULL;
	}
	else{
		pHead->Prev=Tempnode;	
		Tempnode->Next=pHead;
		
	}
	Tempnode->Data=X;
	Tempnode->Prev=NULL;
	return Tempnode;
	
}
void HeadtoTail(NodeType *pHead){
	NodeType *Tempnode=pHead;
	while(Tempnode!=NULL){
		printf("%d   ",Tempnode->Data);
		Tempnode=Tempnode->Next;
	}
}
void TailtoHead(NodeType *pTail){
	NodeType *Tempnode=pTail;
	while(Tempnode!=NULL){
		printf("%d   ",Tempnode->Data);
		Tempnode=Tempnode->Prev;
	}	
}
NodeType *InsertToLast(NodeType *pTail,ElementType X){
	printf("InsertToLast\n");
	NodeType *Tempnode;
	Tempnode=(NodeType*) malloc(sizeof(NodeType));
	if(Tempnode==NULL) exit(1);
	if(pTail==NULL){
		pTail=Tempnode;
		pHead=Tempnode;
		Tempnode->Prev=NULL;
	}
	else{
	pTail->Next=Tempnode;
	Tempnode->Prev=pTail;
	}
	Tempnode->Data=X;
	Tempnode->Next=NULL;
	return Tempnode;
}
int Size(NodeType *pHead){
	NodeType *Tempnode;
	int Count=0;
	Tempnode=pHead;
	while(Tempnode!=NULL){
		Count++;
		Tempnode=Tempnode->Next;
	}
	return Count;
}
int IsEmpty(NodeType *pHead){
	return !pHead;
}
NodeType *InsertToMiddle(NodeType *pHead,ElementType X,int Position){
	printf("Insert %d to position %d\n",X,Position);
	int i=1;
	NodeType *Tempnode1,*Tempnode2;
	Tempnode2=(NodeType*)malloc(sizeof(NodeType));
	if(Tempnode2==NULL) exit(1);
	Tempnode1=pHead;
	if(Position==0) return InsertToHead(pHead,X);
	else{
		if(Position==Size(pHead)) pTail=InsertToLast(pTail,X);
		else{
			while(i<Position){
				Tempnode1=Tempnode1->Next;
				i++;
			}
			Tempnode1->Next->Prev=Tempnode2;
			Tempnode2->Next=Tempnode1->Next;
			Tempnode2->Prev=Tempnode1;
			Tempnode1->Next=Tempnode2;
			Tempnode2->Data=X;
		}
	}
	return pHead;
}
NodeType *DeleteHead(NodeType *pHead){
	printf("Delete Head\n");
	NodeType *Tempnode;
	Tempnode=pHead;
	pHead=pHead->Next;
	pHead->Prev=NULL;
	free(Tempnode);
	return pHead;
}
NodeType *DeleteTail(NodeType *pTail){
	printf("Delete Tail\n");
	NodeType *Tempnode;
	Tempnode=pTail;
	pTail=pTail->Prev;
	pTail->Next=NULL;
	free(Tempnode);
	return pTail;
}
NodeType *DeleteMiddle(NodeType *pHead,int Position){
	printf("Delete in %d\n",Position);
	NodeType *Tempnode;
	int i=1;
	Tempnode=pHead->Next;
	if(Position==0) pHead=DeleteHead(pHead);
	else{
	if(Position==(Size(pHead)-1)) pTail=DeleteTail(pTail);
	else{
	while(i<Position){
	Tempnode=Tempnode->Next;
	i++;
	} 
	Tempnode->Prev->Next=Tempnode->Next;
	Tempnode->Next->Prev=Tempnode->Prev;
	free(Tempnode);
	}
	return pHead;
	}
}	
int main(){
	system("color 06");
	printf("At Starting: \n");
	printf("IsEmpty: %d",IsEmpty(pHead));
	printf("\nNumber of Element(s)= %d",Size(pHead));
	pTail=InsertToLast(pTail,5);
	pHead=InsertToHead(pHead,4);
	pHead=InsertToMiddle(pHead,10,1);
	pHead=InsertToHead(pHead,0);
	pHead=InsertToHead(pHead,1);
	pHead=InsertToHead(pHead,2);
	pHead=InsertToMiddle(pHead,100,1);
	pHead=DeleteMiddle(pHead,6);
	pHead=DeleteHead(pHead);
	pTail=DeleteTail(pTail);
	printf("Data saves in Doubly Linked List from HEAD to TAIL: \n");
	HeadtoTail(pHead);
	printf("\nData saves in Doubly Linked List from TAIL to HEAD: \n");
	TailtoHead(pTail);
	printf("\nNumber of Element(s)= %d\n",Size(pHead));
	printf("IsEmpty: %d\n",IsEmpty(pHead));
		
}
