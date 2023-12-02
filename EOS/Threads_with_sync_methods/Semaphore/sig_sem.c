#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int count=0;	//signalling semaphore
sem_t s,s1;
void *inc(void *u){
	int i=0;
	//while(i<10){
	sem_wait(&s);
	count++;
	printf("in the 1st thread\n");
	printf("inc:%d\n",count);
	
	sem_post(&s1);
	i++;
	}
	//}
void *dec(void*j){
	int i=0;
	//while(i<10){
	sem_wait(&s1);
	count--;
	printf("in the 2st thread\n");
	printf("dec:%d\n",count);
	sem_post(&s);
	i++;
	//}
	}
int main(){
	pthread_t a,b;
	sem_init(&s,0,0);
	sem_init(&s1,0,1);
	pthread_create(&a,NULL,inc,NULL);
	pthread_create(&b,NULL,dec,NULL);
	pthread_join(a,NULL);
	pthread_join(b,NULL);
	sem_destroy(&s);
	}
	
