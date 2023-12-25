// #include<stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int main(){
//     int fd,re;
//     fd=open("/dev/vk_spin",O_RDWR,0777);
//     read(fd,&re,sizeof(re));
//     printf("result from the kernel is:%d\n",re);
//     close(fd);
//     return 0;
// }

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd,op_result;
    fd=open("/dev/vk_spin",O_RDWR,0777);
    read(fd,&op_result,sizeof(op_result));
    printf("result from the kernel is :%d\n",op_result);
    close(fd);
    return 0;
}