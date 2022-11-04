#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

//code not completed
typedef struct
{
    int a[MAX],front,rear;
}queue;

int isempty(queue *ptr)
{
    if(ptr->front==ptr->rear)
    {
        return 1;
    }
    return 0;
}

void insr(queue *ptr,int item)
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        ptr->front=0;
    }
    if(ptr->rear==MAX-1)
    {
        printf("Queue Full \n");
    }
    else
    {
        (ptr->rear)++;
        ptr->a[ptr->rear]=item;
    }    
}
int delf(queue *ptr)
{
    if(isempty(ptr))
    {
        printf("Queue Empty \n");
        exit(1);
    }
    else
    {
        int x=ptr->a[ptr->front];
        for(int i=ptr->front;i<ptr->rear;i++)
        {
            ptr->a[i]=ptr->a[i+1];
        }
        (ptr->front)--;
        (ptr->rear)--;
        return x;
    }
}

void display(queue *ptr)
{
    for(int i=ptr->front;i<=ptr->rear;i++)
    {
        printf("%d ",ptr->a[i]);
    }
    printf("\n");
}

void main()
{
    queue q1,*ptr=&q1;
    ptr->front=-1;
    ptr->rear=-1;
    int arr[MAX],ele;
    for(int i=0;i<MAX;i++)
    {
        printf("Enter Element to insert : \t");
        scanf("%d",&ele);
        insr(ptr,ele);
    }
    printf("Initial Queue Elements \n");
    display(ptr);
    int i=0;
    while(i<MAX)
    {
        int x = delf(ptr);
        arr[i]=x;
        i++;
    }
    i=MAX-1;
    while(i>=0)
    {
        int x = arr[i];
        insr(ptr,x);
        i--;
    }
    printf("\nFinal Queue Elements \n");
    display(ptr);
}