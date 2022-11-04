#include <stdio.h>

int Lsearch(int a[],int n,int ele)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==ele)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int a[100],n,i,loc,ele;
	printf("Enter Number of Elements : \t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : \t",i+1);
		scanf("%d",&a[i]);
	}
	printf("Enter element to search : \t");
	scanf("%d",&ele);
	loc=Lsearch(a,n,ele);
	if(loc==-1)
	{
		printf("Element not found");
	}
	else
	{
		printf("Element found at %d position",loc+1);
	}
	return 0;
}
