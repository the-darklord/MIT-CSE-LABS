#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct
{
    char stack[MAX][MAX];
    int tos;
}STACK;
void push(char* x,STACK *ptr)
{
    strcpy(ptr->stack[++ptr->tos],x);
}
char* pop(STACK *ptr)
{
    return (ptr->stack[ptr->tos--]);
}
void main()
{
    char str[100],temp;
    printf("Enter a Prefix Expression \t");
    scanf("%s",str);
    STACK s1,*ptr=&s1;
    int n = strlen(str);
    for(int i=0;i<n/2;i++)
    {
        temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1]=temp;
    }
    int i=0;
    while(str[i]!='\0')
    {
        if(isdigit(str[i]))
        {
            char c1[2];
            c1[0]=str[i];
            c1[1]='\0';
            push(c1,ptr);
        }
        else
        {
            char op1[MAX], op2[MAX];
            char symbol=str[i];
            char temp[2];
            char strin[MAX];
            temp[0]=symbol;
            temp[1]='\0';
            strcpy(op2,pop(ptr));
            strcpy(op1,pop(ptr));
            strcpy(strin,op2);
            strcat(strin,op1);
            strcat(strin,temp);             
            push(strin,ptr);
        }
        i++;
    }
    printf("%s \n",pop(ptr));
}
