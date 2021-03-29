#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <unistd.h>
 typedef void (*sighandler_t)(int);//要自己定义 函数指针类型
/*
   信号响应是嵌套的，优先响应新来信 同一个信号在响应期间不会嵌套mask此时置1
   信号处理函数中不能用longjmp跳转
 信号是一个位图多次发送只响应一次 0置1 标准信号会丢失 ，会打断阻塞系统调用

 */
static void handler(int s/*响应信号的值*/)
{
	printf("arg s:%d",s);
	for(int i=0 ; i<3 ;i++){
		write(1 ,"*" ,1);
		sleep(1);
	}
}

int main()
{
	int i = 0;
	struct sigaction act ,oldact;
	sighandler_t sig =	signal(SIGINT , handler) ;

	act.sa_handler = handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
//	signal(SIGQUIT ,sig);
	sigaction(SIGQUIT , &act ,&oldact);
	while(1){
		i++;
		if(10 == i)
			signal(SIGINT , sig); 
		write(1 , "##", 2 );
		sleep(1);
	}
	exit(0);
}
