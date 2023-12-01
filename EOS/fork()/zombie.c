#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int i;
    i=fork();
    if(i==0){
        printf("child id:%d\t ppid:%d\n",getpid(),getppid());
        // exit(0);
     

    }
    else{
           printf("parent id:%d\t ppid:%d\n",getpid(),getppid());
        sleep(5);
    }
}	
