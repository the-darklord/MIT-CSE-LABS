#include <stdio.h>
#include <string.h>
#include "mihir.c"
void checkpalindrome(char str[],STACK *ps1)
{
    int n = strlen(str),i=0;
    char x[MAX];
    while(n!=0)
    {
        push(str[i],ps1);
        i++;
        n--;
    }
    i=0;
    while(ps1->tos!=-1)
    {
        x[i]=pop(ps1);
        i++;
    }
    if(strcmp(str,x)==0)
    {
        printf("String is a Palindrome \n");
    }
    else
    {
        printf("String is not a Palindrome \n");
    }
}
void main()
{
    STACK s1,*ps1=&s1;
    ps1->tos=-1;
    char str[MAX];
    printf("Enter a String : \n");
    scanf("%s",str);
    checkpalindrome(str,ps1);
}