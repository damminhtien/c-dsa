#include<iostream>

using namespace std;

typedef struct intQueue{
	int data;
	intQueue *next;
	intQueue *prev;
}intQueue;

intQueue *creatEmptyQueue(intQueue *head){
	head = new intQueue;
	head->next = head;
	head->prev = head;
	return head;
}

bool isEmpty(intQueue *head){
	if(head->next == head) return true;
	else return false;
}

intQueue *enqueue(int data,intQueue *head){
	intQueue *newElm = new intQueue;
	newElm->data = data;
	newElm->prev = head->prev;
	newElm->next = head;
	head->prev->next = newElm;
	head->prev = newElm;	
	return head;
}

intQueue *dequeue(intQueue *head){
	if(isEmpty(head)){
		cout << "Nothing to dequeue!" << endl;
	}
	else{
		head->next = head->next->next;
		head->next->prev = head;
	}
	return head;
}

void traversal(intQueue *head){
	cout << "Queue: "; 
	intQueue *tmp;
	tmp = head->next;
	while(tmp != head){
		cout << " " << tmp->data;
		tmp = tmp->next;	
	}
}

int main(){
	intQueue *head;
	head = creatEmptyQueue(head);	
	int choose = 0;
	while(choose!=4){
		cout << "\n________________________________" << endl;
		cout << "Queue Manipulation: " << endl;
		cout << "1. Is Empty?" << endl;
		cout << "2. Enqueue"   << endl;
		cout << "3. Dequeue"   << endl;
		cout << "4. Exit"      << endl;
		cout << "Your Choose: "; fflush(stdin); cin >> choose;
		switch(choose){
			case 1: if(isEmpty(head)) cout << "Queue is empty!\n";
					else cout << "Queue isn't empty!\n";  
					break;
			case 2: cout << "Input integer data: "; int data; fflush(stdin); cin >> data;
					head=enqueue(data,head); traversal(head); 
					break;
			case 3: head=dequeue(head); traversal(head); break; 
		} 
	}
}
