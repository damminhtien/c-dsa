#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
typedef int ElementType;
typedef struct NodeType{
	ElementType Data;
	NodeType *Next;
};
NodeType *pNode;
int IsEmpty(NodeType *pNode){
	return !pNode;
}
int Size(NodeType *pNode){
	NodeType *Tempnode;
	int Count=1;
	if(IsEmpty(pNode)) return 0;
	Tempnode=pNode->Next;
	while(Tempnode!=pNode){
		Tempnode=Tempnode->Next;
		Count++;
	}
	return Count;	
}
NodeType *Insert(NodeType *Node,ElementType X){
	NodeType *Tempnode;
	Tempnode=(NodeType*)malloc(sizeof(NodeType));
	if(Tempnode==NULL) exit(1);
	if(IsEmpty(Node)){
		Node=Tempnode;
		Node->Next=Node;
	}
	else{
		Tempnode->Next=Node->Next;
		Node->Next=Tempnode;
	}
	Tempnode->Data=X;
	return Node;	
}
NodeType *FindMid(NodeType *Node,ElementType X){
	NodeType *Tmp;
	Tmp=Node->Next;
	if(Tmp->Data==X); 
	else{
		while(Tmp!=Node){
		if(Tmp->Data==X) break;
		Tmp=Tmp->Next;
	}
	}
	return Tmp;
}
void Print(NodeType *pNode){
	NodeType *Tempnode;
	Tempnode=pNode->Next;
	printf("%d  ",pNode->Data);
	while(Tempnode!=pNode){
		printf("%d   ",Tempnode->Data);
		Tempnode=Tempnode->Next;
	}
}
int main(){
	system("color F0");
	pNode=Insert(pNode,5); 	
	pNode=Insert(pNode,1);
	pNode=Insert(pNode,2);
	pNode=Insert(pNode,-3);
	pNode=Insert(pNode,4);
	pNode=Insert(pNode,-8);
	pNode=Insert(pNode,7);
	pNode=Insert(pNode,-1);
	Print(pNode);
	NodeType *FoundNode;
	FoundNode=FindMid(pNode,-1);
	printf("\nFound: %d ;",FoundNode->Data);	
	printf("Size: %d\n",Size(pNode));
}

