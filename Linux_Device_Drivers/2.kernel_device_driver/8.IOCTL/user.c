#include<stdio.h>
#include<sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include <unistd.h>
#include"ioctl.h"

int main(){
    int fd;
    fd=open("/dev/vk_device",O_RDWR);
    printf("file fd:%d\n",fd);
    ioctl(fd,CMD_1);
    ioctl(fd,CMD_2,78);
    close(fd);
    return 0;
}