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
        printf("Child Process ID from Child : %d\n",getpid());
        printf("Parent Process ID from Child : %d\n",getppid());
    }
    else
    {
        printf("Child Process ID from Parent : %d\n",pid);
        printf("Parent Process ID from Parent : %d\n",getpid());
    }
}