#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pid , wait_pid;

	pid = fork();
	if(-1 == pid){
		perror("fork()");
		exit(1);
	}
	if(0 == pid){
		printf("%d\n",pid);
		setpgid(getpid() ,getpid());
		printf("child pid:%d , gpid:%d \n" , getpid() ,getpgid(pid));
	
		exit(0);
	}

	printf("perent pid:%d , gpid:%d \n" , getpid() ,getpgid(pid));
	
	wait_pid = waitpid(-pid , NULL , 0);// 收尸进程组id = pid绝对值 的组内的任意子进程
	//wait_pid = waitpid(-1 , NULL , 0);//任意子进程
	//wait_pid = waitpid(pid , NULL , 0);//指定子进程
	//wait_pid = waitpid(0 , NULL , 0);//进程组内任意进程


	printf("pid:%d , waitpid:%d \n" , pid , wait_pid);
	exit(0);
}
