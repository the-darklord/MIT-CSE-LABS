#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct
{
    char stack[MAX];
    int tos;
}STACK;
void push(char x,STACK *ptr);
char pop(STACK *ptr);
void push(char x,STACK *ptr)
{
    if (ptr->tos==MAX-1)
    {
        printf("Stack Overflow \n");
    }
    else
    {
        ptr->tos++;
        ptr->stack[ptr->tos]=x;
    }
}
char pop(STACK *ptr)
{
    if(ptr->tos==-1)
    {
        printf("Stack Underflow \n");
        exit(1);
    }
    else
    {
        return(ptr->stack[ptr->tos--]);
    }
}
