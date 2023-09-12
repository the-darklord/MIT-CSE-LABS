#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Array
{
    int* arr;
    int n;
}Array;

void* child_thread(void* param)
{
    Array* arr=(Array*)param;

    int sum=0;
    
    for(int i=0;i<arr->n;i++)
    {
        sum += arr->arr[i];
    }

    return sum;
}

void main()
{
    pthread_t thread;
    int sum;
    Array arr;
    printf("Enter a Number : \t");
    scanf("%d",&arr.n);

    arr.arr=(int*)calloc(arr.n,sizeof(int));

    printf("\nEnter Array : \n");
    for(int i=0;i<arr.n;i++)
    {
        scanf("%d",&arr.arr[i]);
    }

    pthread_create(&thread,0,&child_thread,(void**)&arr);
    pthread_join(thread,(void*)&sum);
   
    printf("Sum is %d\n",sum);
}