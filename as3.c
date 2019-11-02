#include<stdio.h>

void create(int [4][4],int,int);
void display(int [4][4],int,int);
void add(int [4][4],int [4][4],int [4][4]);
void multi(int [4][4],int [4][4],int [4][4]);
void transpose(int [4][4]);
void diagonal(int [4][4]);
void uppertriangular(int [4][4]);

int r=0,c=0,r1=0,c1=0; //global declearation
int main()
{
 int a[4][4],b[4][4],cc[4][4];
int ch,ch1,op;

do
{
	printf("\n\n\n\t***MENU**");
	printf("\n\n\t---------------------------------------------");
	printf("\n\n\t1.create first matrix\n\n\t2.create second matrix\n\n\t3.display 1 matrix\n\n\t4.display 2 matrix\n\n\t5.add two matrices\n\n\t6.multiply two matrices\n\n\t7.transpose of the first matrix\n\n\t8.sum of diagonal\n\n\t9.condition ofuppertriangula\n\n\t10.exit");

printf("\n\n\tenter your choice");
scanf("%d",&ch);
switch(ch)
{
	case 1:
	printf("\n\n\tfirst enter matrix A");
	printf("\n\n\tenter the size of matrix:");
	scanf("%d%d",&r,&c);
	create(a,r,c);
	break;

	case 2:
	printf("\n\n\tfirst enter matrix B");
	printf("\n\n\tenter the size of matrix");
	scanf("%d%d",&r1,&c1);
	create(b,r1,c1);
	break;

	case 3:
	printf("\n\n\t matrix A");
	display(a,r,c);
	break;
	
	case 4:
	printf("\n\n\t matrix B");
	display(b,r1,c1);
	break;

	case 5:
	if(r==r1&&c==c1)
	{
		add(a,b,cc);
		printf("\n\n\tmatrix A");
		display(a,r,c);
		printf("\n\n\tmatrix B");
		display(b,r1,c1);
		printf("\n\n\taddition of two matrices");
		display(cc,r,c);         
	}
	else
	printf("\n\n\tcan't print the addition");
	break;

	case 6:
	if(r==r1&&c==c1)
	{
		multi(a,b,cc);
		printf("\n\n\tmatrix A");
		display(a,r,c);
		printf("\n\n\tmatrix B");
		display(b,r1,c1);
		printf("\n\n\tmultiplication of two matrices");
		display(cc,r,c);         
	}
	else
	printf("\n\n\tcan't print the multiplication");
	break;

	case 7:
	if(c==r)
	{
		printf("\n\n\tmatrix A");
		display(a,r,c);
		transpose(a);
		printf("\n\n\ttranspose of matrix A");
		display(a,r,c);
		transpose(a);
	}
	else
	printf("\n\n\tnot a square matrix:");
	break;
	
	case 8:
		printf("\n\n\tmatrix A");
		display(a,r,c);
		diagonal(a);
	break;
	
	case 9:	
		printf("\n\n\tmatrix A");
		display(a,r,c);
		uppertriangular(a);
	break;
}
	printf("\n\n\tdo you want to continue");
	scanf("%d",&ch1);
	if(ch1=='n');
	break;
}
while(ch!=11);
return 0;
}

void create (int a[4][4],int r,int c)
{
	int i,j;
	printf("\n\n\tenter the elements in the matrix");
	for(i=0;i<r;i++)   //for loops are used to read the matrix
	{
	for(j=0;j<c;j++)
		scanf("%d",&a[i][j]);
	}
}

void display(int s[4][4],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
	printf("\n\n");
		for (j=0;j<c;j++)
		{
		
			printf("\t\t%d",s[i][j]);

		}
	}
}	

void add(int a[4][4],int b[4][4],int cc[4][4])
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			cc[i][j]=a[i][j]+b[i][j];
		}
	}
}

void multi(int a[4][4],int b[4][4],int cc[4][4])
{ 
	int i,k,j;
for(i=0;i<r;i++)

		for(j=0;j<c;j++)

			for(k=0;k<c1;k++)
			{cc[i][j]=0;
				cc[i][j]+=a[i][k]*b[k][j];
			}
}

void transpose(int a[4][4])
{
	int i,j,temp;
	for(i=0;i<c;i++)
	{
		for(j=0;j<i;j++)
		temp=a[i][j];
		a[i][j]=a[j][i];
		a[j][i]=temp;
	}
}

void diagonal(int a[4][4])
{
	int i,j,temp=0,n;
	n=r-1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j)
			{
				temp=temp+a[i][j];
			}
		}
	}
				printf("\n\n\taddition of left diagonal elements :%d",temp);
				temp=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i+j==n)
			{
				if(i==n/2 && j==n/2)
				temp=temp+a[i][j];
				else if(i!=j)
				temp=temp+a[i][j];
			}
		}
	}
printf("\n\n\taddition of right diagonal elements is:%d",temp);
}

void uppertriangular(int a[4][4])
{
	int i,j,temp;
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(j<i)
			{
				if(a[i][j]==0)
				temp=1;
				else
				{
					temp=0;
					break;
				}
			}
		}
	}
	if(temp==1)
	printf("\n\n\n\tgiven matrix is upper triangular");
	else
	printf("\n\n\tgiven matrix is not uppertriangular");
}






