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
    fd=open("/dev/sem_dr",O_RDWR,0777);
    write(fd,(char *)&ubuf,sizeof(ubuf));
    close(fd);
    return 0;

}