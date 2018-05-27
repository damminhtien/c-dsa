#include<iostream>
#include<string>
#include<string.h>
#include <fstream> 
using namespace std;

string a = ".abcdefghijklmnopqrstuvwxyz ";
int b[150] ={};

void initAlpha(){
	b[32] = 27;
	int j =0;
	for(int i = 97; i <= 122; i++){
		b[i] = ++j;
	}	
}

typedef struct list{
	char content[255];
	int code;
	list *next;
}list;

list *head;

void initMap(){
	head = new list;
	head->next = head;
}

int encode(char *s){
	char c = s[0];
	int i = 0;
	int code = 0;
	while(s[i]!= '\0'){
		if(b[s[i]] >= 10) code = code*100+b[s[i]];
		else code = code*10+b[s[i]];
		i++;
	}
	return code;
}

char *decode(int code){
	list *temp;
	temp = head->next;
	while(temp != head){
		if(code == temp->code) return temp->content;
		else temp = temp->next;
	} 
	if(temp == head) return NULL;
}

//void inputPara(){
//	int map[500];
//	fstream file("doan van.txt");
//    char temp[255];
//	fflush(stdin);
//	int i = 0;
//	while(file.getline(temp,255)) {
//		cout << "Input para: " << temp << endl;
//		while(temp[i] != '\0'){
//			map[i] = b[temp[i]];
//			i++;
//		}
//	}
//	cout << "Encode: ";
//	for(int j=0;j<i;j++){
//		cout << map[j];	
//	}
//	cout << "\n_____________________________________________________";
//	cout << "\nDecode:\n";
//	int wordCode = 0;
//	for(int j=0;j<i;j++){
//		if(map[j] > 26 || map[j] < 1){
//			cout << wordCode;
//			cout << " " << decode(wordCode) << endl;
//			wordCode = 0;	
//		} 
//		else{
//			if(map[j] >= 10) wordCode = wordCode*100 + map[j];
//			else wordCode = wordCode*10 + map[j];	
//		}  
//	}
//}

void inputDic(){
	fstream file("tu dien.txt");
    char temp[255];
	fflush(stdin);
	while(file.getline(temp,255)) {
		list *newE = new list;
		strcpy(newE->content,temp);
		newE->code = encode(temp);
		newE->next = head->next;
		head->next = newE;
	}
}

int main(){
	initMap();
	initAlpha();
	inputDic();
//	inputPara();
	cout << decode(11212);
	return 0;
}

