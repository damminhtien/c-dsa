#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct PointerType{
	ElementType Inf;
	PointerType *Next;
}PointerType;

void *InsertToMiddle(PointerType *Prev,ElementType X){
	PointerType *Newnode=NULL;
	Newnode=(PointerType*) malloc(sizeof(PointerType));
	if(Newnode==NULL) exit(1);
	Newnode->Next=Prev->Next;
	Prev->Next=Newnode;
	Newnode->Inf=X;
}
int Found(PointerType *First,ElementType X){
	PointerType *Tempnode=NULL;
	int Count=1;
	Tempnode=First;
	if(Tempnode->Inf==X){
			return Count;
		} 
	while(Tempnode->Next!=NULL){
		if(Tempnode->Inf==X){
			return Count;
		} 
		Tempnode=Tempnode->Next;
		Count++;
	}
	return 0;	
}
PointerType *InsertToHead(PointerType *First,ElementType X){
	PointerType *Tempnode=NULL;
	Tempnode=(PointerType*) malloc(sizeof(PointerType));
	if(Tempnode==NULL) exit(1);
	Tempnode->Inf=X;
	Tempnode->Next=First;
	return Tempnode;
}
void Printf(PointerType *First){
	PointerType *Tempnode=NULL;
	Tempnode=First;
	printf("Address Data\n");
	printf("%ld ",Tempnode);
	while(Tempnode!=NULL){
		printf("%d\n%ld ",Tempnode->Inf,Tempnode->Next);
		Tempnode=Tempnode->Next;
	}
}
PointerType *InsertToLast(PointerType *First,PointerType *Last,ElementType X){
	PointerType *Newnode=NULL,*Tempnode=NULL;
	Newnode=(PointerType*) malloc(sizeof(PointerType));
	if(Newnode==NULL) exit(1);
	Newnode->Inf=X;
	Newnode->Next=NULL;
	Tempnode=First;
	while(Tempnode->Next!=NULL)
		Tempnode=Tempnode->Next;
	Tempnode->Next=Newnode;
	Last=Newnode;
	return First;
}
void Delete(PointerType *Prev){
	PointerType *Tempnode;
	Tempnode=Prev->Next;
	Prev->Next=Prev->Next->Next;
	free(Tempnode);
}
PointerType *DeleteHead(PointerType *First){
	PointerType *Tmp=NULL;
	Tmp=First;
	First=First->Next;
	free(Tmp);
	return First;
}
void DeleteLast(PointerType *First){
	PointerType *Tmp1=NULL,*Tmp2=NULL;
	Tmp1=First;
	while(Tmp1->Next!=NULL){
		Tmp2=Tmp1;
		Tmp1=Tmp1->Next;	
		}
	Tmp2->Next=NULL;
	free(Tmp1);
}
int IsEmpty(PointerType *First){
	return !First;
}
PointerType *MakeNull(PointerType *First){
	while(!IsEmpty(First)) First=DeleteHead(First);
	return First;
}
int NumberNodes(PointerType *First){
	PointerType *Tempnode=NULL;
	int Count=1;
	Tempnode=First;
	while(Tempnode->Next!=NULL){
		Tempnode=Tempnode->Next;
		Count++;
	} 
	return Count;
}
void SwapNodes(PointerType *First,int i,int j){
	PointerType *Tmp1=NULL,*Tmp2=NULL;
	int m=1,n=1;
	Tmp1=First;Tmp2=First;
	while(m<i){
		Tmp1=Tmp1->Next;
		m++;
	}
	while(n<j){
		Tmp2=Tmp2->Next;
		n++;
	}
	ElementType tmp=Tmp2->Inf;
	Tmp2->Inf=Tmp1->Inf;
	Tmp1->Inf=tmp;

}
void StraightSelectionSortList(PointerType *First){
	PointerType *Tmp1=NULL,*Tmp2=NULL;
	Tmp1 = First->Next;
	while(Tmp1 != NULL){
		
	}
}

int main(){
	PointerType *List=NULL,*Previous=NULL;
	PointerType *First=List;
	PointerType *Last=List;
	int Position=0,count=2;
	List=InsertToHead(List,6);
	List=InsertToHead(List,4);
	List=InsertToHead(List,3);
	List=InsertToHead(List,2);
	List=InsertToHead(List,1);
	List=InsertToHead(List,0);
		printf("Choose position that want to insert 5: ");
		scanf("%d",&Position);
		if(Position==1) List=InsertToHead(List,5);
		else{
		Previous=List;
		while(count<Position){
			Previous=Previous->Next;
			count++;
		}
	InsertToMiddle(Previous,5);
	}
	List=InsertToLast(List,Last,10);
	Printf(List);
		count=2;
		printf("\nChoose position that want to delete: ");
		scanf("%d",&Position);
		if(Position==1) List=DeleteHead(List); 
		else{
		if(Position==8) DeleteLast(List);
		else{
		Previous=List;
		while(count<Position){
			Previous=Previous->Next;
			count++;
		}
	Delete(Previous);
	}}
	Printf(List);
	SwapNodes(List,1,2);
	printf("\n");
	Printf(List);
	printf("\nThere are %d node(s)",NumberNodes(List));
	printf("\nPosition of 2: %d",Found(List,2));
	printf("\n%d",Last->Inf);
}

