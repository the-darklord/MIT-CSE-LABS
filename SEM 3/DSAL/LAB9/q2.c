#include <stdio.h>
#include "LL.c"

Nodeptr Union(Nodeptr l1,Nodeptr l2)
{
    Nodeptr t1,t2;
    t1=l1;
    t2=l2;
    while(t2)
    {
        if(Contains(t1,t2->data))
        {
            DeleteKey(&t2,t1->data);
        }
        else
        {
            t1=InsertLast(t1,t2->data);
        }
        t2=t2->next;
    }
    return l1;
}

Nodeptr Intersection(Nodeptr l1,Nodeptr l2)
{
    Nodeptr t1,t2,t3=NULL;
    t1=l1;
    t2=l2;
    while(t2)
    {
        if(Contains(t1,t2->data))
        {
            t3=InsertLast(t3,t2->data);
        }
        t2=t2->next;
    }
    return t3;
}

void main()
{
    Nodeptr first=NULL,second=NULL,un,in;
    first=InsertLast(first,1);
    first=InsertLast(first,2);
    first=InsertLast(first,3);
    first=InsertLast(first,4);
    second=InsertLast(second,4);
    second=InsertLast(second,5);
    second=InsertLast(second,6);
    second=InsertLast(second,3);
    printf("List 1 : \n");
    Display(first);
    printf("List 2 : \n");
    Display(second);
    in=Intersection(first,second);
    un=Union(first,second);
    printf("Union : \n");
    Display(un);
    printf("Intersection : \n");
    Display(in);
}