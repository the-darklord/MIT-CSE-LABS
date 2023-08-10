#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *fa,*fb;
    char ca;
    char fname[256];
    printf("Enter Filename to Read from : \t");
    scanf("%s",fname);
    fa=fopen(fname,"r");
    if(!fa)
    {
        printf("Cannot Open File\n");
        exit(0);
    }
    printf("Enter Filename to Write to : \t");
    scanf("%s",fname);
    fb=fopen(fname,"w+");
    ca=getc(fa);
    while(ca != EOF)
    {
        if(ca == '\"')
        {
            putc(ca,fb);
            ca=getc(fa);
            while(ca != '\"')
            {
                putc(ca,fb);
                ca=getc(fa);
            }
        }
        if(ca == ' ')
        {
            putc(ca,fb);
            while(ca==' ')
            {
                ca = getc(fa);
            }
        }
        else if(ca == '\t')
        {
            putc(' ',fb);
            while(ca == '\t')
            {
                ca = getc(fa);
            }
        }
        else if(ca == '#')
        {
            while(ca != '\n')
            {
                ca=getc(fa);
            }
            ca=getc(fa);
        }
        else
        {
            putc(ca,fb);
            ca=getc(fa);
        }
    }
    fclose(fa);
    fclose(fb);
}