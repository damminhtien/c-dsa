#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAXLENGHT 10
typedef int ElementType;
ElementType *array;
int Front=0,Rear=0;
int Size=0;
int IsEmpty(){
	return !Size;
}
int IsFull(){
	return Size==MAXLENGHT;
}
void Enqueue(ElementType X){
	if(IsFull()) printf("\nCan't enqueue %d, Queue is full !",X);
	else{
		printf("\nEnqueue %d",X);
		*(array+Rear)=X;
		Rear=(Rear+1)%MAXLENGHT;
		Size++;
	}
}
void Dequeue(){
	if(IsEmpty()){
		printf("\nError, Queue is Empty !");
	}
	else{
		printf("\nDequeue %d",*(array+Front));
		*(array+Front)=-1;
		Front=(Front+1)%MAXLENGHT;
		Size--;
	}
}
void Print(){
	printf("\nQueue:");
	for(int i=0;i<MAXLENGHT;i++) printf("%5d",*(array+i));
}
int main(){
	array=(ElementType*)malloc(MAXLENGHT*sizeof(ElementType));
	for(int i=0;i<MAXLENGHT;i++) *(array+i)=-1;
	for(int i=0;i<9;i++) Enqueue(i);
	Print(); 
	printf("\nFront: %d, Rear: %d",Front,Rear);
	for(int i=0;i<7;i++) Dequeue();
	Print();
	printf("\nFront: %d, Rear: %d",Front,Rear); 
	for(int i=0;i<5;i++) Enqueue(i);
	Print();
	printf("\nFront: %d, Rear: %d",Front,Rear);
	for(int i=10;i<15;i++) Enqueue(i);
	Print();
	printf("\nFront: %d, Rear: %d",Front,Rear);
	for(int i=0;i<5;i++) Dequeue();
	Print();
	printf("\nFront: %d, Rear: %d",Front,Rear);
	
}
