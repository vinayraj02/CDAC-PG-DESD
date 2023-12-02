#include<stdio.h>
#include<stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include<semaphore.h>
int *count_s;
sem_t *se;
void main(){
	int fd;
	fd=shm_open("/anshm",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	se=sem_open("/anshm", O_CREAT);
       //sem_init(se,1,1);
	ftruncate(fd,sizeof(int));
	count_s=(int *)mmap(NULL,sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
	sem_wait(se);
	printf("%d",(*count_s));
	sem_post(se);
	}
	
	
