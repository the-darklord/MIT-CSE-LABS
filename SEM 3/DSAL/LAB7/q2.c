#include <stdio.h>
#include <stdlib.h>
#define MAX 8
#define t MAX/2

typedef struct
{
    int arr[MAX];
    int f1,r1,f2,r2;
}queue;

void insertcq(queue *ptr,int item,int c)
{
    if(c==1)
    {
        if(ptr->f1==-1&&ptr->r1==-1)
        {
            ptr->f1=0;
        }
        ptr->r1=(ptr->r1+1)%(t+1);
        ptr->arr[ptr->r1]=item;
    }
    if(c==2)
    {
        if(ptr->f2==t&&ptr->r2==t)
        {
            ptr->f2=t+1;
        }
        ptr->r2=(ptr->r2+1)%MAX;
        ptr->arr[ptr->r2]=item;
    }    
}

int deletecq(queue *ptr,int c)
{
    if(c==1)
    {
        if((ptr->r1 + 1)%t==ptr->f1)
        {
            printf("Queue 1 Empty \n");
            exit(1);
        }
        else
        {
            int n=ptr->arr[ptr->f1];
            ptr->f1=(ptr->f1+1)%(t+1);
            return n;
        }
    }
    if(c==2)
    {
        if((ptr->r2 + 1)%MAX==ptr->f2)
        {
            printf("Queue 2 Empty \n");
            exit(1);
        }
        else
        {
            int n=ptr->arr[ptr->f2];
            ptr->f2=(ptr->f2+1)%MAX;
            return n;
        }
    }
}

void displaycq(queue *ptr)
{
    printf("\nQueue 1 Elements\n");
    for(int i=ptr->f1;i!=(ptr->r1+1);i=(i+1)%(t+1))
    {
        printf("%d \n",ptr->arr[i]);
    }
    printf("\nQueue 2 Elements\n");
    for(int i=ptr->f2;i!=(ptr->r2+1);i=(i+1)%MAX)
    {
        printf("%d \n",ptr->arr[i]);
    }
}

void main()
{
    queue q1,*ptr=&q1;
    ptr->f1=-1;
    ptr->r1=-1;
    ptr->f2=t;
    ptr->r2=t;
    insertcq(ptr,1,1);
    insertcq(ptr,2,1);
    displaycq(ptr);
    insertcq(ptr,3,2);
    displaycq(ptr);
    printf("\n\nDeleted Element : %d\n\n",deletecq(ptr,1));
    displaycq(ptr);
    insertcq(ptr,4,2);
    displaycq(ptr);
}