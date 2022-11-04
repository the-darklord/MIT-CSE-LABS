#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct
{
    char stack[MAX];
    int tos;
}STACK;
void push(char x,STACK *ptr);
char pop(STACK *ptr);
void push(char x,STACK *ptr)
{
    ptr->tos++;
    ptr->stack[ptr->tos]=x;
}
char pop(STACK *ptr)
{
    return(ptr->stack[ptr->tos--]);
}
