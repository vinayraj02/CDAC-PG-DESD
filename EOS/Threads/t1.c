#include<stdio.h>
#include<pthread.h>
void *thread(void * arg){
	printf("inside thread\n");
	}
int main(){
	pthread_t id;
	int *a,*c,b=10,d=20;
	a=&b;
	c=&d;
	printf("b c\n");
	pthread_create(&id,NULL,thread,NULL);
	pthread_join(id,NULL);
	printf("af join\n");
	}
