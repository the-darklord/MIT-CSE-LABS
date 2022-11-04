#include<stdio.h>
int main()
{
int num;
do
{
printf("Enter a positive integer");
scanf("%d",&num);
}
while(num<0);
int factorial, i;
for (i = 1; i<=num; i++)
{
factorial = factorial *i;
}
printf("%d! = %d\n", num, factorial);
return 0;
}
