#include "include.h"

#define FIFO_NAME "/tmp/my_fifo"
#define SENT_SIZE (4*sizeof(int))

void main(int argc,char** argv)
{
    int pipe_fd;
    int res;
    int open_mode=O_WRONLY;
    int bytes_sent=0;
    int buf=0;
    if(access(FIFO_NAME,F_OK)==-1)
    {
        res=mkfifo(FIFO_NAME,0777);
        if(res)
        {
            fprintf(stderr,"Couldn't create FIFO : %s\n",FIFO_NAME);
            exit(EXIT_FAILURE);
        }
    }
    printf("Process %d opening FIFO O_WRONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);
    if(pipe_fd != -1)
    {
        while(bytes_sent < SENT_SIZE)
        {
            res = write(pipe_fd, &buf, sizeof(buf));
            if (res == -1)
            {
                fprintf(stderr, "Write error on pipe\n");
                exit(EXIT_FAILURE);
            }
            buf++;
            bytes_sent += res;
        }
        close(pipe_fd);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    printf("Process %d finished, %d bytes sent\n", getpid(),bytes_sent);
    exit(EXIT_SUCCESS);
}