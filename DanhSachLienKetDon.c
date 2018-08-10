#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int ElementType;
struct _PointerType{
  ElementType Inf;
  struct _PointerType *Next;
};
typedef struct _PointerType PointerType;

PointerType *InsertMiddle(PointerType *Prev, ElementType X)
{
  PointerType *TempNode;
  
  TempNode = (PointerType *)malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = Prev->Next;
  Prev->Next = TempNode;
  
  return TempNode;
}

ElementType Delete(PointerType *Prev){
  ElementType X;
  PointerType *TempNode;
  
  TempNode = Prev->Next; Prev->Next = Prev->Next->Next;
  X = TempNode->Inf;
  free(TempNode);
  
  return X;
}

PointerType *InsertToHead(PointerType *First, ElementType X){
  PointerType *TempNode;
  
  TempNode = (PointerType *) malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = First;
  First = TempNode;
  
  return First;
}

PointerType *InsertToLast(PointerType *First, ElementType X){
  PointerType *NewNode; PointerType *TempNode;

  NewNode = (PointerType *)malloc(sizeof(PointerType));
  NewNode->Inf = X;NewNode->Next = NULL; 
  TempNode = First;
  
  while(TempNode->Next!=NULL)
    TempNode = TempNode->Next;
  
  TempNode->Next = NewNode;
  return First;
}

PointerType *DeleteHead(PointerType *First){
  PointerType *TempNode;
  
  TempNode = First->Next;
  free(First);
  
  return TempNode;
}

PointerType *DeleteLast(PointerType *First){
  PointerType *Temp1,*Temp2;
  Temp1 = First; Temp2 = First;
  
  while(Temp1->Next != NULL){
   Temp2 = Temp1;
   Temp1 = Temp1->Next;}
  
  Temp2->Next = NULL;
  free(Temp1);
  return First;
}

int IsEmpty(PointerType *First)
{
  return !First;
}

PointerType *MakeNull(PointerType *First)
{
  while(!IsEmpty(First))
   First=DeleteHead(First);
  return First;
}

void Print(PointerType *First){
  PointerType *TempNode;
  
  printf("%ld ",First);
  TempNode = First;
  while(TempNode!=NULL){
   printf("%d:%ld ",TempNode->Inf,TempNode->Next);
   TempNode = TempNode->Next;
  }
  printf("\n");
}

// Than chuong trinh chinh
int main(){
    PointerType *ds=NULL,*pv=NULL;
    int i,p;
    // Chen 6 gia tri vao vi tri dau
    ds = InsertToHead(ds,1);ds = InsertToLast(ds,2);//ds = InsertToHead(ds,3);
    //ds = InsertToHead(ds,4);ds = InsertToHead(ds,5);ds = InsertToHead(ds,6);
    // In ra danh sach sau khi chen
    printf("In ra danh sach sau khi chen vao dau \n");
    Print(ds);
    // Chen so 7 vao vi tri cuoi cua danh sach
    //printf("Danh sach sau khi chen 7 vao cuoi \n");
    //ds = InsertToLast(ds,7);
    //Print(ds);
    
    // In ra danh sach sau khi xoa phan tu dau
    //printf("In ra danh sach sau khi xoa dau \n");
    //ds = DeleteHead(ds);
    //Print(ds);
    // In ra danh sach sau khi xoa phan tu cuoi
    //printf("In ra danh sach sau khi xoa cuoi \n");
    //ds = DeleteLast(ds);
    //Print(ds);
    
    // In ra danh sach sau khi xoa phan tu dau
    /*printf("Cho vi tri ban muon chen 7 vao sau p = ");scanf("%d",&p);
    pv = ds;i=1;
    while(i<p){pv = pv->Next;i++;}
    InsertMiddle(pv,7);
    Print(ds);*/
    
    
      
    getch();
    return 0;
}
