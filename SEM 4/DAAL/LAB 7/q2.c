#include <stdio.h>
#include <stdlib.h>
#include "BST.c"

int max(int a,int b)
{
    return a>b?a:b;
}

int height(Nodeptr root)
{
    if(root)
    {
        return max(root->lchild,root->rchild)+1;
    }
}

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
            root->lchild = Insert_BST(root->lchild, item);
        else if (item>root->data)
            root->rchild = Insert_BST(root->rchild, item);
        else
            return root;
    
    int bal=balfac(root);

    if (bal > 1 && item < root->lchild->data)
        return rightRotate(root);
 
    if (bal < -1 && item > root->rchild->data)
        return leftRotate(root);

    if (bal > 1 && item > root->lchild->data)
    {
        root->lchild =  leftRotate(root->lchild);
        return rightRotate(root);
    }
 
    if (bal < -1 && item < root->rchild->data)
    {
        root->rchild = rightRotate(root->rchild);
        return leftRotate(root);
    }
 
    return root;
}

void main()
{
    Nodeptr root=NULL;
    int data;
    printf("Enter Root Data : \t");
    scanf("%d",&data);
    root=create_BST(root,data);
}