#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *queue;
    int front,rear;
} Queue;

void enqueue(Queue * q,int x)
{
    if (q->front == -1&&q->rear == -1)
    {
        q->front = 0;
    }
    q->queue[++(q->rear)] = x;
}

int isempty(Queue *q)
{
    if ((q->front == -1 && q->rear==-1) || (q->front > q->rear))
        return 1;
    return 0;
}

int dequeue(Queue * q)
{
    if(isempty(q))
    {
        printf("\nEmpty Queue\n");
        return -1;
    }
    else
    {
        int x = q->queue[q->front];
        int i,ind=q->front;
        for(i=q->front+1;i<=q->rear;i++) 
            q->queue[ind++] = q->queue[i];
        q->rear--;
        return x;
    }
}

int main()
{
    int n,i,j,t;
    printf("Enter Size of Queue : \t");
    scanf("%d",&n);
    Queue q;
    q.rear = -1;
    q.front = -1;
    q.queue = (int *) malloc(n * sizeof(int));

    for(i=0;i<n;i++)
    {
        printf("\nEnter Element %d to insert into Queue : \t",i+1);
        scanf("%d",&t);
        enqueue(&q,t);
    }

    printf("\nInitial Queue\n");
    for(i=0;i<n;i++) 
        printf("%d ",q.queue[i]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            t = dequeue(&q);
            enqueue(&q,t);
        }
        q.front=i+1;
    }

    printf("\n\nReversed Queue \n");
    for(i=0;i<n;i++) 
        printf("%d ",q.queue[i]);
}