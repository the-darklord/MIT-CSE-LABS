#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg
{
    long int msg_type;
    char text[MAX_TEXT];
};

void main()
{
    struct my_msg data;
    int msgid;
    char buffer[BUFSIZ];
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("Enter String : \t");
        scanf(" %s",buffer);
        data.msg_type = 1;
        strcpy(data.text, buffer);
        if (msgsnd(msgid, (void *)&data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        if (strncmp(buffer, "end", 3) == 0)
        {
            break;
        }
    }
    exit(EXIT_SUCCESS);
}