#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex,wrt;

void* reader(void* arg)
{
    sem_wait(&wrt);
    sleep(1);
    sem_wait(&mutex);
    printf("Read\n");
    sem_post(&mutex);   
    sem_post(&wrt);   
}

void* writer(void* arg)
{
    sem_wait(&mutex);
    sleep(1);
    sem_wait(&wrt);
    printf("Read\n");
    sem_post(&wrt);   
    sem_post(&mutex);       
}

void main()
{
    pthread_t th[2];
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    pthread_create(&th[0],NULL,reader,NULL);
    pthread_create(&th[1],NULL,writer,NULL);
    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);
}