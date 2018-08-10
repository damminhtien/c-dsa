#include<stdio.h>
#include<windows.h>
#define BUFFER_SIZE 100

int size=-1;
int buffer[100];
int i=1;

void Producer(){
	while(1){	
		while(size==BUFFER_SIZE) printf("\nFull buffer");
		buffer[size]=1;
		printf("\nBuffer in %d",size=(size+1)%BUFFER_SIZE);
	}
}

void Consumer(){
	while(1){
		while(size<=0);
		printf("\nBuffer out %d",size);
		size--;
	}
}

int main(){
	HANDLE h1, h2; DWORD Id;
	h1=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Producer,NULL,0,&Id);
	h2=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Consumer,NULL,0,&Id);
	WaitForSingleObject(h1,INFINITE);
	WaitForSingleObject(h2,INFINITE);
	return 0;
}
