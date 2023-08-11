#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>

#define PORTNO 10200
int main()
{
int sockfd,newsockfd,portno,clilen,n=1;
char buf[256];
struct sockaddr_in seraddr,cliaddr;
int i,value;
sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
seraddr.sin_family = AF_LOCAL;
seraddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //**
seraddr.sin_port = htons(PORTNO);
bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
// Create a connection queue, ignore child exit details, and wait for clients
listen(sockfd,5);
while(1){
//Accept the connection
clilen = sizeof(clilen);
newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
if(fork()==0){
// If you’re the child, you can now read/write to the client on newsockfd.
n = read(newsockfd,buf,sizeof(buf));
printf(" \nMessage from Client %s \n",buf);
n = write(newsockfd,buf,sizeof(buf));
close(newsockfd);
exit(0);
}
//Otherwise, you must be the parent and your work for this client is finished
else
close(newsockfd);
}
}
