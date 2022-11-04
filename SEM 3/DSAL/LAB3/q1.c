#include <stdio.h>
#include <stdlib.h>

struct Complex
{
	int re;
	int im;
};
void set(struct Complex *ptr,int a,int b)
{
	ptr->re=a;
	ptr->im=b;
}
void display(struct Complex *ptr)
{
	char c='+';
	int t=abs(ptr->im);
	if(ptr->im < 0)
	{
		c='-';
	}
	printf("%d%c%di\n",ptr->re,c,t);

}
void add(struct Complex *add,struct Complex *h1,struct Complex *h2)
{
	add->re = h1->re + h2->re;
	add->im = h1->im + h2->im;
}
void sub(struct Complex *sub,struct Complex *h1,struct Complex *h2)
{
	sub->re = h1->re - h2->re;
	sub->im = h1->im - h2->im;
}
void mult(struct Complex *mult,struct Complex *h1,struct Complex *h2)
{
	mult->re=(h1->re*h2->re)-(h1->im*h2->im);
	mult->im=(h1->re*h2->im)+(h2->re*h1->im);
}
void main()
{
	struct Complex c1,c2,sum,diff,product;
	int m,n,p,q;
	printf("Enter real and imaginary parts of C1 : \t");
	scanf("%d %d",&m,&n);
	struct Complex *p1=&c1,*p2=&c2,*sum1=&sum,*diff1=&diff,*product1=&product;
	set(p1,m,n);
	printf("Enter real and imaginary parts of C2 : \t");
	scanf("%d %d",&p,&q);
	set(p2,p,q);
	display(p1);
	display(p2);
	add(sum1,p1,p2);
	printf("Sum is ");
	display(sum1);
	sub(diff1,p1,p2);
	printf("Difference is ");
	display(diff1);
	mult(product1,p1,p2);
	printf("Product is ");
	display(product1);
}