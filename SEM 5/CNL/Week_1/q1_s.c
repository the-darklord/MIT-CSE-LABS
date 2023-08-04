#include "include.h"

#define PORTNO 6996

void main()
{
    int sock_id,new_sockid,portno,client_len,n=1;
    struct sockaddr_in server_addr,client_addr;
    int i,value;
    
    sock_id = socket(AF_INET,SOCK_STREAM,0);

    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr("172.16.59.56");
    server_addr.sin_port=htons(PORTNO);

    bind(sock_id,&server_addr,sizeof(server_addr));

    listen(sock_id,5);

    while(1)
    {
        char buf[256]={""};
        printf("\nServer Waiting ...\n");

        client_len=sizeof(client_len);

        new_sockid=accept(sock_id,&client_addr,&client_len);

        n=read(new_sockid,buf,sizeof(buf));

        printf("Encrypted Message from Client : %s \n",buf);

        for(int i=0;i<strlen(buf);i++)
        {
            buf[i] -= 4;
        }

        printf("Decrypted Message from Client : %s \n",buf);
    } 
}