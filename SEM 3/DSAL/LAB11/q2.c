#include<stdio.h>
#include<stdlib.h>
#include "Stack.c"
#include "Queue.c"
#include "Tree.c"

void iterative_inorder(Nodeptr root){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    Nodeptr curr = root;
    while(curr != NULL || !(isEmpty(ps))){
        while(curr){
            push(ps,curr);
            curr = curr->lchild;
        }
        curr = pop(ps);
        printf("%d ",curr->data);
        curr = curr->rchild;
    }
}

void iterative_preorder(Nodeptr root){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    Nodeptr curr = root;
    while(curr != NULL || !(isEmpty(ps))){
        while(curr){
            printf("%d ",curr->data);
            push(ps,curr);
            curr = curr->lchild;
        }
        curr = pop(ps);
        curr = curr->rchild;
    }
}

void iterative_postorder(Nodeptr root){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    Nodeptr curr = root;
    Nodeptr prev = NULL;
    while(curr != NULL || !(isEmpty(ps))){
        if(curr){
            push(ps,curr);
            curr = curr->lchild;
        }
        else{
            curr = top(ps);
            if(curr->rchild == NULL || curr->rchild == prev){
                printf("%d ",curr->data);
                pop(ps);
                prev = curr;
                curr = NULL;
            }
            else    
                curr = curr->rchild;
        }
    }
}

void level_order(Nodeptr root){
    Queue *pq,q;
    pq = &q;
    pq->front = pq->rear = -1;
    Nodeptr curr = root;
    enqueue(pq,curr);
    while(!(isQEmpty(pq))){
        curr = dequeue(pq);
        printf("%d ",curr->data);

        if(curr->lchild){
            enqueue(pq,curr->lchild);
        }
        if(curr->rchild){
            enqueue(pq,curr->rchild);
        }
    }
}

  
int main(){
    Nodeptr Tree = NULL;
    create_iter_BT(&Tree);
    printf("Inorder : ");
    iterative_inorder(Tree);
    printf("\nPreorder : ");
    iterative_preorder(Tree);
    printf("\nPostorder : ");
    iterative_postorder(Tree);
    printf("\nLevel Order : ");
    level_order(Tree);
}