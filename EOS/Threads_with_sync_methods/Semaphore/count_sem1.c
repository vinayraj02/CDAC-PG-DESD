#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define sem_th 2
/*shared resource*/
int count=0;	
sem_t s;

void *inc(void *u){	//processing two threads
	int t=*((int *)u);
	for(int i=0;i<5;++i){
	sem_wait(&s);
	count++;
	printf("inc:%d\n thread:%d\n",count,t);
	sem_post(&s);
	}
	}
	/*
void *dec(void*j){
	while(1){
	sem_wait(&s);while
	count--;
	printf("dec:%d\n",count);
	sem_post(&s);
	}
	}
	*/
int main(){
	pthread_t th[sem_th];	//pthread decleration
	int th_id[sem_th];	//semaphore decleration
	sem_init(&s,0,1);		//semaphore initialisation
	
	//creating two threads
	for(int i=0;i<sem_th;++i){
	th_id[i]=i+1;
	pthread_create(&th[i],NULL,inc,&th_id[i]);
	
	}
	
	// joining the two threads
	for(int i=0;i<sem_th;++i){
		pthread_join(th[i],NULL);
	}
	
	
	sem_destroy(&s);
	}
	
