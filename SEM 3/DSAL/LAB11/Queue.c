#include<stdio.h>

typedef struct node *Nodeptr;

typedef struct Queue{
    int front,rear;
    Nodeptr nodestack[30]; 
}Queue;

int isQEmpty(Queue* q){
    if(q->front == q->rear+1 || q->front == -1)
        return 1;
    return 0;
}

void enqueue(Queue* q,Nodeptr x){
    if(q->front == -1){
        q->front = 0;
    }
    q->nodestack[++q->rear] = x;
}

Nodeptr dequeue(Queue* q){
    if(q->front == q->rear+1){
        q->front = -1;
    }
    return q->nodestack[q->front++];
}

Nodeptr Atfront(Queue* q){
    return q->nodestack[q->front];
}