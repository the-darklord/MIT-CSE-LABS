#include<stdio.h>
#include<stdlib.h>
#include "Tree.c"
#include "Stack.c"

void printAncestors(Nodeptr root,int key){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    while(1){
        while(root && root->data != key){
            push(ps,root);
            root = root->lchild;
        }
        if(root && root->data == key){break;}
        if(top(ps)->rchild == NULL){
            root = pop(ps);
            while(!(isEmpty(ps)) && top(ps)->rchild == root){
                root = pop(ps);
            }  
        }
        if(isEmpty(ps))
            root = NULL;
        else
            root = top(ps)->rchild;
    }

    while(!(isEmpty(ps))){
        printf("%d ",pop(ps)->data);
    }
}

int main(){
    Nodeptr Tree = NULL;
    create_iter_BT(&Tree);
    printf("Ancestors of 6 are: ");
    printAncestors(Tree,6);
}