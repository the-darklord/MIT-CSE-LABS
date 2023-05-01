#include <stdio.h>
#include <stdlib.h>

void Warshall(int** adj,int n)
{
    int i, j, k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                adj[i][j] = adj[i][j] | (adj[i][k] & adj[k][j]);
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter No. of Vertices : \t");
    scanf("%d",&n);
    int** adj=(int **)calloc(n,sizeof(int *));
    printf("\nEnter Adjacency Matrix of Directed Graph : \n");
    for(int i=0;i<n;i++)
    {
        adj[i]=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    Warshall(adj,n);
    printf("\nAdjacency Matrix of Directed Graph : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}