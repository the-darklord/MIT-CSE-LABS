#include <stdio.h>
#include "CLL.c"

Nodeptr sortlist(Nodeptr first)
{
    
}

void main()
{
    Nodeptr first=NULL,second=NULL,temp,final=NULL;
    first=InsertLast(first,'h');
    first=InsertLast(first,'c');
    first=InsertLast(first,'m');
    second=InsertLast(second,'f');
    second=InsertLast(second,'o');
    second=InsertLast(second,'l');
    printf("CLIST 1 : \n");
    Display(first);
    printf("CLIST 2 : \n");
    Display(second);
    temp=first;
    while(temp->next!=first)
    {
        final=InsertLast(final,temp->data);
        temp=temp->next;
    }
    final=InsertLast(final,temp->data);
    temp=second;
    while(temp->next!=second)
    {
        final=InsertLast(final,temp->data);
        temp=temp->next;
    }
    final=InsertLast(final,temp->data);
    final=sortlist(final);
    printf("Final CList : \n");
    Display(final);
}