#include "Tree.c"

int main(){
    Nodeptr Tree = NULL,F=NULL;
    create_iter_BT(&Tree);
    printf("Inorder : ");
    inorder(Tree);
    printf("\nPreorder : ");
    preorder(Tree);
    printf("\nPostorder : ");
    postorder(Tree);
    printf("\n");
}