#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

int minDistance(int dist[], bool includeSet[],int n)
{
    int min = INT_MAX, min_index;
  
    for (int i = 0; i < n; i++)
    {
        if (includeSet[i] == false && dist[i] <= min)
        {   
            min = dist[i], min_index = i;
        }
    }
    return min_index;
}

void printSolution(int dist[],int n)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
    {
        if(dist[i]!=INT_MAX)
        {
            printf("%d \t\t\t\t %d\n", i, dist[i]);
        }
        else
        {
            printf("%d \t\t\t\t %s\n", i, "Infinity");
        }
    }
}

void Djikstras(int** adj,int n,int i)
{
    int dist[n];
    bool includeSet[n];
    for(int j=0;j<n;j++)
    {
        dist[j] = INT_MAX;
        includeSet[j] = false;
    }
    dist[i]=0;
    int x;
    for(int j=0;j<n-1;j++)
    {
        x = minDistance(dist,includeSet,n);
        includeSet[x]=true;
        for(int k=0;k<n;k++)
        {
            if(!includeSet[k]&&adj[x][k]&&dist[x]!=INT_MAX&&dist[x]+adj[x][k]<dist[k])
            {
                dist[k]=dist[x]+adj[x][k];
            }
        }
    }
    printSolution(dist,n);
}

void main()
{
    int n;
    printf("Enter No. of Vertices : \t");
    scanf("%d",&n);
    int** adj=(int**)calloc(n,sizeof(int*));
    printf("Enter Adjacency Weight Matrix : \n");
    for(int i=0;i<n;i++)
    {
        adj[i]=(int*)calloc(n,sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    int i;
    printf("Enter Start Vertex : \t");
    scanf("%d",&i);
    Djikstras(adj,n,i);
}

/*

Enter No. of Vertices : 	7
Enter Adjacency Weight Matrix : 

0 2 6 0 0 0 0
2 0 0 5 0 0 0
6 0 0 8 0 0 0
0 5 8 0 10 15 0            
0 0 0 10 0 6 2
0 0 0 15 6 0 6
0 0 0 0 2 6 0

Enter Start Vertex : 	0
Vertex 		 Distance from Source
0 				 0
1 				 2
2 				 6
3 				 7
4 				 17
5 				 22
6 				 19


*/