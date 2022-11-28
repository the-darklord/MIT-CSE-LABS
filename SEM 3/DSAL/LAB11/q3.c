#include "Tree.c"
#include "Stack.c"

void create_exp_tree(Nodeptr* root,char postfix[]){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    char *e = postfix;
    Nodeptr temp;
    while(*e != '\0'){
        if(*e >= '0' && *e <= '9'){
            temp = getnode();
            temp->data = *e;
            temp->rchild = temp->lchild = NULL;
            push(ps,temp);
        }
        else{
            temp = getnode();
            temp->data = *e;
            Nodeptr a = pop(ps);
            Nodeptr b = pop(ps);
            temp->rchild = a;
            temp->lchild = b;
            push(ps,temp);  
        }
        e++;
    }
    *root = pop(ps);
}

int evaluate(Nodeptr root){

    if(root->lchild == NULL && root->rchild == NULL){
        int val = root->data-'0';
        return val;
    }

    int l_val = evaluate(root->lchild);
    int r_val = evaluate(root->rchild);

    if(root->data == '+')
        return l_val+r_val;
    if(root->data == '-')
        return l_val-r_val;
    if(root->data == '*')
        return l_val*r_val;
    if(root->data == '/')
        return l_val/r_val;

}

int main(){
    Nodeptr Tree = NULL;
    char postfix[100];
    printf("Enter a Postfix Expression : \n");
    scanf("%s",postfix);
    create_exp_tree(&Tree,postfix);
    int ans = evaluate(Tree);
    printf("Value of expression: %d\n",ans);
}