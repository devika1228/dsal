# include<stdio.h>
# include<stdlib.h>

void bubble_sort(int[],int);//used in binary search
void linear_search(int[],int,int);
void binary_search(int[],int,int);

int main()
{
	int ch,n,key,i;
	int a[30];
	do
	{
	printf("\n\t**MENU**");
	printf("\n\t1.Linear Search\n\t2.Binary Search\n\t3.Exit");

	printf("\n\n\tEnter your choice");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			printf("\n\t***LINEAR SEARCH***");
			printf("\n\t-----------------------------------");
			printf("\n\tEnter the total number of students:");
			scanf("%d",&n);
		
			printf("\n\tEnter the Roll nos. of the students:");
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}

			printf("Enter the roll no to be searched:");
			scanf("%d",&key);
			
			linear_search(a,key,n);
			break;

		case 2:
			printf("\n\t***BINARY SEARCH***");
			printf("\n\t___________________________________");
			printf("\n\tEnter the total number of students:");
			scanf("%d",&n);
			
			printf("\n\tEnter the Roll nos. of the students:");
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}

			printf("Enter the roll no to be searched:");
			scanf("%d",&key);
	
			binary_search(a,key,n);
			break;

		case 3:
			exit(0);
			break;
		
		
	}
}while(ch!=4);
	
}



void linear_search(int a[30],int key,int n)
{
	int flag=0,i=0;
	for(i=0;i<n;i++)
	{	
		if(a[i]==key)
	{
		printf("\n\tStudent was present for the traning program");
		flag=1;
		break;
	}
	else
	
		flag=0;
	
	}	
	
	if(flag==0)
	
	printf("\n\tStudent was not present for the traning program");
	
}


void binary_search(int a[30],int key,int n)
{

	int i,j,k,mid;
	bubble_sort(a,n);
	i=0;
	j=n-1;
	mid=(i+j)/2;
	
	for(k=0;k<=n+1;k++)
	{
		if(key>a[mid])
		i=mid+1;

		if(key<a[mid])
		j=mid-1;

		if(key==a[mid])
			break;
		mid=(i+j)/2;
	}
	if(k<=n)
	printf("\n\t Studesnt was present for the program");
	else
	printf("\n\tStudent was not present for the program");
}


void bubble_sort(int a[30],int n)
{
int temp;
int i,j=0;

	for(j=0;j<n;j++)
	{
		for(i=0;i<(n-1);i++)
		{
			if(a[i]>a[i+1])
			{
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
			}
		}
	}
}
