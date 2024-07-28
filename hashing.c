#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define m 100
struct node
{
	int age;
	int empid;
	char name[20];
}ht[m];
int hash(int key)
{
	int index;
	index=key%m;
	return index;
}
void main()
{
	int i,j,choice,count=0,empid,index,key,age;
	char name[20];
	for(i=0;i<m;i++)
		ht[i].empid=-1;
	for(;;)
	{
		printf("1.Insert\n2.Search\n3.Exit\nEnter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(count==m)
				{
					printf("Hash table is full\n");
					break;
				}
				else
				{
					printf("Enter the following details to insert\nempid:\n");
					scanf("%d",&empid);
					printf("Name:\n");
					scanf("%s",name);
					printf("Age:\n");
					scanf("%d",&age);
					index=hash(empid);
					if(ht[index].empid==-1)
					{
						ht[index].empid=empid;
						ht[index].age=age;
						strcpy(ht[index].name,name);
						count++;
						break;
					}
					else
					{
						for(i=1;i<=m;i++)
						{
							index=(hash(empid)+i)%m;
							if(ht[index].empid==-1)
							{
								ht[index].empid=empid;
								ht[index].age=age;
								strcpy(ht[index].name,name);
								count++;
								break;
							}
									
						}
					}
					
				}
				break;
			case 2:printf("Enter the key to search");
				scanf("%d",&key);
				index=hash(key);
				if(ht[index].empid==key)
				{
					printf("Key found succesfully\n");
					printf("Name:%s\nage:%d\n",ht[index].name,ht[index].age);
					break;
				}
				else if(ht[index].empid==-1)
				{
					printf("Key not found succesfully\n");
					break;
				}
				else
				{
					for(i=1;i<=m;i++)
					{
						index=(hash(key)+i)%m;
						if(ht[index].empid==key)
						{
							printf("Key found succesfully\n");
							printf("Name:%s\nage:%d\n",ht[index].name,ht[index].age);
							break;
						}
						else if(ht[index].empid==-1)
						{
							printf("Key not found succesfully\n");
							break;
						}
					}
					
				}
				break;
			default:exit(0);
		}
	}
}
