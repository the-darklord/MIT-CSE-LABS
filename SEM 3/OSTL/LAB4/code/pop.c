#include <stdio.h>

int pop(int a[100],int *ptos)
{
if(*ptos==-1)
{
printf("Stack is Empty");
return 0;
}
else
{
return(a[(*ptos)--]);
}
}
