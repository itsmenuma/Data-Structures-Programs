//header files declaration
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//define a stack with big stack size to avoid segmentation fault
#define ss 100
//this function returns the input precedence of each symbol
int input_precedence(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':
		case '%':return 3;
		case '^':
		case '$':return 6;
		case '(':return 9;
		case ')':return 0;
		default :return 7;
	}
}
//this function returns the stack precedence of each symbol
int stack_precedence(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':return 2;
		case '*':
		case '/':
		case '%':return 4;
		case '^':
		case '$':return 5;
		case '(':return 0;
		case '#':return -1;
		default :return 8;
	}
}
//push operation
void push(char item,int *top,char s[])
{
	if(*top==ss-1)
	{
		printf("Stack Overflow\n");
		return;
	}	
	*top=*top+1;
	s[*top]=item;
	return;
}
//pop operation
char pop(int *top,char s[])
{
	char item;
	if(*top==-1)
		return -1;
	item=s[*top];
	*top=*top-1;
	return item;
}
//function where infix experssion is converted into a postfix one
void infix_postfix(char infix[],char postfix[])
{
	int i,j,top,n;
	char s[ss];
	char symbol;
	top=-1;
	j=0;
	n=strlen(infix);//size of the infix expression
	push('#',&top,s);//we push '#' onto the stack initially
	for(i=0;i<n;i++)//start for loop for each symbol in the infix expression
	{
		symbol=infix[i];//acquire the symbol in the infix expression
		while(stack_precedence(s[top])>input_precedence(symbol))//while the stack precedence of the symbol on top of the stack is greater than the symbol of the symbol in the infix expression
		{
			postfix[j]=pop(&top,s);//pop the symbol on top of the stack and place in the postfix expression
			j=j+1;//increment postfix index
		}
		if(stack_precedence(s[top])!=input_precedence(symbol))//if stack precedence of the symbol on top of the stack is not equal to the input precedence of the symbol in the infix expression
			push(symbol,&top,s);//push the infix symbol onto the stack
		else
			pop(&top,s);//delete the item on top of the stack
	}
  //finally pop all the elements other that '#' and place it in the postfix expression
	while(s[top]!='#')
	{	
		postfix[j]=pop(&top,s);
		j=j+1;
	}
	postfix[j] = '\0';//apprend the end of the postfix expression with '\0' cause strings must be appended with \0 always
}
//main function
void main()
{
	char infix[ss],postfix[ss];
	printf("Enter infix:\n");//read the infix expression
	scanf("%s",infix);
	infix_postfix(infix,postfix);//call the infix to postfix fucntion
	printf("Postfix=%s\n",postfix);//print postfix expression
	
}
