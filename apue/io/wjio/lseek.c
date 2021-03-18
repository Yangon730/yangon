#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int fd;//文件描述符
	char buf[100] = {};
	int ret;

	if(argc < 2)
		return 1;
	fd = open(argv[1],O_RDWR /*| O_APPEND*/);
	if(fd == -1 ){
		perror("open()");
		return 1;
	}
	printf("%ld\n",lseek(fd , 1 , SEEK_SET));
  	ret = lseek(fd , -40 ,SEEK_END);
	printf("ret=%d\n",ret);

	write(fd , "helloword" ,10);
	//空洞文件
	lseek(fd , 1024 , SEEK_END);//空洞文件    复制会变为真实存在
	write(fd,"e",1);
	/*od -c 查看 */
	return 0;
}
