#include <stdio.h>
static int glob;//只能在本文件使用
int ass;
static void tast(void);
int main(void)
{
	int a,b,c,e,f,g;


	printf("%d,%d\n%d,%d,%d\n",glob,ass,a,b,c);

	printf("%d,%d,%d\n",e,f,g);

    tast();
    tast();
	tast();
	return 0;
}
static void tast(void)//只能在本文件使用，其他文件定义相同名称不会冲突；
{
	static int a;
	printf("n:%d\n",a);
	a++;
}
