#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	char tuf[50];
        int fd=open("vk",O_RDWR,S_IRWXU);
	read(fd,tuf,50);
	printf("%s",tuf);
	close(fd);
	}
