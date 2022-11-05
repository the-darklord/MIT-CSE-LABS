#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

struct node
{
    char data;
    Nodeptr next;
};

Nodeptr getnode()
{
    Nodeptr temp;
    temp = (Nodeptr)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("No Free Space");
        return NULL;
    }
    return temp;
}

int isEmpty(Nodeptr list)
{
   if(list==NULL)
    {
        return 1;
    }
   return 0;
}


Nodeptr InsertLast(Nodeptr first,int item)
{
    Nodeptr temp,rear;
    temp=getnode();
    temp->data = item;
    rear=first;
    temp->next = first;
    if(isEmpty(first))
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        while(rear->next!=first)
        {
            rear=rear->next;
        }
        rear->next=temp;
        return first;
    }
}

void Display(Nodeptr first)
{
    Nodeptr temp;
    if(isEmpty(first))
    {
        printf("\nList is Empty\n");
    }
    else
    {
        temp=first;
        while(temp->next!=first)
        {
            printf("%c\t",temp->data);
            temp=temp->next;
        }
        printf("%c\n",temp->data);
    }
}