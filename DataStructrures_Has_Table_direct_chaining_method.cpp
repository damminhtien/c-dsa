#include<stdio.h>
#include<stdlib.h>
#define M 10

typedef struct NodeType{
	int key;
	NodeType *next;
};

NodeType *bucket = NULL;

void Initialize(){
	bucket = (NodeType*) malloc (M*sizeof(NodeType));
	for(int i = 0; i < M; i++){
		(&bucket[i])->key = 0;
		(&bucket[i])->next = NULL;
	}
}

void Insert(int key){
	int i = key % M;
	NodeType *temp = NULL;
	temp = &bucket[i];
	while(temp->next != NULL) temp = temp->next;
	NodeType *temp0;
	temp0 = (NodeType*) malloc (sizeof(NodeType));
	temp0->key = key;
	temp0->next = NULL; 
	temp->next = temp0;
}

void Traverse(){
	for(int i = 0; i < M; i++){
		NodeType *temp = NULL;
		temp = &bucket[i];
		if(temp->next == NULL) printf("Bucket %d is empty!",i);
		else{
			printf("Bucket %d: ",i);
			while(temp->next != NULL){
				temp = temp->next;
				printf("%d ",temp->key);
			}
		}
		printf("\n");
	}
}

main(int arg, char** args){
	Initialize();
	for(int i=0;i<M;i++){
		printf("%d  :  %ld\n",i,bucket + i*sizeof(NodeType));	
	} 
	Insert(1);
	Insert(11);
	Insert(1002);
	Insert(4073);
	Traverse();
	free(bucket);
}
