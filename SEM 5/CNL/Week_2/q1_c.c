/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "include.h"

void main()
{
    int sockid,res,len,n=1,size;
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

    printf("Enter Size of Array : \t");
    scanf("%d",&size);
    int buf[size];
    printf("\nEnter Array Elements : \n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&buf[i]);
    }

    write(sockid,&size,sizeof(size));
    
    write(sockid,buf,size*sizeof(int));

    printf("Parent Process ID : %d\n",getppid());

    printf("Child Process ID : %d\n",getpid());

    printf("Sorted Array returned from Server : \n");

    n=read(sockid,buf,sizeof(buf));

    for(int i=0;i<size;i++)
    {
        printf("%d ",buf[i]);
    }
}