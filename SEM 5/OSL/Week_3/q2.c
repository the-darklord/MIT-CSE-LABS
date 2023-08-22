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
        execl("./q1","./q1",NULL);
        printf("Program 2 Child Process \n");
    }
    else
    {
        wait(NULL);
        printf("Program 2 Parent Process \n");
    }
}