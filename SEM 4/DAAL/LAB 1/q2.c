#include <stdio.h>
#include <stdlib.h>

typedef struct node* Nodeptr;
struct node
{
	int data;
	Nodeptr next;
};

Nodeptr getnode()
{
	return (Nodeptr)malloc(sizeof(struct node));
}

Nodeptr insert(Nodeptr first,int item)
{
    Nodeptr temp,rear;
    temp=getnode();
    temp->data = item;
    temp->next = NULL;
    rear=first;
    if(!first)
    {
        first = temp;
    }
    else
    {
        while(rear->next)
        {
            rear=rear->next;
        }
        rear->next=temp;
    }
    return first;
}

void Display(Nodeptr list)
{
	while(list->next)
	{
		printf("%d -> ",list->data);
		list=list->next;
	}
	printf("%d\n",list->data);
}

void main()
{
	int v;
	printf("Enter Number of Vertices : \t");
	scanf("%d",&v);
	int adj[v][v];
	Nodeptr ll[v];
	for(int i=0;i<v;i++)
	{
		ll[i]=NULL;
		ll[i]=insert(ll[i],i+1);
		for(int j=0;j<v;j++)
		{
			if(i==j)
			{
				adj[i][j]=0;
			}
			else
			{
				printf("\nAre Vertices %d and %d are Adjacent?",(i+1),(j+1));
				printf("\nEnter 1 for Yes , 0 for No : \t");
				scanf("%d",&adj[i][j]);
			}
			if(adj[i][j])
			{
				ll[i]=insert(ll[i],j+1);
			}
		}
	}
	printf("\nAdjacency Matrix is \n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	printf("\nAdjacency List is \n");
	for(int i=0;i<v;i++)
	{
		Display(ll[i]);
	}
}