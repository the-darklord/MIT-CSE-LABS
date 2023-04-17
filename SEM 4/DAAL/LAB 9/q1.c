#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opc=0;

void shiftTable(int* shift,char* str)
{
    int m=strlen(str);
    for(int i=0;i<=26;i++)
    {
        shift[i]=m;
    }
    for(int i=0;i<m-1;i++)
    {
        if(str[i]==' ')
        {
            shift[26]=m-i-1;
        }
        else
        {
            shift[str[i]-65]=m-i-1;
        }
    }
}

int harspool(char* text,char* pattern)
{
    int shift[27];
    shiftTable(shift,pattern);
    int m=strlen(pattern);
    int n=strlen(text);
    int j=0,i;
    while(j+m<=n)
    {
        opc++;
        if(pattern[m-1]==text[j+m-1])
        {
            i=m-2;
            opc++;
            while(i>=0&&pattern[i]==text[j+i])
            {
                opc++;
                i--;
            }
            if(i==-1)
            {
                opc--;
                return j;
            }
        }
        if(text[j+m-1]==' ')
        {
            j=j+shift[26];
        }
        else
        {
            j=j+shift[text[j+m-1]-65];
        }
    }
    return n;
}

void main()
{
    char text[100];
    char pattern[50];
    printf("Enter Text : \n");
    gets(text);
    printf("Enter Pattern : \n");
    gets(pattern);
    if(harspool(text,pattern)==strlen(text))
    {
        printf("Pattern Not Found\n");
    }
    else
    {
        printf("Pattern Found\n");
    }
    printf("No. of Comparisions are %d\n",opc);
}