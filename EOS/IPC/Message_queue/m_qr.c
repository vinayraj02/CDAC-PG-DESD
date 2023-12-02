#include<stdio.h>
#include <fcntl.h>           
#include <sys/stat.h>       
#include <mqueue.h>
 #include<string.h>
struct mq_attr atr;
 mqd_t fd;
int main(){

atr.mq_flags=0;       
atr.mq_maxmsg=4;     
atr.mq_msgsize=64;     
atr.mq_curmsgs=0; 

char buff[100];

fd=mq_open("/msg",O_RDWR,S_IRUSR|S_IWUSR,&atr);
int r=mq_receive(fd,buff,100, 0);
buff[strlen(buff)]='\0';
printf("%s\n",buff);

mq_close(fd);
printf("%d\n",r);


}
