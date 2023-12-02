#include<stdio.h>
#include<pthread.h>
pthread_barrier_t a;
void *bar(void *b)
{
	pthread_barrier_wait(&a);
	printf("bar 1\n");
	

	}
void *bar1(void *c){
	pthread_barrier_wait(&a);
	printf("bar 2\n");
	
	}
void *bar2(void *d){
	pthread_barrier_wait(&a);
	printf("bar 3\n");
	
	}
void *bar3(void *e){
	
	printf("bar 4\n");
	}
int main(){
	pthread_t h,i,j,k;
	pthread_barrier_init(&a,NULL,3);
	pthread_create(&h,NULL,bar,NULL);
	pthread_create(&i,NULL,bar1,NULL);
	pthread_create(&j,NULL,bar2,NULL);
	pthread_create(&k,NULL,bar3,NULL);
	pthread_join(h,NULL);
	pthread_join(i,NULL);
	pthread_join(j,NULL);
	pthread_join(k,NULL);
	pthread_barrier_destroy(&a);
	}
	
