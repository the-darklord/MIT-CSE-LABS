#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg
{
    long int msg_type;
    char text[BUFSIZ];
};

int isPal(char num[])
{
    int i=0;
    int n=strlen(num);
    while(num[i]!='\0')
    {
        if(num[i]!=num[n-i-1])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void main()
{
    int msgid;
    struct my_msg data;
    long int msg_to_receive = 0;
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        memset(&data,0,sizeof(struct my_msg));
        if (msgrcv(msgid,(void *)&data, BUFSIZ,msg_to_receive, 0) == -1)
        {
            fprintf(stderr, "msgrcv failed with error: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        if (strncmp(data.text, "end", 3) == 0)
        {
            break;
        }
        if(isPal(data.text))
        {
            printf("%s is a Palindrome\n",data.text);
        }
        else
        {
            printf("%s is not a Palindrome\n",data.text);
        }
    }
    if (msgctl(msgid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}