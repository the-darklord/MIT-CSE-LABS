#include<stdio.h>
#define MAX 10

typedef struct
{
    int queue[MAX];
    int front,rear;
}Queue;

void insq(Queue* q,int ele)
{
    if((q->rear+1) == MAX)
    {
        printf("Queue is Full!\n");
        return;
    }
    if(q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = ele;
}

int delq(Queue* q)
{
    if(q->front == -1)
    {
        return -1;
    }
    
    int ele = q->queue[q->front];
    q->front++;
    return ele;
}

void dispq(Queue* q)
{
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ",q->queue[i]);
    }
    printf("\n");
}

int find_ele(Queue* q,int ele)
{
    for(int i =q->front;i<=q->rear;i++)
    {
        if(q->queue[i] == ele)
        {
            return 1;
        }
    }
    return 0;
}

void main()
{
    Queue que,*q = &que; 
    q->front=q->rear=-1;
    insq(q,1);
    insq(q,2);
    insq(q,3);
    insq(q,4);
    dispq(q);
    if(find_ele(q,3))
    {
        printf("Element Found\n");
    }
    else
    {
        printf("Element not found\n");
    }
    printf("\nDeleted element: %d",delq(q));
}