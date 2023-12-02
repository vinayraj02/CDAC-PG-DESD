#include<stdio.h>
#include<pthread.h>
int count=0,g;
pthread_mutex_t o;
pthread_cond_t a;
void*lok(void *u){
	int i=0;
	pthread_mutex_lock(&o);
	printf("1st thread\n");
	pthread_cond_wait(&a,&o);
	printf("return from th-2\n the number from thread 2 is:%d\n",g);
	pthread_mutex_unlock(&o);
	}
void*vk(void*h){
	pthread_mutex_lock(&o);
	printf("in 2nd th\nenter the number:\n");
	scanf("%d",&g);
	pthread_cond_signal(&a);
	pthread_mutex_unlock(&o);
	}
int main(){
	pthread_t j,k;
	pthread_mutex_init(&o,NULL);
	pthread_cond_init(&a,NULL);
	pthread_create(&j,NULL,lok,NULL);
	pthread_create(&k,NULL,vk,NULL);
	pthread_join(j,NULL);
	pthread_join(k,NULL);
	pthread_cond_destroy(&a);
	pthread_mutex_destroy(&o);
	}
	
