#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int buf[10],f,r;
sem_t mutex,full,empty,atmost10;
int produced,consumed;

void* produce(void* arg)
{
    while(1)
    {
        sem_wait(&atmost10);
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("Produced Item : %d\n",produced);
        buf[(++r)%10]=produced;
        produced++;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
        if(produced-consumed<=10)
        {
            sem_post(&atmost10);
        }
    }
}

void* consume(void* arg)
{
    int item;
    while(1)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        item=buf[(++f)%10];
        consumed++;
        printf("Consumed Item : %d\n",item);
        sem_post(&mutex);
        sem_post(&empty);
        if(produced-consumed<=10)
        {
            sem_post(&atmost10);
        }
        sleep(1);
    }
}

void main()
{
    pthread_t th[2];
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,10);
    sem_init(&atmost10,0,1);
    pthread_create(&th[0],NULL,produce,NULL);
    pthread_create(&th[1],NULL,consume,NULL);
    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);
}