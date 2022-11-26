#include "Tree.c"

void insert(Nodeptr* root,int val){
    Nodeptr head = *root,temp = getnode(),parent = NULL;
    temp->data = val;
    temp->rchild = temp->lchild = NULL;
    if(head == NULL){
        head = temp;
        *root = head;
        return;
    }
    while(head != NULL){
        parent = head;
        if(val > head->data){
            head = head->rchild;
        }
        else{
            head = head->lchild;
        }
    }
    if(val > parent->data){
        parent->rchild = temp;
    }
    else{
        parent->lchild = temp;
    }
    return;
}

void create_BST(Nodeptr* root){
    int val;
    while(1){
        printf("Enter the value you want to insert(-1 to exit) : ");
        scanf("%d",&val);
        if(val == -1){break;}
        insert(root,val);
    }
}

void delete(Nodeptr* root,int key){
    Nodeptr temp = *root;
    Nodeptr prev = NULL;
    while(key != temp->data){
        prev = temp;
        if(key > temp->data)
            temp = temp->rchild;
        else
            temp = temp->lchild;
    }
    if(temp->rchild!=NULL && temp->lchild!=NULL){
        Nodeptr temp2 = temp->rchild;
        Nodeptr prev2 = temp;
        int smallest = temp2->data;
        while(temp2->lchild != NULL){
            prev2 = temp2;
            temp2 = temp2->lchild;
            smallest = temp2->data;
        }
        if(temp2->rchild){
            temp->data = smallest;
            temp2->data = temp2->rchild->data;
            prev2 = temp2;
            temp2 = temp2->rchild;
            free(temp2);
            prev2->rchild = NULL; 
        }
        else{
            if(prev2->rchild->data == smallest)
                prev2->rchild = NULL;
            else
                prev2->lchild = NULL;
            temp->data = smallest;
            free(temp2);
        }
    }
    else if(temp->rchild!=NULL || temp->lchild!=NULL){
        if(temp->rchild){
            Nodeptr child = temp->rchild;
            temp->data = child->data;
            temp->rchild = NULL;
            free(child);
        }
        else{
            Nodeptr child = temp->lchild;
            temp->data = child->data;
            temp->lchild =NULL;
            free(child);
        }
    }
    else{
        free(temp);
        if(key > prev->data)
            prev->rchild = NULL;
        else
            prev->lchild = NULL;
    }
}

int main(){
    Nodeptr Tree = NULL;
    create_BST(&Tree);
    inorder(Tree);
    delete(&Tree,4);
    printf("\n");
    inorder(Tree);
}
