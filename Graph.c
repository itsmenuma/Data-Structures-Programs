#include<stdio.h>
#include<stdlib.h>
void bfs(int n,int a[20][20],int source,int visited[20],int e[20][2])
{
	int f,r,q[20];
	int u,k=1,v;
	f=0;
	r=-1;
	visited[source]=1;
	r=r+1;
	q[r]=source;
	while(f<=r)
	{
		u=q[f];
		f=f+1;
		for(v=1;v<=n;v++)
		{
			if(visited[v]==0 && a[u][v]==1)
			{
				visited[v]=1;
				r=r+1;
				q[r]=v;
				e[k][1]=u;
				e[k][2]=v;
				k=k+1;
			}
		}
	}	
}
void dfs(int n,int a[20][20],int u,int visited[20],int e[20][2])
{
	static int k=1;
	int v;
	visited[u]=1;
	for(v=1;v<=n;v++)
		{
			if(visited[v]==0 && a[u][v]==1)
			{
				
				e[k][1]=u;
				e[k][2]=v;
				k=k+1;
				dfs(n,a,v,visited,e);
			}
		}
}
void main()
{
	int i,j,flag,a[20][20],visited[20],e[20][2],source,n,choice;
	printf("Enter no of vertices:\n");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("Enter source:\n");
	scanf("%d",&source);
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("1.bfs\n2.dfs\nEnter choice:\n");
	scanf("%d",&choice);
	if(choice==1)
		bfs(n,a,source,visited,e);
	else
		dfs(n,a,source,visited,e);
	flag=0;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			printf("Edge %d is not reachable\n",i);
			flag=1;
		}
		else
			printf("Edge %d is  reachable\n",i);
	}
	if(flag==1)
		printf("The Graph is not conneted\n");
	else
	{
		printf("The Graph is connected\nThe spanning tree is :\n");
		for(i=1;i<=n-1;i++)
			printf("Edge from %d to %d\n",e[i][1],e[i][2]);
	}
}
