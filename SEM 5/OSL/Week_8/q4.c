#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Array
{
    int* arr;
    int n;
    int sumO,sumE;
}Array;

void* child_threadO(void* param)
{
    Array* arr=(Array*)param;

    int sum=0;
    
    for(int i=0;i<arr->n;i++)
    {
        if(arr->arr[i]%2==1)
        {
            sum += arr->arr[i];
        }
    }

    arr->sumO=sum;

    return arr;
}

void* child_threadE(void* param)
{
    Array* arr=(Array*)param;

    int sum=0;
    
    for(int i=0;i<arr->n;i++)
    {
        if(arr->arr[i]%2==0)
        {
            sum += arr->arr[i];
        }
    }

    arr->sumE=sum;

    return arr;
}

void main()
{
    pthread_t thread[2];
    int osum,esum;
    Array arr;
    printf("Enter a Number : \t");
    scanf("%d",&arr.n);

    arr.arr=(int*)calloc(arr.n,sizeof(int));

    printf("\nEnter Array : \n");
    for(int i=0;i<arr.n;i++)
    {
        scanf("%d",&arr.arr[i]);
    }

    pthread_create(&thread[0],0,&child_threadE,(void**)&arr);
    pthread_create(&thread[1],0,&child_threadO,(void**)&arr);

    pthread_join(thread[0],(void**)&arr);
    pthread_join(thread[1],(void**)&arr);
    
    printf("Even Numbers sum is %d\n",arr.sumE);
    printf("Odd Numbers sum is %d\n",arr.sumO);
}