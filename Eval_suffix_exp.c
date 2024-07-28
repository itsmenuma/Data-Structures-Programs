#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//declare stack size as 100 to avoid segmentation fault
#define ss 100
//push function
void push(int item,int *top,int s[])
{
	if(*top==ss-1)
	{
		printf("Stack Overflow\n");
		return;
	}
	*top=*top+1;
	s[*top]=item;
}
//pop function
int pop(int *top,int s[])
{
	int item;
	if(*top==-1)
		return -1;
	item=s[*top];
	*top=*top-1;
	return item;
}
//evaulate function
int eval(char postfix[])
{
	int i,j,n,s[ss],op1,op2,res,top;
	char symbol;
	top=-1;
	n=strlen(postfix);
	for(i=0;i<n;i++)
	{
		symbol=postfix[i];
		switch(symbol)
		{
			case '+': op2=pop(&top,s);
				  op1=pop(&top,s);
				  res=op1+op2;
				  push(res,&top,s);
				  break;
			case '-': op2=pop(&top,s);
				  op1=pop(&top,s);
				  res=op1-op2;
				  push(res,&top,s);
				  break;
			case '*': op2=pop(&top,s);
				  op1=pop(&top,s);
				  res=op1*op2;
				  push(res,&top,s);
				  break;
			case '/': op2=pop(&top,s);
				  op1=pop(&top,s);
				  res=op1/op2;
				  push(res,&top,s);
				  break;
			case '%': op2=pop(&top,s);
				  op1=pop(&top,s);
				  res=op1%op2;
				  push(res,&top,s);
				  break;
			case '^':
			case '$': op2=pop(&top,s);
				  op1=pop(&top,s);
				  res=(int)pow((double)op1,(double)op2);
				  push(res,&top,s);
				  break;
			default: push(symbol-'0',&top,s);
		}
	}
	return(pop(&top,s));
}
//main function
void main()
{
	char postfix[ss];
	int res;
	printf("Enter the postfix expression:\n");
	scanf("%s",postfix);
	res=eval(postfix);
	printf("The solution of the postfix expression is \n%d\n",res);
}
