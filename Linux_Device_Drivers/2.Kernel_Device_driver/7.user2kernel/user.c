#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char read_buf[500];
char write_buf[500];

int main(){

    int fd,c;
    fd = open("/dev/file_ch",O_RDWR);
    printf("enter your choise:\n1.write to kernel\n2.read from kernel\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("enter the string to write:\n");
        scanf("%s",write_buf);
        write(fd,write_buf,500);
        break;
    case 2:
        read(fd,read_buf,500);
        printf("%s",read_buf);
        break;
    
    default:
        printf("enter the right choice\n");
        break;
    }
    

    
    close(fd);
    return 0;
}
