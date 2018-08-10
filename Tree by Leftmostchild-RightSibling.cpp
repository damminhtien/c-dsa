#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef char NodeType;
typedef struct Node{
	NodeType Data;
	Node *Leftmostchild;
	Node *Rightsibling;
};

Node *Root;
Node *fTmp;
int count=0;
int h=0;
int ld=0;
int rd=0;

Node *MakeNode(){
	Node *Tmp; 
	Tmp=(Node*)malloc(sizeof(Node));
	if(Tmp==NULL) exit(1);
	else{
		Tmp->Leftmostchild=NULL;
		Tmp->Rightsibling=NULL;
	}
	return Tmp;
}

void InOrderTraversal(Node *Root){
	if(Root->Leftmostchild==NULL){
		printf("%5c",Root->Data);
		count++;
	} 
	else{
		Node *Tmp;
		Tmp=Root->Leftmostchild;
		InOrderTraversal(Tmp);
		printf("%5c",Root->Data);
		while(Tmp->Rightsibling!=NULL){
			InOrderTraversal(Tmp->Rightsibling);
			Tmp=Tmp->Rightsibling;
		}
		
	}
}

void PreOrderTraversal(Node *fRoot){
	printf("%5c",fRoot->Data);
	if(fRoot->Leftmostchild==NULL) count++; 
	if(fRoot->Leftmostchild!=NULL){
		Node *Temp;
		Temp=fRoot->Leftmostchild;
		while(Temp!=NULL){
		PreOrderTraversal(Temp);
		Temp=Temp->Rightsibling;
	}
	}
}

void PostOrderTraversal(Node *fRoot){
	if(fRoot->Leftmostchild==NULL) count++;
	if(fRoot->Leftmostchild!=NULL){
		Node *Temp;
		Temp=fRoot->Leftmostchild;
		while(Temp!=NULL){
			PostOrderTraversal(Temp);
			Temp=Temp->Rightsibling;
		}
	}
	printf("%5c",fRoot->Data);
}

int Height(Node *fRoot){
	if(fRoot==NULL) return 0;
	if(fRoot->Leftmostchild==NULL) return 1;
	else{
		Node *Tmp1;
		Tmp1=fRoot->Leftmostchild;
		ld=Height(Tmp1);
		if(Tmp1->Rightsibling!=NULL){
			Node *Tmp2;
			Tmp2=Tmp1->Rightsibling;
			rd=Height(Tmp2);
		}
	}
	if(ld>=rd) return 1+ld;
		else return 1+rd;
}

Node *InOrderFind(NodeType ch,Node *fRoot){
	if(fRoot->Leftmostchild==NULL){
		if(fRoot->Data==ch) fTmp=fRoot;
	}
	else{
		Node *Tmp;
		Tmp=fRoot->Leftmostchild;
		fTmp=InOrderFind(ch,Tmp);
		if(fRoot->Data==ch) fTmp=fRoot;
		while(Tmp->Rightsibling!=NULL){
			fTmp=InOrderFind(ch,Tmp->Rightsibling);
			Tmp=Tmp->Rightsibling;
		}
	}
	return fTmp;
}

void LeftMostchild(NodeType ch1,NodeType ch2){
	//ch1 la cha, ch2 la con
	Node *Tmp;
	Tmp=InOrderFind(ch1,Root);
	Node *Newnode;
	Newnode=MakeNode();
	Newnode->Data=ch2;
	Newnode->Rightsibling=NULL;
	Newnode->Leftmostchild=NULL;
	Tmp->Leftmostchild=Newnode;
}

void RightSibling(NodeType ch1,NodeType ch2){
	//ch1 ben trai ch2
	Node *Tmp;
	Tmp=InOrderFind(ch1,Root);
	Node *NewNode;
	NewNode=MakeNode();
	NewNode->Data=ch2;
	NewNode->Leftmostchild=NULL;
	NewNode->Rightsibling=NULL;
	Tmp->Rightsibling=NewNode;
}

Node *MakeRoot(NodeType ch){
	Root=MakeNode();
	Root->Data=ch;
	return Root;
}

int main(){
	MakeRoot('a');
	LeftMostchild('a','b');
	fTmp=NULL;
	LeftMostchild('b','c');
	fTmp=NULL;
	LeftMostchild('c','d');
	fTmp=NULL;
	RightSibling('c','k');
	fTmp=NULL;
	RightSibling('b','e');
	fTmp=NULL;
	LeftMostchild('e','h');
	fTmp=NULL;
	RightSibling('h','g');
	fTmp=NULL;
	LeftMostchild('g','l');
	fTmp=NULL;
	LeftMostchild('l','m');
	fTmp=NULL;
	RightSibling('l','n');
	printf("\nINORDER TRAVERSAL:  ");
	InOrderTraversal(Root);
	count=0;
	printf("\nPOSTORDER TRAVERSAL:");
	PostOrderTraversal(Root);
	count=0;
	printf("\nPREORDER TRAVERSAL: ");
	PreOrderTraversal(Root);
	printf("\nNumber Leaves: %d",count);
	h=Height(Root);
	printf("\nHeight of Tree: %d",h);
}
