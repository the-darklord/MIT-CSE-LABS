#include "include.h"

void main()
{
    int status;
    pid_t pid;
    pid=fork();
    if(pid==-1)
    {
        printf("Error !!!\n");
    }
    else if(pid==0)
    {
        printf("Child Process \n");
        exit(0);
    }
    else
    {
        wait(&status);
        printf("Parent Process \n");
        printf("Child Process Returned : %d\n",status);
    }
}