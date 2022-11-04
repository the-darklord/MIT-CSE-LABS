#include <stdio.h>
#include "mihir.h"
int main()
{
int n,a[100],choice=0,tos=-1,ele;
int *ptos=&tos;
printf("Enter array size : \t");
scanf("%d",&n);
while(choice=0|choice!=4)
{
printf("Enter your choice \n");
printf("1.) Push\n2.) Pop\n3.) Display\n4.) Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter Element to push : \t");
scanf("%d",&ele);
push(a,n,ele,ptos);
break;
case 2:
printf("Popped Element is : %d",pop(a,ptos));
break;
case 3:
display(a,ptos);
break;
case 4:
printf("Invalid Case\n");
break;
}
}
}
