#include <stdio.h>

int opc=0;

void Merge(int B[],int b,int C[],int c,int A[])
{
    int i=0,j=0,k=0;
    while(i<b&&j<c)
    {
        if(B[i]<=C[j])
        {
            A[k++]=B[i++];
        }
        else
        {
            A[k++]=C[j++];
        }
    }
    while(i<b)
    {
        A[k++]=B[i++];
    }
    while(j<c)
    {
        A[k++]=C[j++];
    }
}

void MergeSort(int A[],int n)
{
    opc++;
    if(n>1)
    {
        int t=n/2;
        int B[t],C[n-t];
        for(int i=0;i<t;i++)
        {
            B[i]=A[i];
        }
        for(int i=t;i<n;i++)
        {
            C[i-t]=A[i];
        }
        MergeSort(B,t);
        MergeSort(C,n-t);
        Merge(B,t,C,n-t,A);
    }
}

void main()
{
    int n;
    printf("Enter Array Length : \t");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    MergeSort(A,n);
    printf("\nSorted Array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\nOpcount : %d\n\n",opc);
}