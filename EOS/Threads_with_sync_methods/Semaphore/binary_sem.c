#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int count=0;	//binary semaphore
sem_t s;
void *inc(void *u){
	while(1){
	sem_wait(&s);
	count++;
	printf("inc:%d\n",count);
	sem_post(&s);
	}
	}
void *dec(void*j){
	while(1){
	sem_wait(&s);
	count--;
	printf("dec:%d\n",count);
	sem_post(&s);
	}
	}
int main(){
	pthread_t a,b;
	sem_init(&s,0,1);
	pthread_create(&a,NULL,inc,NULL);
	pthread_create(&b,NULL,dec,NULL);
	pthread_join(a,NULL);
	pthread_join(b,NULL);
	sem_destroy(&s);
	}
	
