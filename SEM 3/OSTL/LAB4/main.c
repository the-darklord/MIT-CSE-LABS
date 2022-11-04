#include "maths1.h"
#include<stdio.h>

int main()
{
	int a,b;
	printf("enter 2 variables : \t");
	scanf("%d %d",&a,&b);
	int z=add(a,b);
	int c=sub(a,b);
	printf("Sum is %d , Difference is %d \n",z,c);
	return 0;
}
