#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex,wrt;
int readCount=0;

void* reader(void* arg)
{
    do
    {
        sem_wait(&mutex);
        readCount++;
        if(readCount==1)
        {
            sem_wait(&wrt);
        }
        sem_post(&mutex);
        printf("Reading %d.....\n",readCount);
        sleep(1);
        sem_wait(&mutex);
        readCount--;
        if(readCount==0)
        {
            sem_post(&wrt);
        }
        sem_post(&mutex);
        sleep(2);
    } while (1);
    
}

void* writer(void* arg)
{
    do
    {
        sem_wait(&wrt);
        printf("Writing %d.....\n",readCount);
        sem_post(&wrt);
        sleep(4);
    } while (1);
    
}

void main()
{
    pthread_t th[3];
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    pthread_create(&th[0],NULL,reader,NULL);
    pthread_create(&th[1],NULL,reader,NULL);
    pthread_create(&th[2],NULL,writer,NULL);
    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);
    pthread_join(th[2],NULL);
}