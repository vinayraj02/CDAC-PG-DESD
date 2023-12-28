#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main(){
    char buf[200];
    int fd;
    fd=open("/dev/vk_device",O_RDONLY);
    read(fd,&buf,sizeof(buf));
    printf("string from the kernel is:%s\n",buf);
    close(fd);
    return 0;
}