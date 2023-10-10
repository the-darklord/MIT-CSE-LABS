//Incomplete




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
    int mat[9];
};

void showMat(int* mat)
{
    printf("\n");
    for(int i=0;i<9;i++)
    {
        if(mat[i]==0)
            printf("__");
        if(mat[i]==-1)
            printf("X");
        if(mat[i]==1)
            printf("O");
        if(i%3==2)
            printf("\n\n");
    }
    printf("\n");
}

int analyzeMat(int* mat)
{
    int wins[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int x;
    for(int i=0;i<8;i++)
    {
        x=0;
        for(int j=0;j<3;j++)
        {
            x+=mat[wins[i][j]];
        }
        x=x/3;
        if(x==1 || x==-1)
        {
            return x;
        }
    }
    return 0;
}

int* initMat()
{
    int mat[9];
    for(int i=0;i<9;i++)
    {
        mat[i]=0;
    }
    return mat;
}

int zeroCount(int* mat)
{
    int count=0;
    for(int i=0;i<9;i++)
    {
        if(mat[i]==0)
        {
            count++;
        }
    }
    return count;
}

void main()
{
    int running = 1;
    void *shared_memory = (void *)0;
    struct shared_use_st shared_stuff={.mat=initMat()};
    int shmid;
    char buffer[BUFSIZ];
    srand((unsigned int)getpid());
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }
    printf("fd\n");
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n", (int)shared_memory);
    shared_stuff = *(struct shared_use_st *)shared_memory;
    shared_stuff.written_by_you = 1;
    while(1)
    {
        while(shared_stuff.written_by_you == 1)
        {
            sleep(1);
            printf("waiting for Player 1...\n");
        }
        printf("%d\n",shared_stuff.written_by_you);
        showMat(shared_stuff.mat);
        if(analyzeMat(shared_stuff.mat)!=0 && zeroCount(shared_stuff.mat)==0)
        {
            break;
        }
        printf("Enter Position(1 - 9) : \t");
        int pos;
        scanf("%d",&pos);
        while(shared_stuff.mat[pos-1]!=0)
        {
            printf("\nERROR !!! Can't Insert Here\n");
            printf("Enter Position(1 - 9) : \t");
            scanf("%d",&pos);
        }
        shared_stuff.mat[pos-1]=-1;
        shared_stuff.written_by_you = 1;
    }
    int x=analyzeMat(shared_stuff.mat);
    if(x==0)
        printf("\n\nDraw Match !!!!\n\n");
    if(x==-1)
        printf("\n\nPlayer X wins !!!!\n\n");
    if(x==1)
        printf("\n\nPlayer O wins !!!!\n\n");
    printf("\n\nGAME OVER SUCKER !!!\n\n");
    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}