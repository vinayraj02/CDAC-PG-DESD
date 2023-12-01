#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
 #include <sys/types.h>
#include <sys/wait.h>


int main()
{
	int a=2,b=4,*c;
	pid_t  i=fork();
	int d=4;
	 c=&d;
	if(i==0)
	{
		printf("in child\n");
		printf("ADD:%d\n",a+b);
		printf("MUL:%d\n",a*b);
		
	}
	else
	{
		 wait(c);
		printf("in parent\n");
		printf("sub:%d\n",a-b);

	}
}		
		
