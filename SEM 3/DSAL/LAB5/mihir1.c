#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char *stack;
    int tos;
}STACK;
void push(int n,char x,STACK *ptr);
char pop(STACK *ptr,int i);
void push(int n,char x,STACK *ptr)
{
    if (ptr->tos==n-1)
    {
        printf("Stack Overflow \n");
    }
    else
    {
        ptr->tos++;
        ptr->stack[ptr->tos]=x;
    }
}
char pop(STACK *ptr,int i)
{
    if(ptr->tos==-1)
    {
        printf("Stack Underflow \n");
        exit(1);
    }
    else
    {
        char x = ptr->stack[ptr->tos];
        for(int k=i;k<=ptr->tos;k++)
        {
            ptr->stack[k]=ptr->stack[k+1];
        }
        ptr->tos--;
        return x;
    }
}
