#include<stdio.h> 
#include<stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int *count_r;

int main(){
	int fd;
	fd=shm_open("/anshm",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(int));
	count_r=(int *)mmap(NULL,sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
	printf("%d",(*count_r));
	}
	
