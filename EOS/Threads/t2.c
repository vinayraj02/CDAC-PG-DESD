/*creating three threads*/

#include<stdio.h>
#include<pthread.h>
void *add(void *n){  //thread 1
	int a=4,b=6;
	printf("add:%d\n",a+=b);
	}

//thread 2
void *sub(void *j){
	int a=6,b=2;
	printf("sub:%d\n",a-=b);
	}

//thread 3
void *div(void *u){
	int a,b,c;
	scanf("%d%d\n",&a,&b);
	c=a/b;
	printf("div:%d\n",c);
	}
int main(){
	pthread_t id,id2,id3; //thread variable
	printf("before creating thread\n");
	pthread_create(&id,NULL,add,NULL);
	pthread_create(&id2,NULL,sub,NULL);
	pthread_create(&id3,NULL,div,NULL);
	pthread_join(id,NULL);   //by this join function the main function will wait until completion of the thread to execute
	pthread_join(id2,NULL);
	pthread_join(id3,NULL);
	printf("after joining the threads\n");
	}
