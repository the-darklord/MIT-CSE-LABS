/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>

void removedups(char strings[][256],char ch[],char res[]){
	int i,j=0,k=0,l;
	for(i=0;ch[i]!='\0';i++){
		if(ch[i] == ' '){
			strings[j][k] = '\0';
			j++;
			k=0;
		}
		else{
			strings[j][k] = ch[i];
			k++;
		}
	}
	strings[j][k] = '\0';

	k = 0;
	for(i=0;i<j;i++){
		for(l=1;l<j+1;l++){
			if(strings[i][k] == '\0' || l==i){
				continue;
			}
			if(strcmp(strings[i],strings[l]) == 0){
				strings[l][k] = '\0';
			}
		}
	}

	for(i=0;i<j+1;i++){
		if(strings[i][k] == '\0'){
			continue;
		}
		else{
			strcat(res,strings[i]);
			strcat(res," ");
		}
	}
}

int main(){
	int sockfd,newsockfd,portno,clilen,n=1,i;
	struct sockaddr_in seraddr,cliaddr;

	sockfd = socket(AF_LOCAL,SOCK_STREAM,0);

	seraddr.sin_family = AF_LOCAL;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(4003);

	bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr));


	listen(sockfd,5);

	while(1){
		char buf[256]={""};
		char strings[256][256] = {""};
		char res[256] = {""};
		printf("Server Waiting\n");
		clilen = sizeof(cliaddr);
		newsockfd = accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
		read(newsockfd,buf,sizeof(buf));
		if(strcmp(buf,"Stop") == 0){
			exit(1);
		}
		removedups(strings,buf,res);
		write(newsockfd,res,sizeof(res));
		close(newsockfd);
	}
}
