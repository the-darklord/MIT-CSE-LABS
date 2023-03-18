#include <stdio.h>
#include <stdlib.h>

int n;
int *visited;
int **adj;

void DFS(int i)
{
    visited[i]=1;
    for(int j=0;j<n;j++)
    {
        if(adj[i][j]&&!visited[j])
        {
            DFS(j);
        }
    }
	printf("%d ",i);
}

void main()
{
    printf("Enter No. of Vertices : \t");
    scanf("%d",&n);
    visited=(int *)malloc(n*sizeof(int));
    adj=(int **)calloc(n,sizeof(int *));
    printf("Enter %d*%d Adjacency Matrix : \n",n,n);
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        adj[i]=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nDFS ORDER IS : \n");
    DFS(0);
    printf("\n\n");
}