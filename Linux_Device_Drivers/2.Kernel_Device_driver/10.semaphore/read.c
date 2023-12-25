#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd,op_result;
    fd=open("/dev/sem_dr",O_RDWR,0777);
    read(fd,&op_result,sizeof(op_result));
    printf("result from the kernel is :%d\n",op_result);
    close(fd);
    return 0;
}