#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

struct node
{
    int data;
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

Nodeptr InsertFront(Nodeptr first,int item)
{
    Nodeptr temp;
    temp = getnode();
    temp->data=item;
    temp->next=first;
    return temp;
}

Nodeptr InsertLast(Nodeptr first,int item)
{
    Nodeptr temp,rear;
    temp=getnode();
    rear=getnode();
    temp->data = item;
    temp->next = NULL;
    rear=first;
    if(isEmpty(first))
    {
        first = temp;
    }
    else
    {
        while(rear->next)
        {
            rear=rear->next;
        }
        rear->next=temp;
    }
    return first;
}

int DeleteFront(Nodeptr *first)
{
    Nodeptr temp;
    int x;
    temp = *first;
    if(isEmpty(*first))
    {
        printf("List is Empty");
        return -1;
    }
    else
    {
        *first = (*first)->next;
        x=temp->data;
        free(temp);
        return x;
    }
}

int DeleteLast(Nodeptr *first)
{
    Nodeptr prev,temp;
    int x;
    if(isEmpty(*first))
    {
        printf("Empty List");
        return -1;
    }
    else
    {
        prev=NULL;
        temp = *first;
        while(temp->next)
        {
            prev=temp;
            temp=temp->next;
        }
        x = temp->data;
        if(isEmpty(prev))
        {
            *first = NULL;
        }
        else
        {
            prev->next = NULL;
        }
        free(temp);
        return x;
    }
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
        while(temp)
        {
            rear=temp->next;
            while(rear)
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

void DeleteKey(Nodeptr *first, int key) 
{ 
    Nodeptr temp = *first,prev; 
    while (temp != NULL && temp->data == key) 
    { 
        *first = temp->next;
        free(temp); 
        temp = *first; 
    }  
    while (temp != NULL) 
    { 
        while (temp != NULL && temp->data != key) 
        { 
            prev = temp; 
            temp = temp->next; 
        } 
        if (temp == NULL) return; 
        prev->next = temp->next; 
        free(temp);  
        temp = prev->next; 
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
        while(temp)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int Contains(Nodeptr first,int ele)
{
	Nodeptr temp=first;
	while(temp)
	{
		if(temp->data==ele)
		{
            return 1;
		}
		temp=temp->next;
	}
    return 0;
}