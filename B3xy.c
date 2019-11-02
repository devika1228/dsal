#include<stdio.h>
#include<stdlib.h>

struct sll *   create();
void sort();
void merge();
void display();


typedef struct sll
{
	int data;
	struct sll *link;
}sll;


sll *start1,*start2,*start3;

int main()
{
	 int op;
	 start1=NULL;start2=NULL;start3=NULL;

do
{

	printf("\n\n\n\t\t\t*** MENU ***");
	printf("\n\n\t-------------------------------------------------------------");
	printf("\n\n\t1.Create First list\n\n\t2.Create Second List\n\n\t3.Display First");
	printf("\n\n\t4.Display Second\n\n\t5.Sort both List\n\n\t6.Merge lists\n\n\t7.Exit");
	printf("\n\n\tEnter your choice \t");
	scanf("%d",&op);
switch(op)
{
	case 1:
		printf("\n\n\n\t\t*** First List  ***");
		start1=create();
		break;
	
	case 2:
		printf("\n\n\n\t\t*** Second List  ***");
		start2=create();
		break;

	case 3:
		printf("\n\n\n\t\t*** First List  ***");
		display(start1);
		break;
		
	case 4:
		printf("\n\n\n\t\t*** Second List  ***");
		display(start2);
		break;
		
	case 5:
		sort(start1);
		printf("\n\n\t\t***first list sorted ***\n");
		display(start1);
		//second list
		sort(start2);
		printf("\n\n\t\t*** second list sorted ***\n");
		display(start2);
		break;
		
	case 6:
		printf("\n\n\t\t*** Merged List ***\n");
		merge();
		display(start3);
		break;
			
}
} while(op!=7);

return(0);

}

struct sll *create()
{

	sll *freshnode,*temp;
	sll *start=NULL;
	int ch=0;

while(1)
{
	freshnode=malloc(sizeof(sll));
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
printf("\n\n\t\twanna continnue?\t");
scanf("%d",&ch);
if(ch==0)
break;

}
return(start);
}

void display(struct sll *start)
{

sll *temp1;

if(start==NULL)
{
	printf("\n\n\n\tList is empty");
}
else
	printf("\n\n\n\tDATA\t\tAddress");
	printf("\n\n\t-----------------------------------------------");
	temp1=start;
while(temp1!=NULL)
{
	printf("\n\n\t%d\t\t%p",temp1->data,temp1->link);
	temp1=temp1->link;
}

}



void sort(sll *startt)
{
	sll *temp,*temp1;
	int i;
	temp=temp1=startt;

while(temp!=NULL)
{
	while(temp1->link!=NULL)
	{
	if(temp1->data>temp1->link->data)
	{
		i=temp1->data;
		temp1->data=temp1->link->data;
		temp1->link->data=i;
	}
		temp1=temp1->link;
	}
temp1=startt;
temp=temp->link;
}
}

	
void merge()
{
	 sll *temp1,*temp2,*freshnode;

	 temp1=start1,temp2=start2;

while(temp1!=NULL && temp2!=NULL)
{
if(temp1->data<temp2->data)
{
	if(start3==NULL)
	{
		start3=temp1;
		freshnode=temp1;
		temp1=temp1->link;

	}
	else
	{
		freshnode->link=temp1;
		freshnode=temp1;
		temp1=temp1->link;
		
	}

}
else
{
	if(start3==NULL)
	{
		start3=temp2;
		freshnode=temp2;
		temp2=temp2->link;
		
	}
	else
	{
		freshnode->link=temp2;
		freshnode=temp2;
		temp2=temp2->link;
			  
	}
}

}
while(temp1!=NULL)
{
	freshnode->link=temp1;
	freshnode=temp1;
	temp1=temp1->link;
}
while(temp2!=NULL)
{
	freshnode->link=temp2;
	freshnode=temp2;
	temp2=temp2->link;
}

}


