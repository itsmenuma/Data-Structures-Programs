#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char ssn[20];
	char name[20];
	char dept[20];
	char desg[20];
	float sal;
	char phno[20];
	struct node *llink;//left link
	struct node *rlink;//right link
};
typedef struct node *NODE;
//insert front
NODE IF(char ssn[],char name[],char dept[],char desg[],float sal,char phno[],NODE first)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	strcpy(temp->ssn,ssn);
	strcpy(temp->name,name);
	strcpy(temp->dept,dept);
	strcpy(temp->desg,desg);
	temp->sal=sal;
	strcpy(temp->phno,phno);
	temp->llink=temp->rlink=NULL;
	if(first==NULL)
		return temp;
	temp->rlink=first;
	first->llink=temp;
	return temp;
}
//insert rear
NODE IR(char ssn[],char name[],char dept[],char desg[],float sal,char phno[],NODE first)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	strcpy(temp->ssn,ssn);
	strcpy(temp->name,name);
	strcpy(temp->dept,dept);
	strcpy(temp->desg,desg);
	temp->sal=sal;
	strcpy(temp->phno,phno);
	temp->llink=temp->rlink=NULL;
	if(first==NULL)
		return temp;
	NODE cur=first;
	while(cur->rlink!=NULL)
		cur=cur->rlink;
	cur->rlink=temp;
	temp->llink=cur;
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
	if(first->rlink==NULL)
	{
		printf("The details deleted are:\n");
		printf("ssn:%s\nname:%s\ndept:%s\ndesg:%s\nsal:%f\nphno:%s\n",first->ssn,first->name,first->dept,first->desg,first->sal,first->phno);
		free(first);
		return NULL;
	}
	NODE cur=first;
	first=first->rlink;
	printf("The details deleted are:\n");
	printf("ssn:%s\nname:%s\ndept:%s\ndesg:%s\nsal:%f\nphno:%s\n",cur->ssn,cur->name,cur->dept,cur->desg,cur->sal,cur->phno);
	free(cur);
	first->llink=NULL;
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
	if(first->rlink==NULL)
	{
		printf("The details deleted are:\n");
		printf("ssn:%s\nname:%s\ndept:%s\ndesg:%s\nsal:%f\nphno:%s\n",first->ssn,first->name,first->dept,first->desg,first->sal,first->phno);
		free(first);
		return NULL;
	}
	NODE cur=first;
	while(cur->rlink!=NULL)
		cur=cur->rlink;
	NODE prev=cur->llink;
	printf("The details deleted are:\n");
	printf("ssn:%s\nname:%s\ndept:%s\ndesg:%s\nsal:%f\nphno:%s\n",cur->ssn,cur->name,cur->dept,cur->desg,cur->sal,cur->phno);
	free(cur);
	prev->rlink=NULL;
	return first;
}
//display
void disp(NODE first)
{
	int count=0;
	if(first==NULL)
	{
		printf("The list is empty\n");
		printf("The no of nodes=%d\n",count);
		return;
	}
	NODE cur=first;
	printf("The contents of the list are:\n");
	while(cur!=NULL)
	{
		count++;
		printf("ssn:%s\nname:%s\ndept:%s\ndesg:%s\nsal:%f\nphno:%s\n",cur->ssn,cur->name,cur->dept,cur->desg,cur->sal,cur->phno);
		printf("-------------------------------------\n");	
		cur=cur->rlink;
	}
	printf("The no of nodes=%d\n",count);
	return;
}	
//main
void main()
{
	char ssn[20];
	char name[20];
	char dept[20];
	char desg[20];
	float sal;
	char phno[20];
	NODE first=NULL;
	int i,n,choice;
	printf("Enter the no of employees:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("For employ %d\n",i+1);
		printf("ssn:\n");
		scanf("%s",ssn);
		printf("name:\n");
		scanf("%s",name);
		printf("dept:\n");
		scanf("%s",dept);
		printf("desg:\n");
		scanf("%s",desg);
		printf("sal:\n");
		scanf("%f",&sal);
		printf("phno:\n");
		scanf("%s",phno);
		first=IR(ssn,name,dept,desg,sal,phno,first);
	}
	for(;;)
	{
		printf("1.IF\n2.IR\n3.Df\n4.Dr\n5.Disp\n6.Exit\nEnter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the following details\n");
				printf("ssn:\n");
				scanf("%s",ssn);
				printf("name:\n");
				scanf("%s",name);
				printf("dept:\n");
				scanf("%s",dept);
				printf("desg:\n");
				scanf("%s",desg);
				printf("sal:\n");
				scanf("%f",&sal);
				printf("phno:\n");
				scanf("%s",phno);
				first=IF(ssn,name,dept,desg,sal,phno,first);
				break;
			case 2: printf("Enter the following details\n");
				printf("ssn:\n");
				scanf("%s",ssn);
				printf("name:\n");
				scanf("%s",name);
				printf("dept:\n");
				scanf("%s",dept);
				printf("desg:\n");
				scanf("%s",desg);
				printf("sal:\n");
				scanf("%f",&sal);
				printf("phno:\n");
				scanf("%s",phno);
				first=IR(ssn,name,dept,desg,sal,phno,first);
				break;
			case 3: first=DF(first);
				break;
			case 4: first=DR(first);
				break;
			case 5:disp(first);
				break;
			case 6: exit(0);
		}
	}
}
