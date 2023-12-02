#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
extern int errno;
int main(){
	char buf[]="hello tobi";
	int a=open("f1.txt",O_CREAT|O_RDWR,S_IRWXU);
	printf("a=%d\n",a);
	if(a==-1){
	printf("error number %d\n",errno);
	perror("program");
	}
	write(a,buf,sizeof(buf));
	char ch;
	FILE *file=fopen("f1.txt","r");
	while((ch=fgetc(file)!=EOF)){
	printf("%c",ch);
	}
	//close(f1.txt);
	return 0;
	}
