#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
//令牌桶  速率  令牌  桶上限  
#define DECSIZE 10
#define NUMBSIZE 100

static int took = 0;
static void alarm_handler(int s)
{
	alarm(1);
	took += DECSIZE;
	if(took == NUMBSIZE)
		took = NUMBSIZE;
}
int main(int argc ,char *argv[])
{
	int fd;
	if(argc<2)
		return 1;
	do{
		 fd = open(argv[1] , O_RDWR);
		if(-1 == fd){
			//假错
			if(errno == EINTR)
				continue;
			perror("open()");
			return 1;
		}
		break;
	}while(1);

	char buf[DECSIZE];
	int len; 
	signal(14 ,alarm_handler);
	alarm(1);

	while(1){
		//流量控制
		while(took < DECSIZE)
			pause();
		took -= DECSIZE;
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
