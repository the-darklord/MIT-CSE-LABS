#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

sem_t waiting,barber,mutex;
int f,r;
int maxSeats[5];
int i;

void* customer(void* param){
	while(1){
		sem_wait(&waiting);
		printf("Customer %d is waiting\n",i);
		maxSeats[(++r)%5] = i;
		i++;
		sem_post(&mutex);
		sleep(1);
	}
}

void* barb(void* param){
	while(1){
		sem_wait(&barber);
		sem_wait(&mutex);
		int item = maxSeats[(++f)%5];
		sem_post(&waiting);
		printf("Cutting Started for %d\n",item);
		sleep(4);
		printf("Cutting complete for %d\n",item);
		sem_post(&barber);
	}
}

int main(){
	pthread_t cust,bar;

	//Available chairs are 5
	sem_init(&waiting,0,5);
	sem_init(&barber,0,1);
	sem_init(&mutex,0,0);

	pthread_create(&cust,0,&customer,NULL);
	pthread_create(&bar,0,&barb,NULL);

	pthread_join(cust,NULL);
	pthread_join(bar,NULL);

}
