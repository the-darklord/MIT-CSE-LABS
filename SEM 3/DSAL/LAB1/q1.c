#include <stdio.h>

double Add(double a[],int n)
{
	int i;
	double sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	return sum;
}

int main()
{
	int i,n;
	double a[100],sum;


	printf("Enter Number of Elements : \t");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : \t",i+1);
		scanf("%lf",&a[i]);
	}
	sum=Add(a,n);
	printf("Sum is %lf",sum);
	return 0;
}