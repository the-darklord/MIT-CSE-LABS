/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "include.h"

void main()
{
    int sockid,res,len,n=1;
    struct sockaddr_in addr;
    sockid=socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("172.16.59.39");
    addr.sin_port=htons(6996);
    len=sizeof(addr);

    res=connect(sockid,&addr,len);

    if(res==-1)
    {
        perror("\nConnection Error\n");
        exit(1);
    }

    char tt[256];

    int pid;

    n=read(sockid,&pid,sizeof(pid));

    printf("Child Process ID : %d\n",pid);

    printf("Time returned from Server : \n");

    n=read(sockid,tt,sizeof(tt));
    printf("%s\n",tt);
}