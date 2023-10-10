#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TEXT_SZ 3

struct shared_use_st
{
    int written_by_you;
    char some_text[TEXT_SZ];
};

char getNextChar(char c)
{
    if(c>='A' && c<='Z')
    {
        c = 'A' + (c - 'A' + 1)%26;
    }
    else if(c>='a' && c<='z')
    {
        c = 'a' + (c - 'a' + 1)%26;
    }
}

void main()
{
    int running = 1;
    void *shared_memory = (void *)0;
    struct shared_use_st *shared_stuff;
    int shmid;
    char buffer[BUFSIZ];
    srand((unsigned int)getpid());
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n", (int)shared_memory);
    shared_stuff = (struct shared_use_st *)shared_memory;
    shared_stuff->written_by_you = 0;
    while(1)
    {
        pid_t pid=fork();
        if(pid==0)
        {
            while(1)
            {
                if (shared_stuff->written_by_you)
                {
                    if(strncmp(shared_stuff->some_text, "end", 3) == 0)
                    {
                        shared_stuff->written_by_you = 0;
                        break;
                    }
                    shared_stuff->some_text[0]=getNextChar(shared_stuff->some_text[0]);
                    shared_stuff->written_by_you = 0;
                }
                if (strncmp(shared_stuff->some_text, "end", 3) == 0)
                {
                    break;
                }
            }

        }
        else if(pid>0)
        {
            shared_stuff->written_by_you=0;
            printf("Enter some text :");
            scanf(" %s",buffer);
            strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
            shared_stuff->written_by_you = 1;
            while(shared_stuff->written_by_you == 1)
            {
                sleep(1);
                printf("waiting for child...\n");
            }
            printf("Updated Value : %s\n",shared_stuff->some_text);
        }
        if (strncmp(shared_stuff->some_text, "end", 3) == 0)
        {
            break;
        }
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}