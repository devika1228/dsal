//infix to postfix

#include<stdio.h>
#include<ctype.h>

void push(char);
char pop();
int priority(char);

int top=-1;
char s[20];

int main()
{
        int i=0,j=0;
        char infix[20],postfix[20];
        char x,token;

printf("\n\n\tenter a expression:");
scanf("%s",infix);

        while(infix[i]!='\0')
        {
                if(isalnum(infix[i]))
                {
                        postfix[j]=infix[i];
                        j++;
                }
                else
                        if(infix[i]=='(')
                        push(infix[i]);
                else
                        if(infix[i]==')')
		  {
                                token=pop();
                        while(token!='(')
                        {
                                postfix[j]=token;
                                j++;
                                token=pop();
                        }
                    }    
                else
                {
                        while(priority(infix[i])<=priority(s[top]) && top!=-1)
                        {
                                token=pop();
                                postfix[j]=token;
                                j++;
                        }
        push(infix[i]);
                }
        i++;
        }
while(top!=-1)
{
token=pop();
postfix[j]=token;
j++;
}
postfix[j]='\0';
printf("\n\n\tconverted expression is %s",postfix);
}

void push(char x)
{
top=top+1;
s[top]=x;
}

char pop()
{
int temp;
temp=s[top];
top--;
return temp;
}

int priority(char x)
{
if(x=='(')
return 0;
if(x=='+'||x=='-')
return 1;
if(x=='*'||x=='/')
return 2;
}

