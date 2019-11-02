/*
second year computer engineering class of M students ,set A of students play cricket and set B play badminton . write C/C++ program to find and display
1.set of students  who play either cricket or badminton or both
2.set of students who play both cricket and badminton
3.set of students who play only cricket
4.set of students who play badminton
5.number of students who play neither cricket nor badminton
*/





# define MAX 30
#include<stdio.h>
#include<stdlib.h>
void insert(int []);
void display(int []);
void Union(int[],int[],int[]);
void diff(int[],int[],int[]);



 int main()
{
 int setA[MAX],setB[MAX],setT[MAX],setC[MAX],setC1[MAX],setC2[MAX],setC3[MAX],setC4[MAX],setC5[MAX];
 int x,ch;
 int ch1;

 setA[0]=setB[0]=setC[0]=setT[0]=setC1[0]=setC2[0]=setC3[0]=setC4[0]=setC5[0]=0;
do
{
printf("\t***************************************************");
 printf("\n\n\t**MENU**");
 printf("\n\n\t1.Enter the choice of student\n\n\t2.Students who play Badminton\n\n\t3.Students who play Cricket\n\n\t4.Students who play Badminton,Cricket or Both\n\n\t5.Students who play neither Badminton nor cricket\n\n\t6.Students who play only Badminton (A-B)\n\n\t7.Students who play only Cricket(B-A)\n\n\t8.Students who play both games\n\n\t9.Exit\n\n\t");
printf("****************************************************\n");
 
 printf("Enter ypur choice:");
 scanf("%d",&ch);

switch(ch)
{
 case 1:
         printf("\n\n\tEnter students present in class:");
         insert(setT);
          printf("\n\n\tStudents who play Badminton\n\n");
         insert(setA);
          printf("\n\n\tStudents who plat Cricket\n\n");
         insert(setB);
         break;
case 2:
       printf("\n\n\tStudents who play Badminton");
       printf("\n\n\tRoll no of students:");
       display(setA);
      break;
case 3:
        printf("\n\n\tStudents who play Cricket");
       printf("\n\n\tRoll no of students:");
       display(setB);
      break;

case 4: 
        Union(setA,setB,setC);
        printf("\n\n\tStudents who play Badminton,Cricket or both(AUB):\n");
        display(setC);
        break;

case 5:
        diff(setT,setC,setC1);
        printf("\n\n\tStudents who play neither Badminton nor Cricket:\n");
        display(setC1);
        break;

case 6:
        diff(setA,setB,setC2);
        printf("\n\n\tStudents who play only Badminton (A-B):\n");
        display(setC2);
        break;

case 7:
        diff(setB,setA,setC3);
        printf("\n\n\tStudents who play only Cricket (B-A):\n");
        display(setC3);
        break;

case 8:
        diff(setA,setC2,setC5);
        printf("\n\n\tStudents who play both game:\n");
        display(setC5);
        break;

case 9:
         exit(0);
         



}

  printf("\n\n\tDo you want to continue.........");
  scanf("%d",&ch1);

 if(ch1==0)
  break;
}while(ch!=8);

 return 0;
}

void insert(int set[])
{
 int n,i,x;
 set[0]=0;
 printf("\n\n\tenter no of students:");
 scanf("%d",&n);
 set[0]=n;
 printf("\n\n\tEnter Roll no. of students :\n");
  for(i=1;i<=n;i++)
   {
     scanf("%d",&set[i]);
   }
}


void display(int set[])
{
  int i,n;
  n=set[0];
  
  if(n==0)
   printf("\n\n\tNULL SET");
 
 else

  {
    printf("\n\n\t{");
    for(i=1;i<=n;i++)
      printf("%d\t",set[i]);
      
      printf("}");

  }
}

void Union(int setA[],int setB[],int setC[])
{
 int i,n,n1,m,j,flag;
 n=setA[0];
  for(i=0;i<=n;i++)
    setC[i]=setA[i];
 
 m=n;
 m++;
 n1=setB[0];
  for(i=1;i<=n1;i++)
{
   for(j=1;j<=n;j++)
    {
       if(setB[i]!=setA[j])
       {
            flag=1;
       }
    else
      {
        flag=0;
         break;
     }
 }
  if(flag==1)
 {
   setC[0]++;
    setC[m]=setB[i];
   m++;

}
}
}


void diff(int setA[],int setB[],int setC[])
{
  int i,n,n1,m=1,flag=1,j;
  n=setA[0];
  n1=setB[0];
  setC[0]=0;
  for(i=1;i<=n;i++)
   {
      for(j=1;j<=n1;j++)
        {
             if(setA[i]!=setB[j])
                 flag=1;
           
             else
               {
                  flag=0;
                   break;
               }        
        }
        if(flag==1)
           {
              setC[m]=setA[i];
              setC[0]++;
              m++;
            }
   }
}

