#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int  main()
{
	pid_t i=fork();
	if(i==0)
	{
	sleep(10);
	printf("pid of child:%d\t ppid of child:%d\n",getpid(),getppid());
	printf("im an orphan\n");
	
	}
	else
	{
	printf("pid of parent:%d\t ppid of parent:%d\n",getpid(),getppid());
	printf("end of parent\n");
	exit(0);
	
	}
}	
