#include <stdio.h>
#include <stdlib.h>

//NOT DONE


void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int arr[],int n,int i)
{
    int largest=i;
    int lc=2*i + 1;
    int rc=2*i + 2;

    if(lc<n&&arr[lc]<arr[largest])
    {
        largest=lc;
    }
    if(rc<n&&arr[rc]<arr[largest])
    {
        largest=rc;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
    else
    {
        heapify(arr,n,i);
    }
}

void main()
{
    int n;
    printf("Enter Array Size : \t");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Array : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

        if(i>=2)
        {
            heapify(arr,i+1,0);
        }
    }
    printf("Heap is : \n");
    for(int i=n-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}