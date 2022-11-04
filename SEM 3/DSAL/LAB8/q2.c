#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    char str[MAX][100];
    int front,rear;
}queue;

void insf(queue *ptr,char item[])
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        ptr->front=0;
        ptr->rear=0;
    }
    if(ptr->front==0)
    {
        printf("Can't Insert Front ");
        exit(0);
    }
    else
    {
        strcpy(ptr->str[--ptr->front],item);
    }
}
void insr(queue *ptr,char item[])
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        ptr->front=0;
    }
    if(ptr->rear==MAX-1)
    {
        printf("Can't Insert Rear ");
        exit(0);
    }
    else
    {
        strcpy(ptr->str[++ptr->rear],item);
    }
}
char* delf(queue *ptr)
{
    char *x;
    x = (char *)malloc(100*sizeof(char));
    if(ptr->rear==ptr->front)
    {
        printf("Queue Empty");
        exit(1);
    }
    else
    {
        strcpy(x,ptr->str[ptr->front++]);
        return x;
    }
}
void display(queue *ptr)
{
    for(int i=ptr->front;i<=ptr->rear;i++)
    {
        printf("%s \t",ptr->str[i]);
    }
    printf("\n");
}
void main()
{
    queue q1,*ptr=&q1;
    ptr->front=-1;
    ptr->rear=-1;
    insr(ptr,"Hi");
    insr(ptr,"Hello");
    display(ptr);
    insr(ptr,"Mihir");
    display(ptr);
    printf("\n\nDeleted Element : %s\n\n",delf(ptr));
    display(ptr);
    insf(ptr,"TDL");
    display(ptr);
}