#include <stdio.h>
#include "LL.c"

void main()
{
    Nodeptr first=NULL,final=NULL;
    first=InsertLast(first,1);
    first=InsertLast(first,2);
    first=InsertLast(first,3);
    first=InsertLast(first,4);
    first=InsertLast(first,4);
    first=InsertLast(first,5);
    first=InsertLast(first,6);
    first=InsertLast(first,3);
    printf("Initial List : \n");
    Display(first);
    while(first)
    {
        final=InsertLast(final,first->data);
        if(Contains(first->next,first->data))
        {
            DeleteKey(&first,first->data);
        }
        first=first->next;
    }
    printf("Final List : \n");
    Display(final);
}