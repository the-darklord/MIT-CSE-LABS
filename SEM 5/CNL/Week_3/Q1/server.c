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
	int m,n;
	struct sockaddr_in sadd,cadd;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	sadd.sin_family=AF_INET;
	sadd.sin_addr.s_addr=inet_addr("172.16.59.51");
	sadd.sin_port=htons(PORTNO);
	int result=bind(sd,(struct sockaddr *)&sadd,sizeof(sadd));
	int len=sizeof(cadd);
	recvfrom(sd,&m,sizeof(m),0,(struct sockaddr *)&cadd,&len);
	recvfrom(sd,&n,sizeof(n),0,(struct sockaddr *)&cadd,&len);

	int arr[m][n];
	int recvarr[n];
	int rowCount = 0;
	while(rowCount < m){
		recvfrom(sd,recvarr,n*sizeof(int),0,(struct sockaddr *)&cadd,&len);
		for(int i=0;i<n;i++){
			arr[rowCount][i] = recvarr[i];
		}
		rowCount++;
	}
	printf("After combining the matrix is: \n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}