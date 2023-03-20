#include <stdio.h>
#include <stdlib.h>

int n;
int k=0;
int l=0;
int *visited;
int *topo;
int *indegree;
int *srcrmvl;
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
	topo[k++]=i+1;
}

void source_removal(int i)
{
    visited[i]=1;
    for(int j=0;j<n;j++)
    {
        if(adj[i][j]&&indegree[j]&&!visited[j])
        {
            indegree[j]--;
        }
    }
    srcrmvl[l++]=i+1;
    if(i==n)
    {
        return;
    }
    else
    {
        for(int j=0;j<n;j++)
        {
            if(indegree[j]==0&&!visited[j])
            {
                source_removal(j);
            }
        }
    }
}

void main()
{
    printf("Enter No. of Vertices : \t");
    scanf("%d",&n);
    visited=(int *)malloc(n*sizeof(int));
    topo=(int *)malloc(n*sizeof(int));
    adj=(int **)calloc(n,sizeof(int *));
    indegree=(int *)calloc(n,sizeof(int));
    srcrmvl=(int *)malloc(n*sizeof(int));
    printf("Enter Undirected Adjacency Matrix for DFS : \n");
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
    for(int i=n-1;i>=0;i--)
    {
        printf("%d ",topo[i]);
    }
    printf("\n\n");
    int t;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            t=i;
            break;
        }
    }
    printf("\n\nEnter Directed Adjacency Matrix for SOURCE REMOVAL : \n");
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
            if(adj[i][j])
            {
                indegree[j]++;
            }
        }
    }
    printf("\nSOURCE REMOVAL ORDER IS : \n");
    source_removal(t);
    for(int i=0;i<n;i++)
    {
        printf("%d ",srcrmvl[i]);
    }
    printf("\n\n");
}