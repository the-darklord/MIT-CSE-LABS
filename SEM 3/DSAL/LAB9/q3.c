#include <stdio.h>
#include "CLL.c"

Nodeptr sortlist(Nodeptr first)
{
    Nodeptr temp=first,rear;
    char x;
    if(isEmpty(temp))
    {
        return NULL;
    }
    else
    {
        do
        {
            rear=temp->next;
            while(rear!=temp)
            {
                if(temp->data < rear->data)
                {
                    x=temp->data;
                    temp->data=rear->data;
                    rear->data=x;
                }
                rear=rear->next;
            }
            temp=temp->next;
        }while(temp->next!=first);
    }
    return temp;
}

void main()
{
    Nodeptr first=NULL,second=NULL,temp,final=NULL;
    first=InsertLast(first,'d');
    first=InsertLast(first,'e');
    first=InsertLast(first,'f');
    second=InsertLast(second,'a');
    second=InsertLast(second,'b');
    second=InsertLast(second,'c');
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