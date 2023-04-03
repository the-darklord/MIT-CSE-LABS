#include <stdio.h>
#include <stdlib.h>
#include "BST.c"

int balfac(Nodeptr root)
{
    return height(root->lchild)-height(root->rchild);
}

Nodeptr leftrotate(Nodeptr x)
{
    Nodeptr y=x->rchild;
    Nodeptr z=y->lchild;

    y->lchild=x;
    x->rchild=z;

    return y;
}

Nodeptr rightrotate(Nodeptr x)
{
    Nodeptr y=x->lchild;
    Nodeptr z=y->rchild;

    y->rchild=x;
    x->lchild=z;
    return y;
}

Nodeptr Insert_AVL(Nodeptr root,int item)
{
    if (!root)
    {
        root = getnode();
        root->data= item;
        root->lchild=root->rchild = NULL;
        return root;
    }
    if (item<root->data)
            root->lchild = Insert_AVL(root->lchild, item);
        else if (item>root->data)
            root->rchild = Insert_AVL(root->rchild, item);
        else
            return root;
    
    int bal=balfac(root);

    if (bal > 1 && item < root->lchild->data)
        return rightrotate(root);
 
    if (bal < -1 && item > root->rchild->data)
        return leftrotate(root);

    if (bal > 1 && item > root->lchild->data)
    {
        root->lchild =  leftrotate(root->lchild);
        return rightrotate(root);
    }
 
    if (bal < -1 && item < root->rchild->data)
    {
        root->rchild = rightrotate(root->rchild);
        return leftrotate(root);
    }
 
    return root;
}

Nodeptr create_AVL(Nodeptr root,int data)
{
    int x;
    root=getnode();
    root->data=data;
    root->lchild=root->rchild=NULL;
    while(1)
    {
        printf("Enter data to insert (-1 to exit) : \t");
        scanf("%d",&x);
        if(x==-1)
        {
            break;
        }
        root=Insert_AVL(root,x);
    }
    return root;
}

void preorder(Nodeptr root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void main()
{
    Nodeptr root=NULL;
    int data;
    printf("Enter Root Data : \t");
    scanf("%d",&data);
    root=create_AVL(root,data);
    printf("\n");
    preorder(root);
    printf("\n");
}