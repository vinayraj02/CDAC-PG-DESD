#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int count=0;	//counting semaphore
sem_t s;
void *inc(void *u){
	int i=0;
	while(1){
	sem_wait(&s);
	count++;
	printf("inc:%d\n",count);
	sem_post(&s);
	i++;
	}
	}
void *dec(void*j){
	int i=0;
	while(1){
	sem_wait(&s);
	count--;
	printf("dec:%d\n",count);
	sem_post(&s);
	i++;
	}
	}
int main(){
	pthread_t a,b;
	sem_init(&s,0,2);
	pthread_create(&a,NULL,inc,NULL);
	pthread_create(&b,NULL,dec,NULL);
	pthread_join(a,NULL);
	pthread_join(b,NULL);
	sem_destroy(&s);
	}
	
