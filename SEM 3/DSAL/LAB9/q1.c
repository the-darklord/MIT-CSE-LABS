#include <stdio.h>
#include "LL.c"

void main()
{
    Nodeptr first=NULL;
    int choice=0,t;
    do
    {
        printf("\n1>Insert \t2>Delete \tAny>Exit\n");
        printf("Enter Choice : \t");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nEnter Element to Insert : \t");
            scanf("%d",&t);
            first=InsertLast(first,t);
            Display(first);
        }
        else if(choice==2)
        {
            printf("\nDeleted Element is : %d\n",DeleteFront(&first));
            Display(first);
        }
        else
        {
            choice=-1;
        }

    }while(choice!=-1);
}