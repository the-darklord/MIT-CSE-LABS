#include <stdio.h>

int opc=0;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int A[],int l,int r)
{
    int p=A[l];
    int i=l,j=r+1;
    do
    {
        do
        {
            i++;
        }while(A[i]<p&&i<=r);
        do
        {
            j--;
        }while(A[j]>p);
        if(i<j)
        {
            swap(&A[i],&A[j]);
        }
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}

void QuickSort(int A[],int l,int r)
{
    opc++;
    if(l<r)
    {
        int s=Partition(A,l,r);
        QuickSort(A,l,s-1);
        QuickSort(A,s+1,r);
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
    QuickSort(A,0,n-1);
    printf("\nSorted Array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\nOpcount : %d\n\n",opc);
}