// #include<stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int main(){
//     int fd,n1,n2;
//     printf("enter the values of n1 and n2\n");
//     scanf("%d%d",&n1,&n2);
//     int ubuf[2]={n1,n2};
//     fd=open("/dev/vk_spin",O_RDWR,0777);
//     write(fd,(char*)&ubuf,sizeof(ubuf));
//     close(fd);
//     return 0;
// }


#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd,num1,num2;
    printf("enter the values of num1 and num2\n");
    scanf("%d%d",&num1,&num2);
    int ubuf[2]={num1,num2};
    fd=open("/dev/vk_spin",O_RDWR,0777);
    write(fd,(char *)&ubuf,sizeof(ubuf));
    close(fd);
    return 0;

}