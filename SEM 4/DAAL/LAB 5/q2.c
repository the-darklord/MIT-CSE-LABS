#include <stdio.h>
#include <stdlib.h>

int diam=0;

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

int max(int a,int b)
{
    return a>b?a:b;
}

int height(Nodeptr root)
{
    if(root)
    {
        return max(height(root->lchild),height(root->rchild))+1;
    }
}

int findDiam(Nodeptr root)
{
    if(root)
    {
        int lh,rh,temp;
        lh=height(root->lchild);
        rh=height(root->rchild);
        temp=lh+rh+1;
        findDiam(root->lchild);
        findDiam(root->rchild);
        if(temp>diam)
        {
            diam=temp;
        }
    }

}

void main()
{
    int x;
    Nodeptr root=NULL;
    printf("Enter Root Data : \t");
    scanf("%d",&x);
    root=create_BT(root,x);
    printf("\nDiameter is %d\n\n",findDiam(root));
}