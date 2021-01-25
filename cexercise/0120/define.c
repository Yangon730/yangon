/*gcc 的四个步骤
  1、预处理 -E
  2、编译：翻译成汇编   -S
  3、汇编：生成目标文件（二进制文件）-c
  4、
*/
#include <stdio.h>
#define NUM 10
#define SQUARE(x)   (x)*(x) //加括号
#define SWAP(x,y)\
	do{\
		typeof(x) t; t = x; x = y; y = t ;\
	}while(0)
int main(void)
{
	int i=5 ;
    int x = 5;
    int y = 6;
	SWAP(x,y);
	printf("%d,%d\n",x,y);
	printf("%d\n",SQUARE(i));
#if 0
	for(i=0;i<NUM;i++)
		scanf("%d",&score);
#endif
	return 0;

}

