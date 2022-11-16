#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
struct node
{
	int data;
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
Nodeptr InsF(Nodeptr first,int ele)
{
	Nodeptr temp;
	temp=getnode();
	temp->data=ele;
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
Nodeptr InsL(Nodeptr first,int ele)
{
	Nodeptr temp,rear;
	temp=getnode();
	temp->data=ele;
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
int DelF(Nodeptr* first)
{
	Nodeptr temp;
	if(isEmpty(*first))
	{
		printf("List is Empty \n");
		exit(1);
	}
	else
	{
		int x;
		temp=*first;
		*first=(*first)->next;
		x=temp->data;
		(*first)->prev=NULL;
		temp->next=NULL;
		free(temp);
		return x;
	}
}
int DelL(Nodeptr* first)
{
	Nodeptr temp;
	if(isEmpty(*first))
	{
		printf("List is Empty \n");
		exit(1);
	}
	else
	{
		int x;
		temp=*first;
		while(temp->next)
		{
			temp=temp->next;
		}
		x=temp->data;
		temp->prev->next=NULL;
		temp->prev=NULL;
		free(temp);
		return x;
	}
}
void Display(Nodeptr first)
{
	Nodeptr temp=first;
	while(temp)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void main()
{
	Nodeptr first=NULL;
	int x,choice=1;
	do
	{
		printf("1)Insert Front\t2)Insert Last\n3)Delete Front\t4)Delete Last\n5)Display\tAny)Exit");
		printf("\nEnter Choice : \t");
		scanf("%d",&choice);
		if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5)
		{
			choice=6;
		}
		else
		{
			switch(choice)
			{
				case 1:
				{
					printf("\nEnter Element to Insert : \t");
					scanf("%d",&x);
					first=InsF(first,x);
					break;
				}
				case 2:
				{
					printf("\nEnter Element to Insert : \t");
					scanf("%d",&x);
					first=InsL(first,x);
					break;
				}
				case 3:
				{
					printf("\nDeleted Element : %d\n",DelF(&first));
					break;
				}
				case 4:
				{
					printf("\nDeleted Element : %d\n",DelL(&first));
					break;
				}
				case 5:
				{
					Display(first);
					break;
				}
			}
		}
	}while(choice!=6);
}