#include <stdio.h>

int fib(int n,int *opc )
{
    (*opc)++;
    if(n==1||n==0)
    {
        return n;
    }
    else
    {
        return fib(n-1,opc)+fib(n-2,opc);
    }
}

void main()
{
    int n,opc=0;
    printf("Enter Number : \t");
    scanf("%d",&n);
    printf("Fibonnaci Number is %d\n",fib(n-1,&opc));
    printf("\nOPCOUNT is %d\n",opc);
}