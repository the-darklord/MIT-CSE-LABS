#include <stdio.h>
#include <stdlib.h>

typedef struct node * Nodeptr;
struct node
{
	int data;
	Nodeptr lc,rc;
};

Nodeptr getnode()
{
	return (Nodeptr)malloc(sizeof(struct node));
}

int Search(Nodeptr root,int key)
{
	if(!root)
	{
		return 0;
	}
	if(root->data == key)
	{
		return 1;
	}
	else if(root->data > key)
	{
		return Search(root->lc,key);
	}
	else
	{
		return Search(root->rc,key);
	}
}

Nodeptr insert(Nodeptr root,int data)
{
	if(!root)
	{
		root=getnode();
		root->data=data;
		root->lc=root->rc=NULL;
		return root;
	}
	if(root->data==data)
	{
		printf("\nDuplicates not allowed\n");
		exit(1);
	}
	else if(root->data > data)
	{
		root->lc=insert(root->lc,data);
	}
	else
	{
		root->rc=insert(root->rc,data);
	}
	return root;
}

Nodeptr create_BST()
{
	int x;
	Nodeptr root = NULL;
	printf("Enter root data : \t");
	scanf("%d",&x);
	root=insert(root,x);
	while(1)
	{
		printf("Enter data to insert (-1 to stop) : \t");
		scanf("%d",&x);
		if(x==-1){break;}
		if(Search(root,x))
		{
			printf("\nFound %d\n",x);
		}
		else
		{
			root=insert(root,x);			
		}
	}
	return root;
}

void inorder(Nodeptr root)
{
	if(root)
	{
		inorder(root->lc);
		printf("%d\t",root->data);
		inorder(root->rc);
	}
}

void preorder(Nodeptr root)
{
	if(root)
	{
		printf("%d\t",root->data);
		preorder(root->lc);
		preorder(root->rc);
	}
}

void postorder(Nodeptr root)
{
	if(root)
	{
		postorder(root->lc);
		postorder(root->rc);
		printf("%d\t",root->data);
	}
}

void main()
{
	Nodeptr root=create_BST();
	printf("\nInorder is \n");
	inorder(root);
	printf("\nPreorder is \n");
	preorder(root);
	printf("\nPostorder is \n");
	postorder(root);
	printf("\n");
}