#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <glob.h>
#include <stdlib.h>
#include <sys/wait.h>
int main( )
{
	char *str = NULL;

	size_t len = 0;
	char *dest ;
	int i = 0;	
	pid_t pid;
	glob_t gb;

	while(1){
		printf("[%s]$",getenv("PWD"));
		getline(&str , &len , stdin);
		if(strncmp(str,"exit\n",strlen("exit")) == 0){
			free(str);
			str = NULL;
			break;
		}
		while(str[i] != '\n')
			i++;

		str[i] = '\0';
		i = 0;	
		while(1){

			dest = strsep(&str," \n");
		
			if(NULL == dest)
				break;
			glob(dest , GLOB_NOCHECK | GLOB_APPEND * i , NULL ,&gb);
			i =  1;
		}

		pid = fork();
		if (-1 == pid){
			perror("fork()");
			exit(1);
		}

		if(pid == 0){
			execvp(( gb.gl_pathv)[0] , gb.gl_pathv );
			perror("execvp()");
			exit(0);

		}
		globfree(&gb);
		free(str);
		str = NULL;

		wait(NULL);
	} 

	exit(0);
}

