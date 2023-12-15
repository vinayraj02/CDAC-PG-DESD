#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char read_buf[1024];
char write_buf[1024];

int main(){
    int fd;
    fd = open("/dev/vk_ch",O_RDWR);
    read(fd,read_buf,1024);
    printf("%s",read_buf);
    printf("enter the string to write:\n");
    scanf("%s",write_buf);
    write(fd,write_buf,1024);
    
    close(fd);
}
