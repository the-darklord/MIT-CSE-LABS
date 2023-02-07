#include<stdio.h>

int isprime(int x,int *op)
{
	int c = 0, i;
	for(i = 2; i < x; i++)
	{
		(*op)++;
		if(x % i == 0)
			return 0;
	}
		return 1;
}

int gcdm(int m, int n)
{
	int gcd = 1,i = 2, opc = 0;
	int t=m<n?m:n;
	while(i<t)
	{
		opc++;
		if(isprime(i,&opc))
		{
			if(m%i == 0 && n % i == 0)
			{
				gcd = gcd * i;
				m = m/i;
				n = n/i;
			}
			else
				i++;
		}
		else
			i++;
	}
	printf("Operation Count = %d\n",opc);
	return gcd;
}

void main()
{
	int m,n;
	printf("Enter the two numbers whose GCD has to be calculated : \n");
	scanf("%d %d",&m,&n);
	printf("GCD is %d\n", gcdm(m,n));
}