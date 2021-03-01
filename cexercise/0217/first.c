//输出两个数的最大值
#include <stdio.h>
int max(int a,int b)
{
	int z;
	z = a > b ? a:b;
	return z;
}
int main(void)
{
	int a,b,c;
	printf("请输入两个整数:");
	scanf("%d %d",&a,&b);
	c=max(a,b);
	printf("大的那个数是:%d\n",c);
	return 0;	
}
