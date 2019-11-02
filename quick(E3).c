#include<stdio.h>

void quick(int[],int,int);
int partition(int[],int,int);

int main()
{
	int no,ele[15],i,ch;
	
	printf("\n\n\tenter total no of elements:");
	scanf("%d",&no);
	
	for(i=0;i<no;i++)
	{
		printf("\n\n\tenter the elements:");
		scanf("%d",&ele[i]);
	}

do
{
	printf("\n\n\t***SORTING***");
	printf("\n\n\t1.quick sort");
	printf("\n\n\tenter your choice:");
	scanf("%d",&ch);
	
switch(ch)
{
	case 1:
		printf("\n\n\tquick sort");
		quick(ele,0,no-1);
		printf("\n\n\tsorted array is:");
		for(i=0;i<no;i++)	
		printf("%d\t",ele[i]);
		break;
}
}while(ch!=10);
return 0;
}

void quick(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick(a,l,j-1);
		quick(a,j+1,u);
	}
}

int partition(int a[],int l,int u)
{
	int key,i,j,temp;
	
	key=a[l];
	i=l;
	j=u+1;
	
do
{	do
	i++;
	
	while(a[i]<key && i<=u);
	
	do
		j--;
	while(a[j]>key);
	
	if(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
while(i<j);

a[l]=a[j];
a[j]=key;
return(j);
}
