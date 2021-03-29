#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <syslog.h>
#include <errno.h>

#define  FILELOCK  "/var/run/daemon.pid"
#define  BUFSIZE   100


int run_only();
int mydaemon();

int main()
{
	int md , i = 1;
	struct tm *ti;
	char str[1024]={};
	time_t *t;

//	mydaemon();
	if (daemon( 0 , 0) == -1){
		perror("daemon()");
		return -1;
	}

	if(run_only() == -1){
		syslog(LOG_ERR, "run_already() failed");
		return -1;
	}

 	md = open("/tmp/out",O_RDWR | O_CREAT |O_TRUNC ,0666);
	openlog(NULL , LOG_PID , LOG_DAEMON);
	if(-1 == md){
		syslog(LOG_INFO,"%s :errno" , strerror(errno));
	//	perror("open()");
	//	return 1;
	}
	while(1){

    	*t =time(t);
		ti = localtime(t);
		strftime(str,1024 , "%Y-%m-%d  %H-%M-%S",ti);
		
		syslog(LOG_INFO,"%s 找到了%d只郭浩辉" , str,i++);

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
	dup2(fd,  2);	if(fd > 2)
		close(fd);
	return 0;
}
int run_only()
{
	int md;
	char buf[BUFSIZE];
	md = open(FILELOCK ,O_WRONLY | O_CREAT ,0664);
	if(-1 == md){
		syslog(LOG_ERR , "open():%s" ,strerror(errno));
		return -1;
	}
	if(lockf(md ,  F_TLOCK , 0) == -1){	
		syslog(LOG_ERR , "lockf():%s" ,strerror(errno));
		return -1;
	}
	ftruncate(md,0);
	snprintf(buf ,BUFSIZE ,  "%d" ,getpid());
	write(md , buf , strlen(buf));

}
