#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char usn[20];
	char name[20];
	char branch[20];
	int sem;
	char phno[20];
	struct node *link;
};
typedef struct node *NODE;
//insert front
NODE IF(char usn[],char name[],char branch[],int sem,char phno[],NODE first)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	strcpy(temp->usn,usn);
	strcpy(temp->name,name);
	strcpy(temp->branch,branch);
	temp->sem=sem;
	strcpy(temp->phno,phno);
	temp->link=NULL;
	if(first==NULL)
		return temp;
	temp->link=first;
	return temp;
}
//insert rear
NODE IR(char usn[],char name[],char branch[],int sem,char phno[],NODE first)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	strcpy(temp->usn,usn);
	strcpy(temp->name,name);
	strcpy(temp->branch,branch);
	temp->sem=sem;
	strcpy(temp->phno,phno);
	temp->link=NULL;
	if(first==NULL)
		return temp;
	NODE cur;
	cur=first;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	return first;
}
//delete front
NODE DF(NODE first)
{
	if(first==NULL)
	{
		printf("The list is empty\n");
		return first;
	}
	NODE cur;
	cur=first;
	first=first->link;
	printf("The student details deleted are:\n");
	printf("Name:%s\nUSN:%s\nBranch:%s\nSem:%d\nPhno:%s\n",cur->name,cur->usn,cur->branch,cur->sem,cur->phno);
	free(cur);
	return first;
}
//delete rear
NODE DR(NODE first)
{
	if(first==NULL)
	{
		printf("The list is empty\n");
		return first;
	}
	if(first->link==NULL)
	{
		printf("The student details deleted are:\n");
		printf("Name:%s\nUSN:%s\nBranch:%s\nSem:%d\nPhno:%s\n",first->name,first->usn,first->branch,first->sem,first->phno);
		free(first);
		return NULL;
	}
	NODE cur,prev;
	cur=first;
	prev=NULL;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("The student details deleted are:\n");
	printf("Name:%s\nUSN:%s\nBranch:%s\nSem:%d\nPhno:%s\n",cur->name,cur->usn,cur->branch,cur->sem,cur->phno);
	free(cur);
	prev->link=NULL;
	return first;
}
//display
void disp(NODE first)
{
	int count=0;
	if(first==NULL)
	{
		printf("The list is empty\n");
		printf("The no of nodes are %d\n",count);
		return;
	}
	NODE cur=first;
	printf("The contents of the list are:\n");
	while(cur!=NULL)
	{
		count++;
		printf("Name:%s\nUSN:%s\nBranch:%s\nSem:%d\nPhno:%s\n",cur->name,cur->usn,cur->branch,cur->sem,cur->phno);
		printf("-----------------------------------------------\n");
		cur=cur->link;
	}
	printf("The no of nodes are %d\n",count);
	return;
}
//main
void main()
{
	char usn[20];
	char name[20];
	char branch[20];
	int sem;
	char phno[20];
	NODE first=NULL;
	int n,choice;
	printf("Enter the no of students:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("For student %d\n",i+1);
		printf("usn:\n");
		scanf("%s",usn);
		printf("name:\n");
		scanf("%s",name);
		printf("branch:\n");
		scanf("%s",branch);
		printf("sem:\n");
		scanf("%d",&sem);
		printf("phno:\n");
		scanf("%s",phno);
		first=IF(usn,name,branch,sem,phno,first);
	}
	for(;;)
	{
		printf("1.IF\n2.IR\n3.DF\n4.DR\n5.Disp\n6.Exit\nEnter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter student details:\n");
				printf("usn:\n");
				scanf("%s",usn);
				printf("name:\n");
				scanf("%s",name);
				printf("branch:\n");
				scanf("%s",branch);
				printf("sem:\n");
				scanf("%d",&sem);
				printf("phno:\n");
				scanf("%s",phno);
				first=IF(usn,name,branch,sem,phno,first);
				break;
			case 2: printf("Enter student details:\n");
				printf("usn:\n");
				scanf("%s",usn);
				printf("name:\n");
				scanf("%s",name);
				printf("branch:\n");
				scanf("%s",branch);
				printf("sem:\n");
				scanf("%d",&sem);
				printf("phno:\n");
				scanf("%s",phno);
				first=IR(usn,name,branch,sem,phno,first);
				break;
			case 3: first=DF(first);
				break;
			case 4: first=DR(first);
				break;
			case 5: disp(first);
				break;
			case 6: exit(0);
		}
	}
}
