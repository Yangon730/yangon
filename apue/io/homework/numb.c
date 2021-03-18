#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc , char *argv[])
{
	int i = 0;
	int len;
	int fd;
	char buf;
	if(argc < 2)
		return 1;

	fd = open(argv[1] , O_RDONLY);
	if(-1 == fd){
		perror("open()");
		return 1;
	}
	while(1){
		len = read(fd , &buf , 1);
		if(len == 0)
			break;
		if(buf == ' ' || buf == '\n'){

			i++;
		}
	}
	printf("%d\n" ,i);
	close(fd);
	return 0;

}
