#include <stdio.h>                                                                                         
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX 301
#define MIN 100

int main()
{
	pid_t p;
	int i , j;

	for(i = MIN ; i < MAX ; i++)
	{
	  	p = fork();
	  	if(p == -1){
	  		perror("fork()");
			exit(1);
	  	}
		if( p == 0){
			for(j = 2 ; j < i ;j++){
				if(i%j == 0)
					exit(0);	
			}
			printf("%d质数:%d\n", getpid() , i);
				exit(0);
		}
	}
	for(i = MIN ; i < MAX ; i++)
		wait(NULL);

	printf("******************************\n");

	exit(0);
}
