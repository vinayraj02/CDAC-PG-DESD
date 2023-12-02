#include<stdio.h>
#include<pthread.h>
pthread_mutex_t i;
pthread_mutexattr_t k;
int count=0;
void* inc(void* f){

	while(1){
    	pthread_mutex_lock(&i);
    	pthread_mutex_lock(&i);	//use cases of the lock.........
	count++;
	printf("INC: %d\n",count);
	pthread_mutex_unlock(&i);
	pthread_mutex_unlock(&i);
	}
}
void* dec(void* g){

	while(1){
	pthread_mutex_lock(&i);
	pthread_mutex_lock(&i);	//use cases of the lock.........
	count--;
	printf("DEC: %d\n",count);
	pthread_mutex_unlock(&i);
	pthread_mutex_unlock(&i);
	}
}
int main(){
		//initialization of mutex variable...........
	pthread_t a,b;
	pthread_mutexattr_init( &k);
	pthread_mutexattr_settype(&k, PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutex_init(&i,&k);
	
	pthread_create(&a,NULL,inc,NULL);
	pthread_create(&b,NULL,dec,NULL);
	
	pthread_join(a,NULL);
	pthread_join(b,NULL);
	pthread_mutexattr_destroy(&k);
	pthread_mutex_destroy(&i);
		//destroying the varible....... 
	}
