#include "include.h"

void main()
{
    pid_t pid;
    pid=fork();
    if(pid==-1)
    {
        printf("Error !!!\n");
    }
    else if(pid==0)
    {
        exit(0);
    }
    else
    {
        sleep(100);
        printf("Program 2 Parent Process \n");
    }
}