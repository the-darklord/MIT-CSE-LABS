/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

int main(){
	while(1){
	int len,result,sockfd,i,n=1;
	struct sockaddr_in address;
	char ch[256],buf[256];

	sockfd = socket(AF_LOCAL,SOCK_STREAM,0);

	address.sin_family=AF_LOCAL;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=htons(4003);
	len = sizeof(address);

	result = connect(sockfd,(struct sockaddr *)&address,len);
	if(result == -1){
		printf("\nCLIENT ERROR");
		exit(1);
	}

	printf("\nEnter the string: ");
	gets(ch);
	ch[strlen(ch)] = '\0';
	if(strcmp(ch,"Stop") == 0){
		close(sockfd);
		break;
	}
	write(sockfd,ch,strlen(ch));
	read(sockfd,buf,sizeof(buf));
	printf("\nString after removing duplicates: ");
	puts(buf);
	close(sockfd);
}
}
