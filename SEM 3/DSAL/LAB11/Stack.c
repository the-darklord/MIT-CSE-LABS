#include<stdio.h>

typedef struct node *Nodeptr;

typedef struct Stack{
    int top;
    Nodeptr nodestack[30]; 
}Stack;

int isEmpty(Stack* s){
    if(s->top == -1)
        return 1;
    return 0;
}

void push(Stack* s,Nodeptr x){
    s->nodestack[++s->top] = x;
}

Nodeptr pop(Stack* s){
    return s->nodestack[s->top--];
}

Nodeptr top(Stack* s){
    return s->nodestack[s->top];
}