#include<stdio.h>
#include<stdlib.h>
//defining stack size as 5
#define ss 5
//push operation function
void push(int item,int *top,int s[])
{
	if(*top==ss-1)//if stack is full
	{
		printf("Stack Overflow\n");
		return;
	}
  //to push increment stack pointer and then add the item to the top of the stack
	*top=*top+1;
	s[*top]=item;
	printf("Item %d sucessfully inserted\n",item);
	return;
}
//pop operation function
int pop(int *top,int s[])
{
	int item;
  //if stack is empty retuern -1
	if(*top==-1)
		return -1;
  //access the item on top of the stack
	item=s[*top];
  //decrement the stack pointer
	*top=*top-1;
  //return the item to be deleted
	return item;
}
//function to display stack contents
void display(int top,int s[])
{
	int i;
  //if stack is empty display empty stack
	if(top==-1)
	{
		printf("Stack is empty\n");
		return;
	}
  //display stack contents
	printf("The contents of the stack are:\n");
	for(i=0;i<=top;i++)
		printf("%d\n",s[i]);
	return;
}
//main function
void main()
{
	int y,item,top,s[ss],choice;
	top=-1;
  //infinite loop menu
	for(;;)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
      //if push is selected
			case 1: printf("enter item to inert\n");
				scanf("%d",&item);//input value to push onto stack
				push(item,&top,s);//push that item onto stack
				break;
      //if pop is selected
			case 2: y=pop(&top,s);//access the item on top of the stack
				if(y==-1)//if the stack is empty
					printf("Stack underflow\n");
				else//else print the item deleted
					printf("Item deleted=%d\n",y);
				break;
      //if display is selected
			case 3: display(top,s);
				break;
      //if any other option is selcted simply exit from the infinite loop
			default: exit(0);
		}		
	}
}
