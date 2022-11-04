#include <stdio.h>
#include "mihir.c"
void dectobin(int num,STACK *ptr)
{
    int rem;
    while(num!=0)
    {
        rem=num%2;
        push(rem,ptr);
        num /= 2;
    }
    while(ptr->tos!=-1)
    {
        printf("%d",pop(ptr));
    }
    printf("\n");
}
void main()
{
    int n;
    printf("Enter a Number : \t");
    scanf("%d",&n);
    STACK s1,*ps1=&s1;
    ps1->tos=-1;
    dectobin(n,ps1);
}