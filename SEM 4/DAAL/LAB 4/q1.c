#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void evaluate(int** cm,int* in,int n,int* mincost,int* minarr)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += cm[i][in[i]];
    }
    if(sum<*mincost)
    {
        memcpy(minarr,in,n*sizeof(int));
        *mincost=sum;
    }
}

void generate_permutations(int** cm,int* in,int n,int* mincost,int* minarr,int i)
{
    if(i==n)
    {
        evaluate(cm,in,n,mincost,minarr);
    }
    else
    {
        for(int j=i;j<n;j++)
        {
            swap(&in[i],&in[j]);
            generate_permutations(cm,in,n,mincost,minarr,i+1);
            swap(&in[i],&in[j]);
        }
    }
}

void main()
{
    int n;
    printf("Enter No. of Jobs/Persons : \t");
    scanf("%d",&n);
    int** costmatrix;
    costmatrix=(int**)calloc(n,sizeof(sizeof(int*)));
    int* ind;
    ind=(int*)malloc(n*sizeof(int));
    printf("\nEnter Cost Matrix : \n");
    for(int i=0;i<n;i++)
    {
        ind[i]=i;
        costmatrix[i]=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&costmatrix[i][j]);
        }
    }
    int mincost=INT_MAX;
    int minarr[n];
    generate_permutations(costmatrix,ind,n,&mincost,minarr,0);
    printf("\nMinimum Cost is %d\nFor the Order : \t",mincost);
    for(int i=0;i<n;i++)
    {
        printf("%d ",minarr[i]+1);
    }
    printf("\n");
}