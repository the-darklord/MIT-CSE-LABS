#include <stdio.h>
#define MAX 10

typedef struct
{
    int stack[MAX];
    int tos;
} Stack;

void enqueue(Stack *s,int x) 
{
    if(s->tos==MAX-1)
    {
        printf("Queue Full");
        return;
    }
    else
    {
        s->stack[++(s->tos)] = x; 
    }
}

int dequeue(Stack *s)
{
    if(s->tos==-1)
    {
        printf("Queue Empty");
        return -1;
    }
    else
    {
        return s->stack[(s->tos)--];
    }
}

int main()
{
    Stack s1;
    Stack s2;
    s1.tos = -1;
    s2.tos = -1;
    int choice,t;
    printf("\n1. Enqueue, 2. Dequeue, -1. Exit\n");
    printf("Enter choice : \t");
    scanf("%d",&choice);
    do
    {
        if(choice!=1&&choice!=2)
        {
            choice = -1;
        }
        if (choice == 1)
        {
            printf("\nEnter number to enqueue : \t");
            scanf("%d",&t);
            enqueue(&s1,t);
        }
        else if (choice == 2)
        {
            if (s2.tos == -1) {
                while (s1.tos != -1)
                {
                    enqueue(&s2,dequeue(&s1));
                }
            }
            printf("\nNumber dequeued: %d\n",dequeue(&s2));
        }

        printf("\n1. Enqueue, 2. Dequeue, -1. Exit\n");
        printf("Enter choice : \t");
        scanf("%d",&choice);
    } while (choice != -1);
}