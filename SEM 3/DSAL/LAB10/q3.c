#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *Nodeptr;
struct node
{
	char data[100];
	Nodeptr prev,next;
};
Nodeptr getnode()
{
	Nodeptr temp;
	temp=(Nodeptr)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("No Free Space\n");
	}
	return temp;
}
int isEmpty(Nodeptr list)
{
	if(list==NULL)
	{
		return 1;
	}
	return 0;
}
Nodeptr InsF(Nodeptr first,char ele[])
{
	Nodeptr temp;
	temp=getnode();
	strcpy(temp->data,ele);
	temp->prev=NULL;
	if(isEmpty(first))
	{
		temp->next=NULL;
		return temp;
	}
	else
	{
		temp->next=first;
		first->prev=temp;
		first=first->prev;
		return first;
	}
}
Nodeptr InsL(Nodeptr first,char ele[])
{
	Nodeptr temp,rear;
	temp=getnode();
	strcpy(temp->data,ele);
	temp->next=NULL;
	if(isEmpty(first))
	{
		temp->prev=NULL;
		return temp;
	}
	else
	{
		rear=first;
		while(rear->next)
		{
			rear=rear->next;
		}
		temp->prev=rear;
		rear->next=temp;
		return first;
	}
}
void Display(Nodeptr first)
{
	Nodeptr temp=first;
	while(temp)
	{
		printf("%s\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void main()
{
	int n;
	char x[100];
	Nodeptr first=NULL,final=NULL;
	printf("Enter No. of Words : \t");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nEnter Word %d : \n",i+1);
		scanf("%s",x);
		first=InsL(first,x);
	}
	printf("\nInitial List\n");
	Display(first);
	while(first)
	{
		final=InsF(final,first->data);
		first=first->next;
	}
	printf("\nReversed List\n");
	Display(final);
}