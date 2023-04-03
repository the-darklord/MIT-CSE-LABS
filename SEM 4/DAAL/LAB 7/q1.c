#include <stdio.h>
#include <stdlib.h>
#include "BST.c"

void balancefactor(Nodeptr root)
{
    if(root)
    {
        int balfac=height(root->lchild)-height(root->rchild);
        printf("%d ---> %d\n",root->data,balfac);
        balancefactor(root->lchild);
        balancefactor(root->rchild);
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
    printf("\n\n");
}