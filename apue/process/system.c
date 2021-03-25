#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <glob.h>
#include <string.h>

int Issystem(char *str,glob_t *dest)
{
	char *r = malloc(strlen(str)+1);
	strcpy(r ,str);
	puts(r);
	char *m;
	int i = 0;
	while(1){
		m = strtok(r , " ");
		if(NULL == m)
			break;
		glob(m , GLOB_NOCHECK |  GLOB_APPEND * i ,NULL ,dest);
		i=1;
		r = NULL;
	}
	free(r);
	r = NULL;
	return 0;
}

void sssystem(char *arr)
{

	pid_t pid;
	glob_t gb;
	Issystem(arr,&gb);
	pid = fork();
	if(-1 == pid){
		perror("fork()");
		exit(1);
	}
	if(0 == pid)
	{
		execvp((gb.gl_pathv)[0] , gb.gl_pathv);
		perror("execvp()");
		exit(0);
	}
	wait(NULL);
	globfree(&gb);
}
int main()
{
	char *arr = "ls -l";

	sssystem(arr);
	printf("欢迎来到傻瓜系统:boy\n");
	getchar();
	return 0;
}
