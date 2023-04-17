typedef struct node* Nodeptr;
struct node
{
    int data;
    Nodeptr next;
};

Nodeptr getnode()
{
    return (Nodeptr)calloc(1,sizeof(struct node));
}

Nodeptr InsL(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
    temp->next=NULL;
    if(root)
    {
        Nodeptr last=root;
        while(last->next)
        {
            last=last->next;
        }
        last->next=temp;
        return root;
    }
    return temp;
}

void Display(Nodeptr list)
{
    if(!list)
    {
        printf("NULL");
    }
    while(list)
    {
        printf("%d \t",list->data);
        list=list->next;
    }
    printf("\n");
}
