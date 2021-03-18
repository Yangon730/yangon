#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define NUMBSIZE 100

int main(int argc ,char *argv[])
{
	int fd , md;
	int i = 0;
	int l , len;
	char buf[NUMBSIZE];
	
	if(argc < 3)
		return 1;
	
	fd = open(argv[1],O_RDONLY);
 	
	if(-1 == fd){
		perror("open()");
		return -1;
	}
	md = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,0666);

	if(md == -1){
		perror("open()");
		goto ERROR;
	
	}
	while(1){
	if(l == -1)
		break;
	
	l =	lseek(fd , i-- ,SEEK_END);
	
	len = read(fd , buf , 1);
	if(len == -1){
		perror("read()");
		goto ERROR1; 
	} 
	write(md ,buf ,len);
	}

	close(fd);
	close(md);
	return 0;
ERROR1:
	close(md);
	
ERROR:
	close(fd);
}
