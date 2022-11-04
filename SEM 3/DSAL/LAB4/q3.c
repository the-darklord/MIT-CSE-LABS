#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void cpy(char st[100],char *ptr)
{
    static int i=0;
    int n=strlen(st);
    while(st[i]!='\0')
    {
        ptr[i] = st[n-i-1];
        i++;
        return cpy(st,ptr);
    }
}
void main()
{
    char str[100];
    printf("Enter a String : \n");
    gets(str);
    int n = strlen(str);
    char *p  = (char *) malloc((n+1)*sizeof(char));
    cpy(str,p);
    if(strcmp(str,p)==0)
    {
        printf("Palindrome String");
    }
    else
    {
        printf("Not a Palindrome");
    }
    printf("\n");
    free(p);
}