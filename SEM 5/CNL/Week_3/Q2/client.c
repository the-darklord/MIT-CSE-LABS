/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "../include.h"

#define PORTNO 8003

int main()
{
	int sd;
	struct sockaddr_in address;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("172.16.59.51");
	address.sin_port=htons(PORTNO);
	char buf[256];
	int len=sizeof(address);
	//'GET /index.html HTTP/1.1\r\nHost:stackoverflow.com\r\n\r\n'
	printf("Enter the request: ");
	scanf("%[^\n]",buf);
	sendto(sd,buf,sizeof(buf),0,(struct sockaddr *)&address, len);

	return 0;
}