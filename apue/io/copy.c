//把一个文件拷贝到另一个文件
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define NUMSIZE  10

int main(int argc ,char *argv[])
{
	int fd , md;
	int len;
	char buf[NUMSIZE];
	if(argc < 3)
		return 1;
	fd = open(argv[1], O_RDONLY);

	if(-1 == fd){
		perror("open()");
		goto ERROR1;
	}
	md =open(argv[2],O_WRONLY | O_CREAT | O_TRUNC ,0666);
	if(md == -1 ){
		perror("open()");
		goto ERROR2;
	}

	while(1){

		len = read(fd,buf,NUMSIZE);
		if(len == -1){
			perror("read()");
			goto ERROR;
		}
		if(len == 0){
			break;
		}
		write(md, buf,len);

	}
	close(fd);
	close(md);
	return 0;
ERROR:
	close(md);
ERROR2:
	close(fd);
ERROR1:
	return 1;
}
