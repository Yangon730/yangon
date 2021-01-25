//定义一个函数，求得斐波那契数列第n项
#include<stdio.h>
int isfibo(int n);
int main(void)
{
	int n;
	printf("请输入一个n：");
	scanf("%d",&n);
	printf("%d\n", isfibo(n));
	return 0;
}	
int isfibo(int n)
{
    if (n == 1 || n == 2) {
		return 1;
	}
	return isfibo(n - 2) + isfibo(n - 1);
}
