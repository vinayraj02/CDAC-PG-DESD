#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
#include <sys/ioctl.h>

#define MAGIC 'k'
#define GETSTATS _IOR(MAGIC, 1, struct stats *)

struct stats {
    int size;
    char ubuf[200];
    int r_w;
};


int main(){
    int fd;
    struct stats data;
    fd = open("/dev/vk_device",O_RDWR);
     if (ioctl(fd, GETSTATS, &data) < 0) {
        printf("Failed to get stats from the device\n");
        close(fd);
        return -1;
    }
    printf("size of the data from the kernel is:%d\n",data.size);
    printf("data from the kernel:%s\n",data.ubuf);
    printf("recent activity:%d\n",data.r_w);

    close(fd);
    return 0;

}
