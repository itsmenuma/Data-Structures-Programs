#include<stdio.h>
#include<stdlib.h>
//queue size declared as 5
#define qs 5
//insert rear function
void IR(int item,int *r,int q[])
{
	if(*r==qs-1)//queue is full condition
	{
		printf("Queue Overflow\n");
		return;
	}
	*r=*r+1;//increment rear pointer
	q[*r]=item;//add item
	printf("Item %d sucessfully inserted\n",item);
	return;
}
//delete front function
void DF(int *f,int *r,int q[])
{
	if(*f>*r)//queue empty condition
	{
		printf("Queue is empty\n");
		return;
	}
	int item=q[*f];//access item
	printf("Item deleted=%d\n",item);//print item
	*f=*f+1;//update front pointer
	if(*f>*r)//reinitilizze front and rear pointers
	{
		*f=0;
		*r=-1;
	}
	return;
}
//display fucntion
void Display(int f,int r,int q[])
{
	int i;
	if(f>r)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("The contents of the Queue are:\n");
	for(i=f;i<=r;i++)
		printf("%d\t",q[i]);
	printf("\n");
	return;
}
//insert front function
void IF(int item,int *f,int *r,int q[])
{
	if(*f==0 && *r!=-1)//check if inserting at first is possible
	{
		printf("Insertion from front not possible\n");
		return;
	}
	if(*f==0)
	{
		*r=*r+1;
		q[*r]=item;
		printf("Item %d sucessfully inserted\n",item);
		return;
	}
	*f=*f-1;
	q[*f]=item;
	printf("Item %d sucessfully inserted\n",item);
	return;
}
//delete front function
void DR(int *f,int *r,int q[])
{
	if(*f>*r)
	{
		printf("Queue is empty\n");
		return;
	}
	int item=q[*r];
	printf("Item deleted=%d\n",item);
	*r=*r-1;
	if(*f>*r)
	{
		*f=0;
		*r=-1;
	}
	return;
}
//main function
void main()
{
	int q[qs],r,f,item,choice;
	f=0;
	r=-1;
  //infinite loop
	for(;;)
	{
		printf("1.IF\n2.IR\n3.DF\n4.DR\n5.D\n6.E\nEnter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter item to insert:\n");
				scanf("%d",&item);
				IF(item,&f,&r,q);
				break;
			case 2: printf("enter item to insert:\n");
				scanf("%d",&item);
				IR(item,&r,q);
				break;
			case 3: DF(&f,&r,q);
				break;
			case 4: DR(&f,&r,q);
				break;
			case 5: Display(f,r,q);
				break;
			default: exit(0);
		}
	}
}
