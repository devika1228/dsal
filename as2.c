/*writ C/C++ program to score marks scored for first test of subject "DSA" for students .compute:
1.the avg score of the class
2.heighest score and lowest score of class
3.marks scoreed by most of the students
4.list of students who were absent for the test
*/





#include<stdio.h>
#define MAX 20

int main()
{
 
 int stud_roll[MAX],stud_marks[MAX],n,count=0,i;
char stud_status[MAX];
float avg,total=0;
printf("enter number of students in class");
scanf("%d",&n);
printf("enter roll no.and marks of DSA \nplease enter -1 for absent students");

for(i=0;i<n;i++)
{
printf("\nenter the roll no.\n");
scanf("%d",&stud_roll[i] );
printf("\nenter the marks\n");
scanf("%d",&stud_marks[i]);

if (stud_marks[i]>=40)
stud_status[i]='P';
else if(stud_marks[i]<40 && stud_marks[i]>=0)
stud_status[i]='F';
else
stud_status[i]='A';


}

printf("\n\t\t.............................................................");
printf("\n\n\n\t\t*****RESULT ANALYSIS****\n");
printf("40 and above marks is pass.The marks -1 shows the student is absent\n");
printf("\n\t\t.............................................................");
printf("\n\n\t\tROLL NO.\t\tMARKS\t\tSTATUS");
printf("\n\t\t.............................................................");

for(i=0;i<n;i++)
{
printf("\n\t\t\t%d\t\t %d\t\t %c",stud_roll[i],stud_marks[i],stud_status[i]);
}

printf("\n\t\t.............................................................");



for(i=0;i<n;i++)
{
if(stud_marks[i]>-1)
{
total+= stud_marks[i];
count++;
}
}
avg=total/count;
printf("\n1.Avg of class:%f",avg);

int min,max1;
max1=stud_marks[0];
min=stud_marks[0];

min=999;
for(i=0;i<n;i++)
{ 
if(stud_marks[i]<min && stud_marks[i]>-1)
min=stud_marks[i];

}
for(i=0;i<n;i++)
{
if (stud_marks[i]>max1)
max1=stud_marks[i];
}

printf("\n\n\n\t2.highest score:%d \tlowest score:%d",max1,min);



printf("\n\n\n\t3.The DSA marks scored by most students.\n\n\t\tlist of students who scored above average marks:\n");
printf("\n\t\t......................................................");
printf("\n\n\t\tROLL NO.\tMARKS");
printf("\n\t\t......................................................");


for(i=0;i<n;i++)
{
if(stud_marks[i]>=avg)
printf("\n\t\t\t %d\t%d \t\t\t",stud_roll[i],stud_marks[i]);
}
printf("\n\t\t......................................................");


count=0;
printf("\n\n\n\t4.ROLL NOS. OF ABSENT STUDENTS:");
for(i=0;i<n;i++)
{
if(stud_marks[i]<=-1)
{
printf("\t%d",stud_roll[i]);
count++;
}
}
printf("\n\n");
if(count==0)
printf("\n\n\tNO STUDENTS WERE ABSENT FOR THE TEST\n\n");
return 0;
}























