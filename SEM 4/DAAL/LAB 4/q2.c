#include <stdio.h>
#include <stdlib.h>

//Code Not Completed

typedef struct ELEMENT
{
    int data;
    int push_order,pop_order;
    int visited;
}ELEMENT;
typedef struct STACK
{
    ELEMENT *arr;
    int push_count,pop_count;
    int tos;
}STACK;

void push(STACK *ptr,int x)
{
    ptr->push_count++;
    ptr->arr[++(ptr->tos)].data=x;
    ptr->arr[ptr->tos].push_order=ptr->push_count;
}

ELEMENT pop(STACK *ptr)
{
    ptr->pop_count++;
    ptr->arr[ptr->tos].pop_order=ptr->pop_count;
    return ptr->arr[(ptr->tos)--];
}

void dfs()
{

}

void main()
{
    STACK *ptr;
    ptr->tos=-1;
    ptr->push_count=ptr->pop_count=0;
    int n;
    printf("Enter Number of Vertices : \t");
    scanf("%d",&n);
    ptr->arr=(int *)malloc(n*sizeof(int));
    int** adj=(int **)calloc(n,sizeof(int *));
    printf("\nEnter 1 for YES \t 2 for NO\n");
    for(int i=0;i<n;i++)
    {
        adj[i]=(int *)malloc(n*sizeof(int));
        ptr->arr[i].visited=0;
        for(int j=0;j<n;j++)
        {
            printf("Are Vertices %d,%d are adjacent? \t",i+1,j+1);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nAdjacency Matrix is \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(ptr->tos==-1)
    //         {
    //             push(ptr,i+1);
    //         }
    //     }
    // }
}