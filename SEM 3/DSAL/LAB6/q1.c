#include<stdio.h>
#include <string.h>
#include "mihir.c"
int evaluate(char x,int op1,int op2)
{
    switch(x)
    {
        case '+':
        {
            return (op1+op2);
        }
        case '-':
        {
            return (op1-op2);
        }
        case '*':
        {
            return (op1*op2);
        }
        case '/':
        {
            return (op1/op2);
        }
        case '%':
        {
            return (op1%op2);
        }
    }
}
void main()
{
    char str[MAX],temp;
    STACK s1 , *ptr=&s1;
    printf("Enter a Prefix expression \t");
    scanf("%s",str);
    int i,n=strlen(str),op1,op2,val;
    ptr->tos=-1;
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
            push(str[i]-'0',ptr);
        }
        else
        {
            op1=pop(ptr);
            op2=pop(ptr);
            val=evaluate(str[i],op1,op2);
            push(val,ptr);
        }
        i++;
    }
    val=pop(ptr);
    printf("Value of Expression is %d \n",val);
}