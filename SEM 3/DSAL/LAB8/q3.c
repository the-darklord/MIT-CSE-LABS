#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    char str[MAX];
    int front,rear;
}queue;

void insf(queue *ptr,char item)
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        ptr->front=0;
        ptr->rear=0;
    }
    if(ptr->front==0)
    {
        printf("Can't Insert Front \n");
        exit(0);
    }
    else
    {
        ptr->str[--ptr->front]=item;
    }
}
void insr(queue *ptr,char item)
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        ptr->front=0;
        ptr->rear=0;
    }
    if(ptr->rear==MAX-1)
    {
        printf("Can't Insert Rear \n");
        exit(0);
    }
    else
    {
        ptr->str[++ptr->rear]=item;
    }
}
char delf(queue *ptr)
{
    char x;
    if(ptr->rear==ptr->front)
    {
        printf("Queue Empty \n");
        exit(1);
    }
    else
    {
        x=ptr->str[ptr->front++];
        return x;
    }
}
char delr(queue *ptr)
{
    char x;
    if(ptr->rear==ptr->front)
    {
        printf("Queue Empty \n");
        exit(1);
    }
    else
    {
        x=ptr->str[ptr->rear--];
        return x;
    }
}
void display(queue *ptr)
{
    for(int i=ptr->front;i<=ptr->rear;i++)
    {
        printf("%c \t",ptr->str[i]);
    }
    printf("\n");
}
void main()
{
    queue q1,*ptr=&q1;
    int flag;
    char string[100];
    ptr->front=-1;
    ptr->rear=-1;
    printf("Enter a string : \n");
    scanf("%[^\n]s",string);
    int i=0;
    while(string[i]!='\0')
    {
        insr(ptr,string[i]);
        i++;
    }
    for(int i = 0; i<= strlen(string)/2;i++)
    {
		if(delr(ptr) == string[i])
			flag = 1;
		else{
			flag =0;
			break;
		}
	}
    if(flag)
    {
        printf("String is Palindrome \n");
    }
    else
    {
        printf("String is not a Palindrome \n");
    }
}