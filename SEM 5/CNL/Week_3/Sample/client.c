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
    struct sockaddr_in addr;

    sockid=socket(AF_INET,SOCK_DGRAM,0);

    addr.sin_family=AF_INET;
    addr.sin_port=htons(6996);
    addr.sin_addr.s_addr=inet_addr("172.16.59.51");

    printf("Enter String : \n");
    scanf("%s",buf);

    int len=sizeof(addr);

    int m=sendto(sockid,buf,sizeof(buf),0,&addr,len);

    int n=recvfrom(sockid,buf,sizeof(buf),0,&addr,len);

    printf("Server Echo is \n%s\n",buf);
}