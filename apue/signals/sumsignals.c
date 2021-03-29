#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
//#include <fcntl.h>
#include <unistd.h>
//struct sigaction 
static void handler1(int s)
{
	write(1 , "!" ,1);
}
static void handler2(int s)
{
	write(1 , "$" ,1);
}

int main(void)
{
	sigset_t set, oldset; //信号集类型

	signal(SIGINT,handler1);
	signal(SIGQUIT , handler2);
	
	sigemptyset(&set);//信号集置空
	sigaddset(&set , SIGINT);	
	sigaddset(&set , SIGQUIT);

	for(int i = 0 ;i < 10 ; i++){
		sigprocmask(SIG_BLOCK ,&set ,&oldset); //检测更改屏蔽字
		for(int j = 0 ;j < 5 ;j++)
		{
			write(1, "*" , 1);
			sleep(1);
		}
		write(1 , "\n" , 1);
//		sigsuspend(&oldset);
		/*
		sigprocmask(SIG_BLOCK ,&set , &oldset);
		pause();
		sigprocmask(SIG_SETMASK ,&oldset , NULL);
		*/
		sigprocmask(SIG_SETMASK ,&oldset , NULL);
	}

	exit(0);
}
