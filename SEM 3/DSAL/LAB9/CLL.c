#include <stdio.h>
#include <stdlib.h>

//code not complete
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
    if(isEmpty(first))
    {
        first = temp;
    }
    else
    {
        while(rear->next!=first)
        {
            rear=rear->next;
        }
        rear->next=temp;
        temp->next = first;
    }
    return first;
}

Nodeptr sortlist(Nodeptr first)
{
    Nodeptr temp=first,rear;
    int x;
    if(isEmpty(temp))
    {
        return NULL;
    }
    else
    {
        while(temp!=first)
        {
            rear=temp->next;
            while(rear!=temp->next)
            {
                if(temp->data > rear->data)
                {
                    x=temp->data;
                    temp->data=rear->data;
                    rear->data=x;
                }
                rear=rear->next;
            }
            temp=temp->next;
        }
    }
    return first;
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
        printf("%d\n",temp->data);
    }
}