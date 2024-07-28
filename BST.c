#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node*llink;
	struct node*rlink;
};
typedef struct node *NODE;
NODE insert(int item,NODE root)
{
	NODE temp;
	NODE prev,cur;
	temp=(NODE)malloc(sizeof(struct node));
	temp->info=item;
	temp->llink=temp->rlink=NULL;
	if(root==NULL)
		return temp;
	cur=root;
	prev=NULL;
	while(cur!=NULL)
	{
		prev=cur;
		if(item<cur->info)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(item<prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;
	return root;
}
void inorder(NODE root)//LNR
{
	if(root==NULL)
		return;
	inorder(root->llink);
	printf("%d\t",root->info);
	inorder(root->rlink);
}
void preorder(NODE root)//NLR
{
	if(root==NULL)
		return;
	printf("%d\t",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}
void postorder(NODE root)//LRN
{
	if(root==NULL)
		return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\t",root->info);	
}
NODE search(int key,NODE root)
{
	if(root==NULL || root->info==key)
		return root;
	if(key<root->info)
		return(search(key,root->llink));
	else
		return(search(key,root->rlink));	
}
void main()
{
	int item,choice;
	NODE root=NULL,temp=NULL;
	for(;;)
	{
		printf("\n1.Insert\n2.Traverse\n3.Search\n4.exit\nEnter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter item to insert:\n");
				scanf("%d",&item);
				root=insert(item,root);
				break;
			case 2: if(root==NULL)
				{
					printf("The BST is empty\n");
					break;
				}
				printf("\nInorder:\n");
				inorder(root);
				printf("\nPreorder:\n");
				preorder(root);
				printf("\nPostorder:\n");
				postorder(root);
				break;
			case 3: printf("Enter item to search:\n");
				scanf("%d",&item);
				temp=search(item,root);
				if(temp==NULL)
					printf("ITem not found!!\n");
				else
					printf("Item %d is found\n",temp->info);
				break;
			default: exit(0);
		}
	}
}
