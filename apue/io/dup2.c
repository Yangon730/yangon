#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc ,char *argv[])
{
	int fd;
	int i,j;
	
	if(argc > 1 && strcmp(argv[1] , ">>>>")  == 0 ){
		fd = open(argv[2] , O_WRONLY | O_CREAT | O_TRUNC ,0666);
		if(-1 == fd)
		{
			perror("open()");
			return 1;
		}
		dup2(fd ,1);
	}

	for(i = 1 ;i < 11 ; i++){
		for(j =1 ; j <= i ; j++ ){
			printf("*");
		}
		printf("\n");
	}
	
//	dup2(fd , 1 );
   	close(fd);
	return 0;
}
