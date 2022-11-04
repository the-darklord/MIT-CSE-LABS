#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 4

typedef struct
{
    char str[MAX][100];
    int front,rear;
}queue;

void insertcq(queue *ptr,char item[])
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        ptr->front=0;
    }
    ptr->rear=(ptr->rear+1)%MAX;
    strcpy(ptr->str[ptr->rear],item);    
}

char* deletecq(queue *ptr)
{
    if((ptr->rear + 1)%MAX==ptr->front)
    {
        printf("Queue Empty \n");
        exit(1);
    }
    else
    {
        char *ch;
        ch=(char *)malloc(100*sizeof(char));
        strcpy(ch,ptr->str[ptr->front]);
        ptr->front=(ptr->front+1)%MAX;
        return ch;
    }
}

void displaycq(queue *ptr)
{
    printf("\nQueue Elements\n");
    for(int i=ptr->front;i<=ptr->rear;i++)
    {
        printf("%s \n",ptr->str[i]);
    }
}

void main()
{
    queue q1,*ptr=&q1;
    ptr->front=-1;
    ptr->rear=-1;
    insertcq(ptr,"Hi");
    insertcq(ptr,"Hello");
    displaycq(ptr);
    insertcq(ptr,"who");
    displaycq(ptr);
    printf("\n\nDeleted Element : %s\n\n",deletecq(ptr));
    displaycq(ptr);
    insertcq(ptr,"Mihir");
    displaycq(ptr);
}