#include <stdio.h>                                                                                         
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX 300
#define MIN 100

int prime(int i)
{
	for(int j = 2 ; j < i ;j++)
		if(i % j == 0)
			return 0;	
	return 1;
}
int main(void)
{
	pid_t p;
	int i,j;
	for( j=MIN ; j < MAX  ;j += 50){
		p = fork();
		if(-1 == p ){
			perror("fork()");
			exit(1);
		}
		if(0 == p){
			for(i = j ; i <= j+50 ; i++){
				if(prime(i))
					printf("[%d]质数:%d\n" , getpid() ,i);
			}
			exit(0);
		}
	}
	for(i = 0 ; i < 4 ;i++)
		wait(NULL);
	exit(0);
}


