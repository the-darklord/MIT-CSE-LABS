#include <stdio.h>
#include <stdlib.h>

int count=0,opc=0;

typedef struct node * Nodeptr;
struct node
{
    int data;
    Nodeptr lchild;
    Nodeptr rchild;
};

Nodeptr getnode()
{
    return ((Nodeptr)malloc(sizeof(struct node)));
}

Nodeptr create_BT(Nodeptr root,int data)
{
    int x;
    if(data!=-1)
    {
        Nodeptr temp=getnode();
        temp->data=data;

        printf("\nEnter lchild of %d : \t",temp->data);
        scanf("%d",&x);
        temp->lchild=create_BT(temp->lchild,x);

        printf("\nEnter rchild of %d : \t",temp->data);
        scanf("%d",&x);
        temp->rchild=create_BT(temp->rchild,x);
        return temp;
    }
    return NULL;
}

void NodeCount(Nodeptr root)
{
    opc++;
    if(root)
    {
        NodeCount(root->lchild);
        count++;
        NodeCount(root->rchild);
    }
}

void main()
{
    int x;
    printf("Enter Root Data : \t");
    scanf("%d",&x);
    Nodeptr root=create_BT(root,x);
    NodeCount(root);
    printf("\nNo. of Nodes is %d",count);
    printf("\nOpcount : %d\n\n",opc);
}