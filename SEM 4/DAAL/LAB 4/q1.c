#include <stdio.h>
#include <stdlib.h>

void store(int* minArr,int *ind,int n)
{
    for(int i=0;i<n;i++)
    {
        minArr[i]=ind[i]+1;
    }
}

void swap( int *a, int *b) 
{ 
  int temp = *a; 
  *a = *b; 
  *b = temp; 
} 

void permute(int**jp,int *ind,int start,int end,int n,int *minArr,int *minCost) 
{
    if(start==end)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=jp[i][ind[i]];
        }
        if(*minCost==0||*minCost>sum)
        {
            *minCost=sum;
            store(minArr,ind,n);
        }
        
    }
    else
    {
        for(int i=start;i<=end;i++)
        {
            swap((ind+start),(ind+i));
            permute(jp,ind,start+1,end,n,minArr,minCost);
            swap((ind+start),(ind+i));
        }
    }
} 

void main()
{
    int n;
    printf("Enter Number of Persons/Jobs : \t");
    scanf("%d",&n);
    int **arr=(int **)calloc(n,sizeof(int *));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            printf("Enter Assignment Cost of J%d , P%d : \t",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    int ind[n];
    int minSal=0,minArr[n];
    for(int i=0;i<n;i++)
    {
        ind[i]=i;
        minArr[i]=0;
    }
    permute(arr,ind,0,n-1,n,minArr,&minSal);
    printf("\nMinimum Cost is %d\n",minSal);
    printf("For the Order\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",minArr[i]);
    }
    printf("\n");
}