#include<stdio.h>
#include<stdlib.h>
#include "Tree.c"

Nodeptr copy(Nodeptr root){
    if(root==NULL)
        return NULL;
    Nodeptr ctree = getnode();
    ctree->data = root->data;
    ctree->lchild = ctree->rchild = NULL;
    ctree->lchild = copy(root->lchild);
    ctree->rchild = copy(root->rchild);

    return ctree;
}

int equals(Nodeptr Tree1,Nodeptr Tree2){
    if (Tree1 == NULL && Tree2 == NULL) {
        return 1;
    }
    return (Tree1 && Tree2) && (Tree1->data == Tree2->data) &&
            equals(Tree1->lchild, Tree2->lchild) &&
            equals(Tree1->rchild, Tree2->rchild);
}

int main(){
    Nodeptr tree1 = NULL;
    Nodeptr tree2 = NULL;
    create_iter_BT(&tree1);
    tree2 = copy(tree1);
    if(equals(tree1,tree2))
        printf("\nThey are equal");
    else
        printf("\nThey are not equal");
}