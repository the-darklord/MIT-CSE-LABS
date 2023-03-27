#include <stdio.h>
#include <stdlib.h>

int count=0,opc=0;

typedef struct node * Nodeptr;
struct node
{
    int data;
    Nodeptr lchild;
    Nodeptr rchild;
    int balance_factor;
};

Nodeptr getnode()
{
    return ((Nodeptr)malloc(sizeof(struct node)));
}

Nodeptr Insert_BST(Nodeptr root, int item)
{
    if (!root)
    {
        root = getnode();
        root->data= item;
        root->balance_factor=0;
        root->lchild=root->rchild = NULL;
        return root;
    }
    else
    {
        if (item<root->data)
            root->lchild = Insert_BST(root->lchild, item);
        else if (item>root->data)
            root->rchild = Insert_BST(root->rchild, item);
        else
            printf("Duplicates are not allowed\n");
        return root;
    }
}

Nodeptr create_BST(Nodeptr root,int data)
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
        root=Insert_BST(root,x);
    }
    return root;
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

void balancefactor(Nodeptr root)
{
    if(root)
    {
        root->balance_factor=height(root->lchild)-height(root->rchild);
        balancefactor(root->lchild);
        balancefactor(root->rchild);
    }
}

void printbalancefactor(Nodeptr root)
{
    if(root)
    {
        printbalancefactor(root->lchild);
        printf("%d ---> %d\n",root->data,root->balance_factor);
        printbalancefactor(root->rchild);
    }
}

void main()
{
    int x;
    printf("Enter Root Data : \t");
    scanf("%d",&x);
    Nodeptr root=create_BST(root,x);
    printf("\n");
    balancefactor(root);
    printbalancefactor(root);
    printf("\n\n");
}