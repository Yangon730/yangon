#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	char *opts[] = {"ls","-l",NULL};

	printf("%s start\n",__FUNCTION__ );
	pid = fork();

	if(0 == pid){
		//execl("./prime","./" ,NULL);//替换当前运行程序
		//execlp("ls","ls","-l",NULL);//在当前环境变量里的文件可以只写文件名
		execv("/bin/ls",opts);//可以把要替换的命令放在指针数组里
	//	execvp("ls",opts);//lp一样
		perror("execv()");
		exit(1);
	}
	wait(NULL);
	printf("%s end\n",__FUNCTION__ );

	exit(0);
}
