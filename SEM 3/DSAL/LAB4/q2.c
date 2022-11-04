#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void cpy(char st[100],char *ptr)
{
    static int i=0;
    while(st[i]!='\0')
    {
        ptr[i] = st[i];
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
    printf("Copied string: ");
    puts(p);
    printf("\n");
    free(p);
}