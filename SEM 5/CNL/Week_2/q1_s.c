/*
This code is written by
    NAYAKANTI SAI MIHIRNATH
    Reg. Num. : 210905368
    Roll No.  : 57
*/

#include "include.h"

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
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

    while(1)
    {
        clilen=sizeof(clilen);
        newsockid=accept(sockid,&client_addr,&clilen);

        if(fork()==0)
        {
            printf("Created New Child with ID : %d\n",getpid());
            
            n=read(newsockid,&size,sizeof(size));
            int buf[size];
            n=read(newsockid,buf,sizeof(buf));
            sort(buf,size);
            n=write(newsockid,buf,sizeof(buf));
            int pid=getpid();
            n=write(newsockid,&pid,sizeof(pid));
            close(newsockid);
            exit(0);
        }
        else
        {
            close(newsockid);
        }
    }
}