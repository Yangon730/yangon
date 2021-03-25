#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int mydaemon();
int main()
{
	int md;
	struct tm *ti;
	char str[1024]={};
	time_t *t;
	mydaemon();
 	md = open("/tmp/out",O_RDWR | O_CREAT |O_TRUNC ,0666);
	if(-1 == md){
		perror("open()");
		return 1;
	}
	while(1){

    	*t =time(t);
		ti = localtime(t);
		strftime(str,1024 , "%Y-%m-%d  %H-%M-%S",ti);
		sleep(1);
		write(md ,str,strlen(str));
		write(md ,"\n",1);
	}
	return 0;
}
int mydaemon()
{
	int fd;
	pid_t pid;
	pid = fork();
	if(-1 == pid){
		perror("fork()");
		return -1;
	}
	if(pid > 0)
		exit(0);

	if(setsid() == -1)
	{
		perror("setsid()");
		return -1;
	}
	chdir("/");
	umask(0);
	fd = open("/dev/null",O_RDWR);
	dup2(fd , 0);
	dup2(fd , 1);
	dup2(fd,  2);
	if(fd > 2)
		close(fd);
	return 0;
}
