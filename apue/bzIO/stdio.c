#include <unistd.h>
#include <stdio.h>

int main()
{
	//标准I/O
	printf("hello");
	fflush(NULL);//强制刷新(NULL全部缓存区)
	printf("word");//有缓存区

	//文件I/O
	write(1, "good" , 4);
	write(1,"morning",7);//无缓存区先打印

	return 0;//进程结束刷新缓存区
}
