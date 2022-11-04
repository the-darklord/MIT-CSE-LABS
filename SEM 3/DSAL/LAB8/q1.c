#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    int a[MAX],front,rear;
}queue;

void insertpq(queue *ptr,int item)
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        ptr->front=0;
    }
    (ptr->rear)++;
    ptr->a[ptr->rear]=item;    
}
int smallest(queue *ptr)
{
    int small=ptr->a[ptr->front],ind;
    for(int i=ptr->front+1;i<=ptr->rear;i++)
    {
        if(ptr->a[i]<small)
        {
            small=ptr->a[i];
            ind=i;
        }
    }
    return ind;
}
int deletepq(queue *ptr)
{
    if(ptr->rear==ptr->front)
    {
        printf("Queue Empty \n");
        exit(1);
    }
    else
    {
        int ind=smallest(ptr);
        int x=ptr->a[ind];
        for(int i=ind;i<ptr->rear;i++)
        {
            ptr->a[i]=ptr->a[i+1];
        }
        (ptr->rear)--;
        return x;
    }
}

void displaypq(queue *ptr)
{
    printf("\nQueue Elements\n");
    for(int i=ptr->front;i<=ptr->rear;i++)
    {
        printf("%d \n",ptr->a[i]);
    }
}

void main()
{
    queue q1,*ptr=&q1;
    ptr->front=-1;
    ptr->rear=-1;
    insertpq(ptr,9);
    insertpq(ptr,2);
    displaypq(ptr);
    insertpq(ptr,5);
    displaypq(ptr);
    printf("\n\nDeleted Element : %d\n\n",deletepq(ptr));
    displaypq(ptr);
    insertpq(ptr,8);
    displaypq(ptr);
}