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
	Nodeptr temp,front;
	front=first->next;
	temp=getnode();
	temp->data=ele;
	if(isEmpty(first->next))
	{
		temp->prev=first;
		first->next=temp;
		temp->next=first;
		first->prev=temp;
	}
	else
	{
		first->next=temp;
		temp->prev=first;
		temp->next=front;
		front->prev=temp;
	}
	return first;
}
void Display(Nodeptr first)
{
	Nodeptr temp=first;
	temp=temp->next;
	while(temp!=first)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
Nodeptr InsLong(Nodeptr first,long int n)
{
	int x;
	while(n!=0)
	{
		x=n%10;
		first=InsF(first,x);
		n=n/10;
	}
	return first;
}
int len(Nodeptr first)
{
	Nodeptr temp=first;
	if(isEmpty(first))
	{
		return 0;
	}
	else
	{
		int count=0;
		while(temp->next!=first)
		{
			count++;
			temp=temp->next;
		}
		return count;
	}
}
void main()
{
	long int n1,n2;
	printf("Enter Two Numbers : \n");
	scanf("%ld %ld",&n1,&n2);
	Nodeptr f1,f2,l1,l2,l;
	f1=getnode();
	f2=getnode();
	f1->data=-1;
	f2->data=-1;
	f1->prev=NULL;
	f1->next=NULL;
	f2->prev=NULL;
	f2->next=NULL;
	l->prev=NULL;
	l->next=NULL;
	f1=InsLong(f1,n1);
	f2=InsLong(f2,n2);
	printf("\nNum 1 \n");
	Display(f1);
	printf("\nNum 2 \n");
	Display(f2);
	int c1,c2,k,c,cc;
	c1=len(f1);
	c2=len(f2);
	k=c1>c2?(c1-c2):(c2-c1);
	if(c1>c2)
	{
		while(k!=0)
		{
			f2=InsF(f2,0);
			k--;
		}
	}
	else if(c1<c2)
	{
		while(k!=0)
		{
			f1=InsF(f1,0);
			k--;
		}
	}
	l1=f1->prev;
	l2=f2->prev;
	cc=0;
	while(l1!=f1||l2!=f2)
	{
		c=l1->data+l2->data+cc;
		k=c%10;
		cc=c/10;
		l=InsF(l,k);
		l1=l1->prev;
		l2=l2->prev;
	}
	if(cc!=0)
	{
		l=InsF(l,cc);
	}
	printf("\nSum \n");
	Display(l);
}