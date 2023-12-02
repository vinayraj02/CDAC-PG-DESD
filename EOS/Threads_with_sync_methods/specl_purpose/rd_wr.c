#include<stdio.h>
#include<pthread.h>
int n,g,m;
pthread_t a,b,t,i;
pthread_rwlock_t h;
void *read(void *r){
	pthread_rwlock_rdlock(&h);
	printf("enter 1 number:\n");
	scanf("%d",&n);
	pthread_rwlock_unlock(&h);
	}
void *read1(void *r){
	pthread_rwlock_rdlock(&h);
	printf("enter 2 number:\n");
	scanf("%d",&g);
	pthread_rwlock_unlock(&h);
	}
void *read2(void *r){
	pthread_rwlock_rdlock(&h);
	printf("enter 3 number:\n");
	scanf("%d",&m);
	pthread_rwlock_unlock(&h);
	}
void *write(void*w){
	pthread_rwlock_wrlock(&h);
	printf("%d\n",n);
	printf("%d\n",g);
	printf("%d\n",m);
	pthread_rwlock_unlock(&h);
	}
int main(){
	pthread_rwlock_init(&h,NULL);
	pthread_create(&a,NULL,read,NULL);
	pthread_join(a,NULL);
	pthread_create(&t,NULL,read1,NULL);
	pthread_join(t,NULL);
	pthread_create(&i,NULL,read2,NULL);
	pthread_join(i,NULL);
	pthread_create(&b,NULL,write,NULL);
	pthread_join(b,NULL);	
	pthread_rwlock_destroy(&h);
}
