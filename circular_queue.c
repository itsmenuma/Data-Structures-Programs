#include<stdio.h>
#include<stdlib.h>
//queue size is 5
#define qs 5
//insert rear function
void ir(int item,int *r,int *count,int q[])
{
	if(*count==qs)//queue if full condition
	{
		printf("Queue Ovewrlfow\n");
		return;
	}
	*r=(*r+1)%qs;//increment read pointer
	q[*r]=item;//add the item
	*count=*count+1;//increment count variable
	printf("Item %d sucessfully inseted\n",item);
	return;
}
//delete front function
void df(int *f,int *count,int q[])
{
	int item;
	if(*count==0)//queue is empty
	{
		printf("Queue is empty\n");
		return;
	}
	item=q[*f];//access the item
	printf("Item deletd=%d\n",item);//print deleted
	*f=(*f+1)%qs;//update the front pointer
	*count=*count-1;//decrement count
	return;
}
//display fucntion
void display(int f,int count,int q[])
{
	int i;
	if(count==0)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("The contents of the Queue are:\n");
	for(i=1;i<=count;i++)
	{
		printf("%d\t",q[f]);
		f=(f+1)%qs;
	}
	printf("\n");
	return;
}	
//main function
void main()
{
	int f,r,count,q[qs],choice,item;
	f=0;
	r=-1;
	count=0;
	for(;;)
	{
		printf("1.IR\n2.DF\n3.D\n4.E\nEnter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter item to insert:\n");
				scanf("%d",&item);
				ir(item,&r,&count,q);
				break;
			case 2: df(&f,&count,q);
				break;
			case 3: display(f,count,q);
				break;
			default: exit(0);
		}	
	}
}
