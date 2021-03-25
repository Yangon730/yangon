#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int m=2;
	pid_t pid ,ppid;
	pid_t p;
	pid = getpid();
	ppid = getppid();
	int num = 100;
	printf("pid:%d , ppid:%d \n" ,pid ,ppid);
	printf("********************************************");
	fflush(NULL);
	p = fork();
	if(p == -1){
		perror("fork()");
		exit(0);
	}
	if( p == 0 ){
		printf("child's pid:%d ,child's prent pid:%d\n",getpid(), getppid() );
		printf("*******************************1:%d\n",num );
		num = 200;
		printf("*******************************2:%d\n",num );
		sleep(3);
	    exit(m);
	}

	wait(&m);//收尸
#if 0
	for(int i = 0 ; i < 5 ;i++ ){
		write(1 , "*" , 1);
		sleep(1);
	}
#endif
    printf("\n");
	printf("*******************************3:%d\n",num);
	exit(0);
}

