//this is the intra process communication

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int arr[2];
	pid_t a;
	char buf[50];
	char tuf[]="hello tobi\n";
	
	pipe(arr);
	a=fork();
	if(a==0){
		close(arr[1]);
		//int fd=open(arr[0],O_RDWR,S_IRWXU);
		//read(fd, buf, 50);
		read(arr[0], buf, 50);
		printf("%s",buf);
		close(arr[0]);
		}
	else{
		close(arr[0]);
		//int fd=open(arr[1],O_RDWR,S_IRWXU);
		//write(fd, tuf, sizeof(tuf));
		write(arr[1], tuf, sizeof(tuf));
		close(arr[1]); 
		}
}
