#include <stdio.h>
#include "mihir.c"
void display(STACK *s1)
{
    for(int i=0;i<=s1->tos;i++)
    {
        printf("%c",s1->stack[i]);
    }
}
void main()
{
    STACK s1,*ps1;
    ps1 = &s1;
    ps1->tos=-1;
    int choice=0;
    char ele;
    while(choice==0||choice==1||choice==2||choice==3)
    {
        printf("Enter your choice \n 1)Push \t 2)Pop \t 3)Display \t 4)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter Character to push : \t");
                scanf(" %c",&ele);
                push(ele,ps1);
                break;
            }
            case 2:
            {
                printf("Popped Character is %c \n",pop(ps1));
                break;
            }
            case 3:
            {
                display(ps1);
                printf("\n");
                break;
            }
        }
    }
}