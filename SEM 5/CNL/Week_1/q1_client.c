/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "include.h"

void main()
{
    int len,result,sock_id,n=1;
    struct sockaddr_in address;
    char ch[256],buf[256];

    sock_id = socket(AF_INET,SOCK_STREAM,0);

    address.sin_family=AF_INET;
    address.sin_port=htons(6996);
    address.sin_addr.s_addr=inet_addr("172.16.59.56");
    len=sizeof(address);

    result=connect(sock_id,&address,len);

    if(result==-1)
    {
        perror("\nClient Error !!!!\n");
        exit(1);
    }

    printf("\nEnter String : \t");
    gets(ch);
    ch[strlen(ch)]='\0';

    for(int i=0;i<strlen(ch);i++)
    {
        ch[i] += 4;
    }

    write(sock_id,ch,strlen(ch));

    puts(buf);
}