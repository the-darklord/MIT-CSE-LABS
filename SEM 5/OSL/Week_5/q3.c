#include "include.h"

#define fname "hi.txt"

void main()
{
    FILE *f1,*f2;
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("Fork Error \n");
        exit(EXIT_FAILURE);
    }
    if(pid>0)
    {
        wait(NULL);
        f2=fopen(fname,"r");
        if(!f2)
        {
            perror("File Error \n");
            exit(EXIT_FAILURE);
        }
        char cc;
        while((cc=fgetc(f2))!=EOF)
        {
            printf("%c",cc);
        }
        printf("\n");
        fclose(f2);
    }
    else
    {
        f1=fopen(fname,"w+");
        if(!f1)
        {
            perror("File Error \n");
            exit(EXIT_FAILURE);
        }
        char c[256];
        printf("Enter Something : \t");
        scanf(" %s",c);
        fputs(c,f1);
        fclose(f1);
    }
    exit(EXIT_SUCCESS);
}