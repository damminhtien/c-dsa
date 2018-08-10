#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct qnode{
	int item;
	qnode *next;
};
struct queue{
	qnode *front;
	qnode *rear;
};
// khoi tao 
queue *khoi_tao()
{
	queue *q;
	q=(queue *)malloc(sizeof(queue));
	if(q==NULL) return NULL;
	else{
		q->front=NULL;
		q->rear=NULL;
	}
	return q;
}
queue *isFull(queue *q){
	if(q==NULL) printf("hang doi full");
	return q;
}
int isEmpty(queue *q){
	
	return ((q->rear==NULL)&&(q->front==NULL));
}
// them phan tu vao hang doi
queue *enqueue (queue *q, int x){
	qnode *node;
	node=(qnode *)malloc(sizeof(qnode));
	if(isEmpty(q))
	{node->item=x;
	q->front=node;
	q->rear=node;
	node->next=NULL;
	}
	else
	{
		node->item=x;
		q->rear->next=node;
		q->rear=node;
		node->next=NULL;
	}
	return q;
}
queue *dequeue(queue *q)
{
	qnode *node;
	if(q->front==NULL && q->rear==NULL)
	isEmpty(q);
	else{
		node=q->front;
		q->front=q->front->next;
		if(q->front==NULL)
		q->rear=NULL;
		node->next=NULL;
	}
	return q;
}
void print(queue *q){
	printf("danh sach phan tu trong hang doi la:\n");
	qnode *node;
	int m;
	node=q->front;
	do{
	m=node->item;
	printf("%2d",m);
	node=node->next;
	}
	while(node!=NULL);	
}
int main()
{
	
	queue *hd;
	hd=khoi_tao();
	hd=enqueue(hd,1); 


	hd=enqueue(hd,3);
	print(hd);
	return 0;
}
