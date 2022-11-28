#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
struct node 
{
    int data;
    Nodeptr lchild,rchild;
};

Nodeptr getnode()
{
    return (Nodeptr)malloc(sizeof(struct node));
}

void insert(Nodeptr* root,int val){
    Nodeptr head = *root;
    Nodeptr temp = getnode();
    Nodeptr parent = NULL;

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

void create_iter_BT(Nodeptr* root){
    int x,option;
    Nodeptr temp,prev = NULL;
    if(!(*root)){
        temp = getnode();
        printf("Enter the value of root: ");
        scanf("%d",&x);
        temp->data = x;
        temp->rchild = temp->lchild = NULL;
        *root = temp;
        prev = *root;
    }
    Nodeptr curr = *root;
    printf("1.Go Left\n2.Go Right\n3.Go back\n4.Go to root\n5.Exit\nEnter option: ");
    scanf("%d",&option);
    while(option != 5){
        if(option == 1){
            prev = curr;
            temp = getnode();
            printf("Enter the value of left child:");
            scanf("%d",&x);
            temp->data = x;
            temp->rchild = temp->lchild = NULL;
            curr->lchild = temp;
            curr = curr->lchild;
        }
        else if(option == 2){
            prev = curr;
            temp = getnode();
            printf("Enter the value of right child:");
            scanf("%d",&x);
            temp->data = x;
            temp->rchild = temp->lchild = NULL;
            curr->rchild = temp;
            curr = curr->rchild;
        }
        else if(option == 3){
            curr = prev;
        }
        else if(option == 4){
            curr = *root;
        }
        else{
            return;
        }
        printf("Enter option: ");
        scanf("%d",&option);
    }
}

void inorder(Nodeptr root){
    if(root){
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}

void preorder(Nodeptr root){
    if(root){
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(Nodeptr root){
    if(root){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}