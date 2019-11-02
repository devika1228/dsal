#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct cq
{
	int data[MAX];
	//char name[20];
	int rear,front;
}cq;

void insert(cq*,int x);
void display(cq*);
void pop(cq*);

int main()
{
	int x,ch,token=99;
	char name[20];
	cq q;
	q.front=-1;
	q.rear=-1;
	
do
{
	printf("\n\n\t***PIZZA PARLOUR***");
	printf("\n\n\t1.place your order\n\n\t2.dispatch the order\n\n\t3.display");
	printf("\n\n\tenter your choice:");
	scanf("%d",&ch);
	
switch(ch)
{
	
	case 1:
		printf("\n\n\tplz place your order\n\n\tenter the name of item:");
		scanf("%s",name);
		token++;
		printf("\n\n\tthank you!!!\n\n\tyour token no is:%d",token);
		insert(&q,token);
		break;
		
	case 2:
		pop(&q);
		break;
		
	case 3:
		display(&q);
		break;
		
}
}
while(ch!=11);
return 0;
}

void insert(cq *q,int x)
{
	if(q->rear==MAX-1 && q->front==0)
		printf("\n\n\tsorry cant accept your order.");	//the q is full!
	else
	{
		if(q->rear==-1 && q->front==-1)
		{
			q->front=0;
			q->rear=0;
		}
		else
			if(q->rear==MAX-1 && q->front!=0)
			q->rear=0;
		else
			q->rear=q->rear+1;
			q->data[q->rear]=x;
	}
}

void display(cq *q)
{
	int i;
	
	printf("\n\n\t***pending orders***");
	if(q->front==-1)
	printf("\n\n\tthere are no orders");
	
	else if(q->rear==q->front)
	{
		for(i=q->front;i<=q->rear;i++)
		printf("\n\n\t%d\n",q->data[i]);
	}
	else
	{
		for(i=q->front;i<=q->rear;i++)
		printf("\n\n\t%d\n",q->data[i]);
		/*for(i=0;i<=q->rear;i++)
		printf("\n\n\t%d\n",q->data[i]);*/
	}
}

void pop(cq *q)
{
	if(q->front==-1)
	printf("\n\n\tthere are no orders");
	else
	{	
		printf("\n\n\torder is served for token no:%d\n",q->data[q->front]);
	
	if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	else
	{
		if(q->front==MAX-1)
			q->front=0;
		else
			q->front=q->front+1;
	}
	}
}	
	
