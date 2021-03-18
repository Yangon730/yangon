#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define SIZE  1024

int main(int argc,char *argv[])
{
	int num = 0;
	int len;
	int fd , wd;
	char buf[SIZE] = {};	
	if(argc < 4)
		return 1;

	fd = open(argv[1],O_RDONLY);
	if(fd == -1){
		perror("open()");
		return 1;	
	}
	wd = open(argv[3] ,O_WRONLY | O_CREAT | O_TRUNC ,0666);
	if(wd == -1){
		perror("open()");
		goto ERROR;
	}

	while(1){
		len  = read(fd , buf ,1);
		if(len == -1){
			perror("read()");
			goto ERROR1;
		}
		if(len == 0)
			break;

		if(num == 3){
			lseek(wd ,-1 ,SEEK_CUR);
			write(wd ,argv[2] ,strlen(argv[2])+1);
			write(wd,"\n",1);
			num++;
		}
		if( buf[0] == '\n')
				num++;
		write(wd ,buf ,len);
			
	}
	close(fd);
	close(wd);
	return 0;
ERROR1:
	close(wd);
ERROR:
	close(fd);
}

