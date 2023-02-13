#include <stdio.h>
#include <string.h>

void main()
{
    char text[30];
    char pattern[30];
    printf("Enter Text : \n");
    scanf("%s",text);
    printf("Enter Pattern for matching : \n");
    scanf("%s",pattern);
    printf("Text : %s\nPattern : %s\n",text,pattern);
    int t=strlen(text);
    int p=strlen(pattern);
    int opcount=0,counter=0,flag=0;
    for(int i=0;i<=t-p;i++)
    {
        counter=0;
        for(int j=0;j<p;j++)
        {
            opcount++;
            if(text[i+j]==pattern[j])
            {
                counter++;
            }
        }
        if(counter==p)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        printf("\nPattern Found\n");
    }
    else
    {
        printf("\nPattern Not Found\n");
    }
    printf("\nOperation Count = %d\n",opcount);
}