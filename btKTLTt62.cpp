#include<iostream>

using namespace std;

typedef struct intStack{
	int data;
	intStack *next;
	intStack *prev;
}intStack;

intStack *creatEmptyStack(intStack *head){
	head = new intStack;
	head->next = head;
	head->prev = head;
	return head;
}

bool isEmpty(intStack *head){
	if(head->next == head) return true;
	else return false;
}

intStack *push(int data,intStack *head){
	intStack *newElm = new intStack;
	newElm->data = data;
	newElm->prev = head->prev;
	newElm->next = head;
	head->prev->next = newElm;
	head->prev = newElm;	
	return head;
}

intStack *pop(intStack *head){
	if(isEmpty(head)){
		cout << "Nothing to pop!" << endl;
	}
	else{
		head->prev = head->prev->prev;
		head->prev->next = head;
	}
	return head;
}

void traversal(intStack *head){
	cout << "Stack: "; 
	intStack *tmp;
	tmp = head->next;
	while(tmp != head){
		cout << " " << tmp->data;
		tmp = tmp->next;	
	}
}

int main(){
	intStack *head;
	head = creatEmptyStack(head);	
	int choose = 0;
	while(choose!=4){
		cout << "\n________________________________" << endl;
		cout << "Stack Manipulation: " << endl;
		cout << "1. Is Empty?" << endl;
		cout << "2. Push"   << endl;
		cout << "3. Pop"   << endl;
		cout << "4. Exit"      << endl;
		cout << "Your Choose: "; fflush(stdin); cin >> choose;
		switch(choose){
			case 1: if(isEmpty(head)) cout << "Stack is empty!\n";
					else cout << "Stack isn't empty!\n";  
					break;
			case 2: cout << "Input integer data: "; int data; fflush(stdin); cin >> data;
					head=push(data,head); traversal(head); 
					break;
			case 3: head=pop(head); traversal(head); break; 
		} 
	}
}
