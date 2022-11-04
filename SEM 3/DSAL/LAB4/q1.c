#include <stdio.h>

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return (fib(n-1)+fib(n-2));
    }
}
void main()
{
    int n,i=0;
    printf("Enter No. of Terms : \t");
    scanf("%d",&n);
    while(i<n)
    {
            printf("%d ",fib(i));
            i++;
    }
}