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

    Expr e1;

    int result;

    printf("Enter First Element : \t");
    scanf("%d",&e1.a);
    
    printf("Enter Second Element : \t");
    scanf("%d",&e1.b);

    printf("Enter Operator : \t");
    scanf(" %c",&e1.c);
    
    write(sockid,&e1,sizeof(e1));

    printf("Answer returned from Server : \n");

    n=read(sockid,&result,sizeof(result));

    printf("%d\n",result);
}