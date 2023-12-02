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
atr.mq_msgsize=100;     
atr.mq_curmsgs=0; 

char buff[]="helloall\n";

fd=mq_open("/msg",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,&atr);
printf("%d\n",fd);
int s=mq_send(fd, buff,12, 0);
mq_close(fd);
printf("%d\n",s);

}
