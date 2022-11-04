#include<stdio.h>
#include "eval_postfix_fun.h"
int main()
{
stack s;
char x;
int op1,op2,val;
init(&s);
printf("Enter the expression(eg: 59+3*)\n single digit operand and operators only:");
while((x=getchar())!='\n')
{
    if(isdigit(x))
    push(&s,x-'0');
else
{
op2=pop(&s);
op1=pop(&s);
val=evaluate(x,op1,op2);
push(&s,val);
}
}
val=pop(&s);
printf("\nvalue of expression=%d",val);
return 0;
}