#include<stdio.h>
#include<stdlib.h>

#define MAX 4

void insert(int[],int);
int delete(int[]);
void display();

int q[MAX];
int front=-1,rear=-1;

int main()
{
	int key;
	int ch,x;
	do
	{
	printf("\n\t**MENU**");
	printf("\n\t_______________________________");
	printf("\n\t1.Enter Job into Queue\n\t2.Delete Job from Queue\n\t3.Display Queue\n\t4.Exit");
	printf("\n\t_______________________________");
	printf("\n\n\tEnter your choice");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			insert(q,key);
			break;

		case 2:
			x=delete(q);
			printf("\n\tJob sent to execution is:%d",x);
			break;

		case 3:
			display();
			break;
	
		case 4:
			exit(0);
			break;
	}
}while(ch!=5);
return 0;
}

void insert(int q[MAX],int key)
{
	
	printf("\n\tEnter job:");
	scanf("%d",&key);
	
	if(rear==MAX-1)
	{
		printf("\n\tQueue is FULL");
	}
	else
	if(front==-1&&rear==-1)
	{
		front++;
		rear++;
		q[rear]=key;
	}
	else
	{
		rear++;
		q[rear]=key;
	}
}

int delete(int q[MAX])
{
	int temp;
	temp=q[front];
	if(front==-1)
	{
		printf("\n\tQueue is Empty");
	}
	else
	if(front==rear)
	{
		rear=front=-1;
		
		printf("\n\tNo job to send for execution");
	}
	else
	{
		front++;
		
		
	}
return(temp);
}

void display()
{
	int i;
	printf("\n\tThe Jobs present in the Queue are:");
	for(i=front;i<=rear;i++)
	{
		
		printf("\n\t%d",q[i]);
	}
}
