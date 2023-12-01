#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
int main(){
	//pid_t fork(void);
	
	int a=fork();
	if(a==0){
	printf("\nchild born:%d\t%d\n",getpid(),getppid());
	}
	else{	
		printf("parent:%d\t%d\n",getpid(),getppid()); 
		}
	
	//fork();
	//printf("child born:%d\t%d\n",getpid(),getppid());
	//printf("%d\n",getppid());
	}
