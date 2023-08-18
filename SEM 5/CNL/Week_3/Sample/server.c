/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "../include.h"

void main()
{
    int sockid;
    char buf[256];
    struct sockaddr_in sadd,cadd;

    sockid=socket(AF_INET,SOCK_DGRAM,0);

    sadd.sin_family=AF_INET;
    sadd.sin_port=htons(6996);
    sadd.sin_addr.s_addr=inet_addr("172.16.59.51");

    int result=bind(sockid,&sadd,sizeof(sadd));

    int len=sizeof(cadd);

    int m=recvfrom(sockid,buf,sizeof(buf),0,&cadd,len);

    printf("Server Send is \n%s\n",buf);

    int n=sendto(sockid,buf,sizeof(buf),0,&cadd,len);
}