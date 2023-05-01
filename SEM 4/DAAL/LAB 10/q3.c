#include <stdio.h>
#include <stdlib.h>

int* subset;
int l=0;
int cost=0;

int max(int a,int b)
{
    return (a>b)?a:b;
}

void KnapSack(int **KS,int n,int w,int* V,int* W)
{
    int i,j,k;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            KS[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=w;j++)
        {
            if(j-W[i]>=0)
            {
                KS[i][j]=max(KS[i-1][j],V[i]+KS[i-1][j-W[i]]);
            }
            else
            {
                KS[i][j]=KS[i-1][j];
            }
        }
    }
    j=w;
    for(int i=n;i>0;i--)
    {
        if(KS[i][j]!=KS[i-1][j])
        {
            cost+=V[i];
            subset[l++]=i;
            j=j-W[i];
        }
    }
}

void main()
{
    int w,n;
    printf("Enter No. of Items : \t");
    scanf("%d",&n);
    printf("Enter Capacity : \t");
    scanf("%d",&w);
    int W[n+1],V[n+1];
    V[0]=W[0]=0;
    printf("Enter Weights of Items : \n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&W[i]);
    }
    printf("Enter Prices of Items : \n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&V[i]);
    }
    int **KS=(int**)calloc(n+1,sizeof(int*));
    for(int i=0;i<=n;i++)
    {
        KS[i]=(int*)malloc((w+1)*sizeof(int));
    }
    subset=(int*)calloc(n+1,sizeof(int));
    KnapSack(KS,n,w,V,W);
    printf("\nKnapSack Table is \n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            printf("%d\t",KS[i][j]);
        }
        printf("\n");
    }
    printf("\nKnapSack Items are : \t");
    for(int i=l;i>0;i--)
    {
        printf("%d ",subset[i]);
    }
    printf("\n\nCost is : %d\t",cost);
    printf("\n\n");
}