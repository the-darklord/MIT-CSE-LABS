#include "Tree.c"

void inorder_suc(Nodeptr root,int key){

    static int flag = 0;
    if(root){
        inorder_suc(root->lchild,key);
        if(flag == 1){
            printf("Inorder successor of %d is %d\n",key,root->data);
            flag = 0;
        }
        if(root->data == key){
            flag = 1;
        }
        inorder_suc(root->rchild,key);
    }
}

int main(){
    Nodeptr Tree = NULL;
    create_BST(&Tree);
    inorder_suc(Tree,8);
    inorder_suc(Tree,10);
    inorder_suc(Tree,14);
}