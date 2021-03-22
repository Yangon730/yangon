#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#define BUFSIZE 128
int main (int argc ,char *argv[])
{
	DIR *dp;
	struct dirent *dir;
	long size = 0;
	struct stat res;
	char buf[BUFSIZE] = {};

	if(argc < 2){
		return 1;
	}
	dp = opendir(argv[1]);
	if(dp == NULL){
		perror("opendir()");
		return 1;
	}
	while(1){
		dir = readdir(dp);
		if(NULL==dir){
			if(!errno)
				break;
			perror("readdir()");
			goto READERROR;
		}
		//	printf("%s\n" , dir->d_name);
		memset(buf,'\0',BUFSIZE);
		strncpy(buf , argv[1] ,BUFSIZE);
		strcat(buf , "/" );
		strncat(buf, dir->d_name ,BUFSIZE);
		if(stat(buf, &res) == -1){ 
			perror("stat()");
			return 1;
		}
		size += res.st_size;
	}
	printf("**********************%ld\n",size);
	closedir(dp);
	return 0;
READERROR:
	closedir(dp);
	return 1;
}
