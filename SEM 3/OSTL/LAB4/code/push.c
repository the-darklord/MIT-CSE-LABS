#include <stdio.h>

void push(int a[100],int size,int ele,int *ptos)
{
if(*ptos==size-1)
{
printf("Stack is Full");
}
else
{
(*ptos)++;
a[*ptos]=ele;
}
}
