#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* child_thread(void* n)
{
    int nn=(int)n;

    int l=0,r=1,c=0,t;

    int* arr=(int*)calloc(nn,sizeof(int));

    while(c<nn)
    {
        arr[c++]=l;
        t=l+r;
        l=r;
        r=t;
    }

    return arr;
}

void main()
{
    pthread_t thread;
    int n;
    printf("Enter a Number : \t");
    scanf("%d",&n);
    
    int* arr=(int*)calloc(n,sizeof(int));

    pthread_create(&thread,0,&child_thread,(void*)n);
    pthread_join(thread,(void**)&arr);

    printf("\nFibonacci Series is : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}