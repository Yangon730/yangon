#include <stdio.h>
#include <stdlib.h>
extern char **environ;

int main(void)
{
	for(int i = 0; environ[i] ;i++)
		puts(environ[i]);

	printf("*****************************************\n");
	char *p = getenv("PATH");
	puts(p);
	setenv("PATH" , "." ,1);
	p = getenv("PATH");
	puts(p);
	printf("*****************************************\n");
	for(int i = 0; environ[i] ;i++)
		puts(environ[i]);

	return 0;
}
