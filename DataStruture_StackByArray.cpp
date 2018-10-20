#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef int ElementType;
ElementType *array;
int N=0;
int IsEmpty(){
	return !N;
}
int Size(){
	return N;
}
void Push(ElementType X){
	*(array+(++N))=X;
}
void Print(){
	printf("\nStack:  ");
	for(int i=1;i<=N;i++) printf("%d   ",*(array+i));
}
ElementType *Pop(){
	return array+(N--);
}
ElementType *Top(){
	return array+N;
}
int main(){
	Beep(1000,200);
	system("color a0");
	Sleep(200);
	Beep(2000,200);
	system("color b0");
	Sleep(500);
	Beep(3000,200);
	system("color c0");
	Sleep(500);
	Beep(4000,200);
	system("color d0");
	printf("Is Empty: %d",IsEmpty());
	array=(ElementType*)malloc(sizeof(ElementType));
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	Print();
	printf("\nSize: %d",Size());
	ElementType *Temp;
	Temp=Pop();
	printf("\nPop: %d",*Temp);
	printf("\nSize: %d",Size());
	Print();
	printf("\nIs Empty: %d",IsEmpty());
	ElementType *GetTop;
	GetTop=Top();
	printf("\nGet Top: %d",*GetTop);
	printf("\nSize: %d",Size());
	Print();
}
