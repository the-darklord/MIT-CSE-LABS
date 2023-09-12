#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Bounds
{
    int u,l;
}Bounds;

int isPrime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void* child_thread(void* param)
{
    Bounds* arr=(Bounds*)param;
    
    for(int i=arr->l;i<=arr->u;i++)
    {
        if(isPrime(i))
        {
            printf("%d ",i);
        }
    }
}

void main()
{
    pthread_t thread;
    int sum;
    Bounds arr;
    printf("Enter Lower and Upper Bounds : \n");
    scanf("%d %d",&arr.l,&arr.u);

    printf("\nPrime Numbers are : \n");

    pthread_create(&thread,0,&child_thread,(void**)&arr);
    pthread_join(thread,NULL);
   
    printf("\n");
}