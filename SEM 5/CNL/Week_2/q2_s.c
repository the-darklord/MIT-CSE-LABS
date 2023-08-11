/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "include.h"

typedef struct expression
{
    int a,b;
    char c;
}Expr;

int validate(Expr e)
{
    switch(e.c)
    {
        case '+':
        {
            return e.a + e.b;
        }
        case '-':
        {
            return e.a - e.b;
        }
        case '*':
        {
            return e.a * e.b;
        }
        case '/':
        {
            return e.a / e.b;
        }
    }
}

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

    Expr e1;

    while(1)
    {
        clilen=sizeof(clilen);
        newsockid=accept(sockid,&client_addr,&clilen);

        if(fork()==0)
        {
            n=read(newsockid,&e1,sizeof(e1));
            int res=validate(e1);
            printf("%d %c %d = %d\n",e1.a,e1.c,e1.b,res);
            n=write(newsockid,&res,sizeof(res));
            close(newsockid);
            exit(0);
        }
        else
        {
            close(newsockid);
        }
    }
}