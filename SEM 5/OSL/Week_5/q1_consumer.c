#include "include.h"

#define FIFO_NAME "/tmp/my_fifo"
#define SENT_SIZE (4*sizeof(int))

void main(int argc,char** argv)
{
    int pipe_fd;
    int res;
    int open_mode=O_RDONLY;
    int bytes_read=0;
    int buf;
    printf("Process %d opening FIFO O_RDONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);
    if(pipe_fd != -1)
    {
        do
        {
            res = read(pipe_fd, &buf, sizeof(buf));
            printf("%d\n",buf);
            bytes_read += res;
        }while(bytes_read < SENT_SIZE);
        close(pipe_fd);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    printf("Process %d finished, %d bytes read\n", getpid(),bytes_read);
    exit(EXIT_SUCCESS);
}