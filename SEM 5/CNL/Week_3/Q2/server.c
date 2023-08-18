/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "../include.h"

#define PORTNO 8003

int main(){
	int sd;
	char buf[256];
	struct sockaddr_in sadd,cadd;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	sadd.sin_family=AF_INET;
	sadd.sin_addr.s_addr=inet_addr("172.16.59.51");
	sadd.sin_port=htons(PORTNO);
	int result=bind(sd,(struct sockaddr *)&sadd,sizeof(sadd));
	int len=sizeof(cadd);
	char command[512]; 
	recvfrom(sd,buf,sizeof(buf),0,(struct sockaddr *)&cadd,&len);
	sprintf(command,"echo -en %s | nc stackoverflow.com 80 > x.html",buf);
	system(command);
	return 0;
}	