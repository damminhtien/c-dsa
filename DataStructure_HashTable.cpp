#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct hashItem{
	int data;
	int key;
};
hashItem *hashTable;
int size = 0;

void createTable(){
	printf("Size: ");
	scanf("%d",&size);
	hashTable = (hashItem*) malloc(size * sizeof(hashItem)); 
	for(int i = 0; i < size;i++){
		hashTable[i].data = -1;
		hashTable[i].key =-1;
	}
	for(int i = 0; i < size; i++){
		int tData = 0;
		int tKey = 0;
		printf("Input data of element %d: ",i+1);
		scanf("%d",&tData);
		printf("Input key of element %d : ",i+1);
		scanf("%d",&tKey);
		int index = tKey % size;
		while(hashTable[index].key != -1){
			index++;
			index = index % size;
		}
		hashTable[index].data = tData;
		hashTable[index].key = tKey;
	}
}

void showTable(){
	printf("Hash Table\nData____________________Key \n");
	for(int i = 0;i < size;i++){
		printf(" %d          |           %d \n",hashTable[i].data,hashTable[i].key);
	}
}

hashItem search(int sKey){
	hashItem null;
	int index = sKey % size;
	int flag = index; // thong bao vi tri noi bat dau & ket thuc loop
	while(hashTable[index].key != sKey){
	++index;
	if(index == flag){
		printf("Key not found!!!\n");
		return null;
	}	
	} 
	return hashTable[index];
}

int main(int arg,char **args){
	createTable();
	showTable();
	free(hashTable);
	hashItem fData;
	printf("Input key of find-data: ");
	int key;
	scanf("%d",&key);
	fData = search(key);
	printf("Data: %d",fData.data);
	return 0;
}
