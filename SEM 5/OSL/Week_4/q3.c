#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(int argc,char* argv[100])
{
    if(argc!=3)
    {
        printf("ERROR Insufficient Arguments\n");
        return;
    }
    struct stat sbuf;
    int ret=stat(argv[1],&sbuf);
    if(ret==-1)
    {
        perror("ERROR !!!\n");
        return;
    }
    int flag=link(argv[1],argv[2]);
    if(flag==-1)
    {
        perror("Link Error!!!\n");
        return;
    }
    printf("Successfully Linked %s to %s\n",argv[1],argv[2]);
    flag=unlink(argv[2]);
    if(flag==-1)
    {
        perror("Unlink Error!!!\n");
        return;
    }
    printf("Successfully Unlinked %s to %s\n",argv[1],argv[2]);
}