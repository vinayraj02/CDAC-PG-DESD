#include<stdio.h>
#include<pthread.h>
int count=0;
void* inc(void* a){
	int i=0;
	while(i<=10){
	count++;
	printf("INC: %d\n",count);
	//i++;

	}
}
void* dec(void* b){
	int i=0;

		while(i<=10){
	count--;
	printf("DEC: %d\n",count);
	//i++;
	
	}
}
int main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,inc,NULL);
	
	pthread_create(&t2,NULL,dec,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
