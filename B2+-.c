
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void create();
void delete();
void display();
void separate();
void sort();
void merge();


typedef struct sll
{
int data;
struct sll *link;
}sll;



sll *start=NULL,*start1=NULL,*startN=NULL,*startP=NULL,*startM=NULL;


void main()
{
 int op;

do
{

	printf("\n\n\n\t\t\t***MENU***");
	printf("\n\n\t-------------------------------------------------------------");
	printf("\n\n\t1.Create\n\n\t2.Display\n\n\t3.Delete Negative nos");
	printf("\n\n\t4.Separate positive Numbers and Negative no List\n\n\t5.Merge");
	printf("\n\n\tEnter your choice \t");
	scanf("%d",&op);
		switch(op)
		{
			case 1:

				create();
				break;
			case 2:

				display(start);
				break;
			case 3:

				delete();
				break;
			case 4:
				separate();
				break;
			case 5:
				merge();
				break;


		}
	} while(op!=7);



}
void create()
{

	sll *freshnode,*temp,*temp1;
	int ch;

		while(1)
	{
		freshnode=(sll*)malloc(sizeof(sll*));
		printf("\n\n\n\n\tEnter data for new node\t");
		scanf("%d",&freshnode->data);
		freshnode->link=NULL;
		if(start==NULL)
		{
			start=freshnode;
			temp=freshnode;
		}
		else
		{
			temp->link=freshnode;
			temp=freshnode;
		}
	   printf("\n\n\t\tU want add more ?\t");

	  scanf("%d",&ch);
		if(ch==0)
		break;
	}
	
	//duplicate list
	temp1=start;
	while(temp1!=NULL)
	{
			freshnode=(sll*)malloc(sizeof(sll*));
			freshnode->data=temp1->data;
			freshnode->link=NULL;
		if(temp1==start)
		{
			
			start1=freshnode;
			temp=start1;
			temp1=temp1->link;
		}
		else
		{
			
			temp->link=freshnode;
			temp=temp->link;
			temp1=temp1->link;
		}
	}
	
}

void display(sll *dstart)
{

	sll *temp1;

	if(dstart==NULL)
		printf("\n\n\n\tList is empty");
	else
	{
		printf("\n\n\n\t\t***List***");
		printf("\n\n\n\tDATA\t\tAddress");
		printf("\n\n\t-----------------------------------------------");
		temp1=dstart;
		while(temp1!=NULL)
		{
			printf("\n\n\t%d\t\t%p",temp1->data,temp1->link);
			temp1=temp1->link;
		}
		printf("\n\n\t-----------------------------------------------");
	}
}

void delete()
{
	sll *temp1,*temp,*prev;
	prev=start;
	temp=start->link;

	while(temp!=NULL)
        {
        if(start->data<0)
      	{
		temp1=start;
		prev=temp;
		start=start->link;
		temp=temp->link;
		free(temp1);
  	}
	if(temp->data<0)
	{
		temp1=temp;
		prev->link=temp->link;		
   	   	temp=temp->link;		   	   	
		free(temp1);
	}
	else
	{
		prev=temp;
		temp=temp->link;

	}
	}

}
  	
void separate()
{

	sll *temp1,*temp,*prev,*freshnode,*temp2;

	temp=start1;
	startP=start;
 while(temp!=NULL)
 {
if(temp->data<0)
{
			   		
	if(startN==NULL)
	{
		freshnode=(sll*)malloc(sizeof(sll*));
		freshnode->data=temp->data;
		freshnode->link=NULL;
		startN=freshnode;
		temp2=startN;
		temp=temp->link;
	}
	else
	{

		freshnode=(sll*)malloc(sizeof(sll*));
		freshnode->data=temp->data;
		freshnode->link=NULL;
		temp2->link=freshnode;
		temp2=freshnode;
		temp=temp->link;
				   	}

	}
	else
	{
		temp=temp->link;
	}

}

printf("\n\n\n\t\tPositive No List");
display(startP);
printf("\n\n\n\t\tNegative  No List");
display(startN);
}


void merge()
{
	sll *temp;
	        printf("\n\n\t\tList After Sorting");
	        printf("\n\n\t\tPositive no List After Sorting");
		sort(startP);
		printf("\n\n\t\tPositive no List After Sorting");
		sort(startN);
		startM=startP;
		temp=startM;
		while(temp->link!=NULL)
		{

			temp=temp->link;
		}
			temp->link=startN;
	
	printf("\n\n\t\tList After Sorting");
	display(startM);
}


void sort(sll *dstart)
{
	sll *temp,*temp1;
	int i;
	temp=temp1=dstart;

	while(temp!=NULL)
	{
	while(temp1->link!=NULL)
	{
		if(temp1->data<temp1->link->data)
		{
			i=temp1->data;
			temp1->data=temp1->link->data;
			temp1->link->data=i;
		}
			temp1=temp1->link;
		}
	temp1=dstart;
	temp=temp->link;
	 }
}
