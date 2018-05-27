#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int DataType;
typedef struct NodeType{
	DataType Data;
	NodeType *Leftchild;
	NodeType *Rightchild;
};

NodeType *Root;
NodeType *fTmp;
int ld = 0;
int rd = 0;

NodeType *MakeNode(){
	NodeType *Temp;
	Temp=(NodeType*) malloc(sizeof(NodeType));
	if(Temp==NULL) exit(1);
	else{
		Temp->Leftchild=NULL;
		Temp->Rightchild=NULL;
	} 
	return Temp;
}

NodeType *PreOrderFind(NodeType *fRoot,DataType ch){
	if(fRoot->Data==ch) fTmp=fRoot;
	else{
		if(fRoot->Leftchild!=NULL) fTmp=PreOrderFind(fRoot->Leftchild,ch);
		if(fRoot->Rightchild!=NULL) fTmp=PreOrderFind(fRoot->Rightchild,ch);
	}
	return fTmp;
}

void PreOrderTraversal(NodeType *fRoot){
	printf(" %c ",fRoot->Data); 
	if(fRoot->Leftchild!=NULL) PreOrderTraversal(fRoot->Leftchild);
	if(fRoot->Rightchild!=NULL) PreOrderTraversal(fRoot->Rightchild);
}

void InOrderTraversal(NodeType *fRoot){ 
	if(fRoot->Leftchild!=NULL) InOrderTraversal(fRoot->Leftchild);
	printf(" %c ",fRoot->Data);
	if(fRoot->Rightchild!=NULL) InOrderTraversal(fRoot->Rightchild);
}

void PostOrderTraversal(NodeType *fRoot){ 
	if(fRoot->Leftchild!=NULL) PostOrderTraversal(fRoot->Leftchild);
	if(fRoot->Rightchild!=NULL) PostOrderTraversal(fRoot->Rightchild);
	printf(" %c ",fRoot->Data);
}

void LeftChild(DataType ch1,DataType ch2){
	NodeType *Tmp1;
	NodeType *Tmp2;
	Tmp2=MakeNode();
	Tmp1=PreOrderFind(Root,ch1);
	if(Tmp1==NULL) exit(1);
	else{
		Tmp1->Leftchild=Tmp2;
		Tmp2->Data=ch2;
	}	
}

void MakeRoot(DataType ch){
	Root=MakeNode();
	Root->Data=ch;
}

void RightChild(DataType ch1,DataType ch2){
	NodeType *Tmp1;
	NodeType *Tmp2;
	Tmp2=MakeNode();
	Tmp1=PreOrderFind(Root,ch1);
	if(Tmp1==NULL) exit(1);
	else{
		Tmp1->Rightchild=Tmp2;
		Tmp2->Data=ch2;
	}
}

int Height(NodeType *fRoot){
	if(fRoot == NULL) return 0;
	int ld = Height(fRoot->Leftchild);
	int rd = Height(fRoot->Rightchild);
	return ld > rd ? (ld+1):(rd+1);
}

int main(){
	MakeRoot('a');
	LeftChild('a','b');fTmp=NULL;
	RightChild('a','c');fTmp=NULL;
	LeftChild('b','d');fTmp=NULL;
	RightChild('b','e');fTmp=NULL;
	RightChild('d','j');fTmp=NULL;
	LeftChild('d','h');fTmp=NULL;
	LeftChild('e','k');fTmp=NULL;
	RightChild('e','l');fTmp=NULL;
	LeftChild('c','f');fTmp=NULL;
	RightChild('c','g');fTmp=NULL;	
	printf("PreOrderTraversal:  ");
	PreOrderTraversal(Root);
	printf("\nInOrderTraversal:   ");
	InOrderTraversal(Root);
	printf("\nPostOrderTraversal: ");
	PostOrderTraversal(Root);
	printf("\nHeight: %d",Height(Root));
}
