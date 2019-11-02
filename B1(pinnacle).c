//pinnacle club

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void create();
void display();
void insert();
void del_pre();
void del_sec();
void count();
void reverse();
void delmem();

typedef struct sll
{
int prn;
char name[20];
struct sll *link
}sll;
sll *start,*end;

int main()
{
        int op;

do
{
        printf("\n\n\tMENU");
        printf("\n\n\t1.create the club\n\n\t2.insert a new member\n\n\t3.delete a member\n\n\t4.change the president\n\n\t5.change the secretary\n\n\t6.display members of the club\n\n\t7.count\n\n\t8.reverse\n\n\t9.exit");
        printf("\n\n\tenter your choice:");
        scanf("%d",&op);

switch(op)
{

        case 1:
                create();
                break;
                
	case 2:
		insert();
		break;
		
	case 3:
		delmem();
		break;
		
	case 4:
		del_pre();
		break;
		
	case 5:
		del_sec();
		break;
		
	case 6:
		display();
		break;
		
	case 7:
		count();
		break;
	
	case 8:
		reverse();
		break;
	
                
        case 9:
        	exit(0);
        	break;
       	
        
}
}while(op!=10);
return 0;
}


void create()
{
        sll *freshnode,*temp;
        int ch;
        
        while(1)
        {
        	if(start==NULL)
        	{
        		printf("\n\n\tEnter data for president");
        		freshnode=malloc(sizeof(sll));
        		printf("\n\n\tEnter the PRN and Name of president");
        		scanf("%d%s",&freshnode->prn,freshnode->name);
        		freshnode->link=NULL;
        		start=freshnode;
        		temp=freshnode;
        		
        		printf("\n\n\tEnter data for secretary");
        		freshnode=malloc(sizeof(sll));
        		printf("\n\n\tEnter the PRN and Name of secretary ");
        		scanf("%d%s",&freshnode->prn,freshnode->name);
        		freshnode->link=NULL;
        		end=freshnode;
        		start->link=end;
        	}
        	else
        	{
        		freshnode=malloc(sizeof(sll));
        		printf("\n\n\tenter PRN and Name of students to ente into the club");
        		scanf("%d%s",&freshnode->prn,freshnode->name);
        		freshnode->link=NULL;
        		temp->link=freshnode;
        		temp=freshnode;
        		temp->link=end;
        	}
        printf("\n\n\tdo you want to add more?");
        scanf("%d",&ch);
        if(ch==0)
        break;
        }
        
}
        		
void display()
{

	sll *temp1;
	
	if(start==NULL)
		printf("\n\n\tNO MEMBERS IN THE CLUB");
	else
	{
		printf("\n\n\t------------------------------------------");
		printf("\n\n\n\n\t\t\t\t***PINNACLE CLUB***");
		printf("\n\n\t-------------------------------------------");
		
		temp1=start;
		printf("\n\n\n\n\t\t\t\t***PINNACLE CLUB PRESIDENT***");
		printf("\n\n\t\t\t%d\t\t%s",temp1->prn,temp1->name);
		printf("\n\n\t-------------------------------------------------");
		temp1=temp1->link;
		printf("\n\n\n\n\t\t\t\t*** PINNACLE CLUB MEMBERS");
		printf("\n\n\t\tPRN\t\tName of student");
		
		while(temp1->link!=NULL)
		{
			printf("\n\n\t\t%d\t\t%s",temp1->prn,temp1->name);
			temp1=temp1->link;
		}
		printf("\n\n\t--------------------------------------------");
		printf("\n\n\n\n\t\t\t*** PINNACLE CLUB SECRETARY");
		printf("n\n\t%d\t\t\t\t%s",end->prn,end->name);
		printf("\n\n\t---------------------------------------------");
	}
}

void insert()
{
	sll *freshnode;
	
	freshnode=malloc(sizeof(sll));
	printf("\n\n\tEnter PRN and Name of student to add into club");
	scanf("%d%s",&freshnode->prn,freshnode->name);
	freshnode->link=NULL;
	freshnode->link=start->link;
	start->link=freshnode;
	display();
}

void del_pre()
{
	sll *temp;
	
	temp=start;
	start=start->link;
	free(temp);
	printf("\n\n\n\n\t Congratulation %s selected as New President   \t",start->name);
	//display();


}
void deletmem()
{
	sll *temp,*prev;
	int pos;
	temp=start;
	if(start->link==end)
		printf("\n\n\tNo Member in club only President and Secretary");
	else
	{
		printf("\n\n\tEnter the PRN  to cancle the membership");
		scanf("%d",&pos);
	   while(temp->prn!=pos)
	   {
			prev=temp;
			temp=temp->link;

	   }

	  prev->link=temp->link;
	   free(temp);

	  //display();
	}

}
void del_sec()
{
	 
	sll *temp;
	temp=start;
	while(temp->link!=end)
	{	
		temp=temp->link;	
	}
	free(temp->link);	
	temp->link=NULL;
	end=temp;	
	printf("\n\n\n\n\t Congratulation %s selected as New President   \t",end->name);
	//display();

}

void count()
{
	sll *temp1;
	int count=1;
	temp1=start;
	if(start==NULL)
		printf("\n\n\tno members in the club");
	else
	{
		while(temp1->link!=NULL)
		{
			count++;
			temp1=temp1->link;
		}
	printf("\n\n\ttotal no of members in clun are:%d including the president and the secretary",count);
	
	}
}

void reverse()
{
	sll *temp,*prev,*next;
	end=start;
	if(start==NULL)
		printf("\n\n\tno members in the club");
	else
	{
		temp=start->link;
		prev=start;
		prev->link=NULL;
		while(temp!=NULL)
		{
			next=temp->link;
			temp->link=prev;
			prev=temp;
			temp=next;
		}
		
		start=prev;
		printf("\n\n\tReverse is:");
		
	display();
	}
}
