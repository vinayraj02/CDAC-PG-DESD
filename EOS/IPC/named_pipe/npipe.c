#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	char buf[]="hello tobi\n";
	int fd=open("vk",O_RDWR,S_IRWXU);
	write(fd,buf,sizeof(buf));
	close(fd);
	}
