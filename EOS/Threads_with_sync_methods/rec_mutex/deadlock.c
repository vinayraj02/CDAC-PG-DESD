//in this if we give multiple locks and give only one unlock then it goes into deadlock state

#include<stdio.h>
#include<pthread.h>
pthread_mutex_t i;
void *inc(void*j){
	int count=0;
	printf("entered into the thread\n");
	while(1){
		pthread_mutex_lock(&i);
		pthread_mutex_lock(&i);
		count++;
		printf("inc:%d\n",count);
		pthread_mutex_unlock(&i);
		}
	}
	
int main(){
	pthread_t a;
	pthread_mutex_init(&i,NULL);
	pthread_create(&a,NULL,inc,NULL);
	pthread_join(a,NULL);
	pthread_mutex_destroy(&i);
	}
	
