#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mihir.c"

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void main()
{
    char str[MAX],temp,x;
    STACK s1,s2,*ptr=&s1,*ptr1=&s2;
    printf("Enter a Infix Expression \t");
    scanf("%s",str);
    ptr->tos=-1;
    ptr1->tos=-1;
    int i,n=strlen(str);
    for(i=0;i<n/2;i++)
    {
        temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    i=0;
    while(str[i]!='\0')
    {
        if(isdigit(str[i]))
        {
            push(str[i],ptr1);
        }
        else if(str[i]==')')
        {
            push(str[i],ptr);
        }
        else if(str[i]=='(')
        {
            while((x=pop(ptr))!=')')
            {
                push(x,ptr1);
            }
        }
        else
        {
            while(priority(ptr->stack[ptr->tos])>=priority(str[i]))
            {
                push(pop(ptr),ptr1);
            }
            push(str[i],ptr);
        }
        i++;
    }
    do
    {
        push(pop(ptr),ptr1);
    }
    while(ptr->tos!=-1);
    do
    {
        printf("%c",pop(ptr1));
    }
    while(ptr1->tos!=-1);
    printf("\n");
}