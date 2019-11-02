#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int length(char[]);

void reverse1(char[]);

void pallindrome(char[]);
void copy(char[],char[]);
void concat(char[],char[]);
void compare(char[],char[]);
void count(char[]);
int main()
{
	char *str,str1[100],str11[100];
	int result,op,ch;
do
{



	printf("\n\n\n\t\t***MENU***");
	printf("\n\n\t******************************************");
	printf("\n\n\t1.LENGTH OF STRING\n\n\t2.REVERSE\n\n\t3.PALLINDROME\n\n\t4.COPY\n\n\t5.CONCATATION\n\n\t6.COMPARE\n\n\t7.EXIT");
	printf("\n\n\t******************************************");
	printf("\n\n\tenter your choice-");
	scanf("%d",&op);
switch(op)
{

	case 1:
		printf("\n\n\tenter a string");
		scanf("%s",str1);
		result=length(str1);
		printf("\n\nlength of %s is %d",str1,result);
		break;

	case 2:
		printf("\n\n\tENTER A STRING");
		scanf("%s",str1);
		reverse1(str1);
		printf("\n\n\treverse string %s",str1);
		break;

	case 3:
		printf("\n\n\tenter a string");
		scanf("%s",str1);
		pallindrome(str1);
		break;

	case 4:
		printf("\n\n\tenter a string");
		scanf("%s",str1);
		copy(str11,str1);
		printf("\n\n\n\t\t\tstring is %s",str11);
		break;
	
	case 5:
		printf("\n\n\n\t\tenter 1st string");
		scanf("%s",str1);
		printf("\n\n\n\t\tenter 2nd string");
		scanf("%s",str11);
		concat(str1,str11);
		printf("\n\n\tconcat string is %s",str1);
		break;

	case 6:
		printf("\n\n\n\t\tenter 1st string");
		scanf("%s",str1);
		printf("\n\n\n\t\tenter 2nd string");
		scanf("%s",str11);
		compare(str1,str11);
		break;

	case 7:
		exit(0);
		break;
}
printf("\n\n\t\tdo want to continue?\t");
scanf("%d",&ch);
if(ch==0)
break;
}
while (op<9);
return (0);
}


int length(char str[])
{
	int count=0,i=0;
	while(str[i]!='\0')
	{
		count++;	
		i++;
	}
return(count);
}

void reverse1(char s[])
{	
	char temp;
	int i,j=0;
	i=0;
	j=length(s)-1;
	while(i<j)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
		i++;
		j--;
	}
}

void pallindrome(char str1[])
{
	int i,j,flag=0;
	i=j=0;
	j=length(str1);
	j--;
	while(i<j)
	{
		if(str1[1]!=str1[j])
	{
		flag=0;
	}
		else
		flag=1;
		i++;j--;
	}
if (flag==0)
printf("\n\n\n\t\tnot a pallindrome");
else
printf("\n\n\n\t\ta pallidrome");
}

void copy(char ans[],char source[])
{
	int i=0;
	while(source[i]!='\0')
	{
		ans[i]=source[i];
		i++;
	}
	ans[i]='\0';
}

void concat(char str1[],char str11[])
{
	int i,j,n;
	i=length(str1);
	for(j=i,n=0;str11[n]!='\0';j++,n++)
		str1[j]=str11[n];
		str1[j]='\0';
}

void compare(char str1[],char str11[])
{
	int i,j,flag,n=0;
	i=length(str1),j=length(str11);
	if(i!=j)
	{
	if(i>j)
	{
		printf("\n\n\n\t\tstring %s is substring of %s",str11,str1);
	}
	else
		printf("\n\n\n\t\tstring %s is substring of %s",str1,str11);
	}
	else
	{
	while (str1[n]!='\0')
	{
		if(str1[n]==str11[n])
		flag=1;
		else
	{
		flag=0;
		break;
	}
		n++;
	}
if(flag==1)
{
printf("\n\n\n\t\tstring %s is equal to %s",str11,str1);
}
else
printf("\n\n\n\t\tstring %s is not equal to %s",str11,str1);
}
}

















