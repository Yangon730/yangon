#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BUFSIZE 100

int main(int argc,char *argv[])
{
	time_t t;
	time(&t);

	char buf[BUFSIZE]={};

	struct tm *time;
	
	time = localtime(&t);
	time->tm_mday += atoi(argv[1]) ;

	t = mktime(time);

	time = localtime(&t);

	strftime(buf ,BUFSIZE , "%Y年 %m月 %d日 %H:%M" ,time);

	puts( buf);	

	return 0;

}
