#include <stdio.h>

unsigned int gcd(unsigned int m,unsigned int n)
{
	unsigned int t=m>n?n:m;
	int opcount=0;
	while(t>0)
	{
		opcount++;
		if(m%t==0&&n%t==0)
		{
			break;
		}
		t--;
	}
	printf("\nOperation Count = %d\n",opcount);
	return t;
}

void main()
{
	unsigned int m,n;
	printf("Enter the two numbers whose GCD has to be calculated : \n");
	scanf("%d %d",&m,&n);
	printf("GCD of two numbers is %d\n",gcd(m,n));
}