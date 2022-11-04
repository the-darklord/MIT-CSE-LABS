#include <stdio.h>
#define MAX 10

typedef struct
{
    int stack[MAX],tos1,tos2;
}STACK;

void push(int x,int i,STACK *ptr)
{
    if(ptr->tos1+1 == ptr->tos2)
    {
        printf("Stack Overflow \n");
        return ;
    }
    else if(i==1)
    {
        ptr->stack[++ptr->tos1] = x;
    }
    else if(i==2)
    {
        ptr->stack[--ptr->tos2] = x;
    }
}
int pop(int i,STACK *ptr)
{
    if(i==1)
    {
        if(ptr->tos1==-1)
        {
            printf("Stack Underflow \n");
            return -1;
        }
        else
        {
            return ptr->stack[ptr->tos1--];
        }
    }
    if(i==2)
    {
        if(ptr->tos2==MAX)
        {
            printf("Stack Underflow \n");
            return -1;
        }
        else
        {
            return ptr->stack[ptr->tos2++];
        }
    }
}
int main()
{
    STACK s1,*ptr=&s1;
    ptr->tos1=-1;
    ptr->tos2=MAX;

    push(5,1,ptr);
    push(6,1,ptr);
    push(7,2,ptr);
    push(8,2,ptr);
    printf("%d\n%d\n%d\n%d\n",pop(1,ptr),pop(2,ptr),pop(1,ptr),pop(2,ptr));

    return 0;
}