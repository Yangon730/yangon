#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#define NUMBSIZE 10

int main(int argc ,char *argv[])
{
	if(argc<2)
		return 1;
#if 0
	int fd = open(argv[1],O_RDONLY);
	if(fd == -1){
		printf("errno:%d\n",errno);
		perror("open()");
		return 1;
	}
	int fd = open(argv[1] , O_RDWR  , 0666)
#endif
	int fd = open(argv[1] , O_RDWR);
   	if(-1 == fd){
		perror("open()");
		return 1;
	}
	char buf[NUMBSIZE];
	int len =1; 
	while(1){
		memset(buf,'\0',NUMBSIZE);
    	len	= read(fd , buf ,NUMBSIZE);
		if(len == -1){
			perror("read()");
			goto ERROR;
		
		}
		if(len == 0){
			break;
		}
		write(1,buf,len);

	//	puts(buf);
	//	printf("%s\nlen=%d\n",buf,len);
	}
	
	close(fd);
//	printf("fd:%d\n",fd);
	return 0;
ERROR:
	close(fd);
	return 1;
}

//打开文件open
