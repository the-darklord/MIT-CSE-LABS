/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "include.h"
#include <time.h>

void main()
{
    int sockid,newsockid,portno,clilen,n=1;
    int size;
    struct sockaddr_in server_addr,client_addr;
    sockid=socket(AF_INET,SOCK_STREAM,0);
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr("172.16.59.39");
    server_addr.sin_port=htons(6996);
    bind(sockid,&server_addr,sizeof(server_addr));

    listen(sockid,5);

    while(1)
    {
        clilen=sizeof(clilen);
        newsockid=accept(sockid,&client_addr,&clilen);

        if(fork()==0)
        {
            printf("Created New Child with ID : %d\n",getpid());
            time_t t;
            time(&t);
            char tt[256];
            strcpy(tt,ctime(&t));
            int pid=getpid();
            n=write(newsockid,&pid,sizeof(pid));
            n=write(newsockid,tt,sizeof(tt));
            close(newsockid);
            exit(0);
        }
        else
        {
            close(newsockid);
        }
    }
}