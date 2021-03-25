#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void test(void)
{
	//return;
	exit(0);
}
void handler1(void)
{
printf("%s\n",__FUNCTION__);
}
void handler2(void)
{
printf("%s\n",__FUNCTION__);
}
void handler3(void)
{
printf("%s\n",__FUNCTION__);
}

int main()
{
	//test()
	atexit(handler1);
	atexit(handler2);
	atexit(handler3);
	printf("helloWORD");
	//_exit(EXIT_SUCCESS/*参数是为了给副进程信号*/);//不刷新缓存区
	exit(EXIT_SUCCESS);	//exit刷新缓存区

}
