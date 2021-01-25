//读入10个整型变量，求得十个数中所有的素数打印输出  
#include <stdio.h>

int isprime(int x);
#define NUM 10
int main(void)
{
	int arr[NUM];
	for(int i=0;i<NUM;i++)
	{
		printf("请输入第%d个整型：",i+1);
		scanf("%d",&arr[i]);
		arr[i] *= isprime(arr[i]);
	}
	for(int j= 0 ;j < NUM ; j++)
		if(arr[j])
			printf("%d\n",arr[j]);

	return 0;
}
int isprime(int x)
{
	int i;
	if(x==1)
		return 1;
	else
	{
		for(i=2;i<=x;i++)
		{
			if(x % i == 0)
				break;
		}
		if(i == x)
			return 1;
		else
			return 0;

	}
}
