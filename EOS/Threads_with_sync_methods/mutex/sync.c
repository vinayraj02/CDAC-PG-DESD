#include<stdio.h>
#include<pthread.h>
int count=0;
pthread_mutex_t i;	//creating the mutex variable..........
void* inc(void* f){

	while(1){
    	pthread_mutex_lock(&i);	//use cases of the lock.........
	count++;
	printf("INC: %d\n",count);
	pthread_mutex_unlock(&i);
	}
}
void* dec(void* g){

	while(1){
	pthread_mutex_lock(&i);	//use cases of the lock.........
	count--;
	printf("DEC: %d\n",count);
	pthread_mutex_unlock(&i);
	}
}
int main(){
	pthread_mutex_init(&i,NULL);	//initialization of mutex variable...........
	pthread_t a,b;
	pthread_create(&a,NULL,inc,NULL);
	pthread_create(&b,NULL,dec,NULL);
	pthread_join(a,NULL);
	pthread_join(b,NULL);
	pthread_mutex_destroy(&i);	//destroying the varible....... 
	}
