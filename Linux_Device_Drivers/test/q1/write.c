#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main(){
    char buf[200]="HI VINAY";
    int fd;
    fd=open("/dev/vk_device",O_WRONLY);
    write(fd,&buf,strlen(buf));
    printf("data sent to kernel is:%s\n",buf);
    printf("writing done into the kernel\n");
    close(fd);
    return 0;
}
