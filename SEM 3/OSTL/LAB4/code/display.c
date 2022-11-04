#include <stdio.h>

void display(int a[100],int *ptos)
{
for(int i=0;i<*ptos+1;i++)
{
printf("%d ",a[i]);
}
}
