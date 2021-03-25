#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 100;
	pid_t pid;

	pid = vfork();
	if(-1 == pid){
		perror("vfork()");
		exit(1);
	}
	if(0 == pid){
	num ++ ;
	printf("[%d] ,num: %d \n" , getpid()  ,num);

	sleep(2);
	_exit(0);
	}

	printf("[%d] ,num: %d \n" , getpid()  ,num);
	exit(0);
}
