#include<stdio.h>
void bubble(int data[15],int no);
void selection(int data[15],int no);
void insertion(int data[15],int no);

int main()
{
	int no,data[15],i,ch;	//no=total no of elements
	
	printf("\n\n\tenter total no of students:");
	scanf("%d",&no);
	
	for(i=0;i<no;i++)
	{
		printf("\n\n\tenter the roll nos:");
		scanf("%d",&data[i]);
	}
	
do
{
	printf("\n\n\t***SORTING***");
	printf("\n\n\t1.Bubble sort\n\n\t2.selection sort\n\n\t3.insertion sort");
	printf("\n\n\tEnter your choice:");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			printf("\n\n\t***BUBBLE SORT***");
			bubble(data,no);
			break;
		case 2:
			printf("\n\n\t***SELECTION SORT***");
			selection(data,no);
			break;
			
		case 3:
			printf("\n\n\t***INSERTION SORT***");
			insertion(data,no);
			break;
	}
}while(ch!=10);
return 0;
}

void bubble(int a[15],int no)
{
	int i,j,temp,k,no1;
	no1=no-1;
	

	for(i=0;i<no;i++)
	{
		for(j=0;j<no1;j++)
		{
			if(a[j]>a[j+1])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}

		}
		
	}
	
	printf("\n\n\n After sorting\t\n\n\n");
	 for(i=0;i<no;i++)
	 {
		printf("\t%d",a[i]);

	}

}

void selection(int a[15],int no)
{
	int i,j,temp,k;
	
	for(i=0;i<no;i++)
	{
		for(j=i+1;j<no;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	
//print the sorted elements
printf("\n\n\t after sorting\t\n\n");
for(i=0;i<no;i++)
{
	printf("\t%d",a[i]);
}
}

void insertion(int a[15],int no)
{
	int i,j,temp,k;

	
	for(i=1;i<no;i++)
	{
		temp=a[i];
		j=i;
		while(j>0 && (a[j-1]>temp))
		{
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=temp;

	 }
	
	
	printf("\n\n\n After sorting\t\n\n\n");
	 for(i=0;i<no;i++)
	 {
		printf("\t%d",a[i]);

	}

}
	
