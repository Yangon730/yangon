#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define DECSIZE 10
#define NUMBSIZE 10

static int took = 0;
static void alarm_handler(int s)
{
	alarm(1);
	took = 1;
}
int main(int argc ,char *argv[])
{
	if(argc<2)
		return 1;
	int fd = open(argv[1] , O_RDWR);
	if(-1 == fd){
		perror("open()");
		return 1;
	}
	char buf[DECSIZE];
	int len; 
	signal(14 ,alarm_handler);
	alarm(1);

	while(1){
	//	while(took == 0 )
			pause();
		took = 0;
		memset(buf,'\0',DECSIZE);
		len	= read(fd , buf , DECSIZE);
		if(len == -1){
			perror("read()");
			goto ERROR;

		}
		if(len == 0){
			break;
		}
		write(1,buf,len);
	}
	close(fd);
	return 0;
ERROR:
	close(fd);
	return 1;
}
