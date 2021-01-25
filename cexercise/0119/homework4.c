//求得两个整型数的最大公约数
#include <stdio.h>
int iscommon(int x,int y);
int iscommon2(int x,int y);
int main(void)
{
	int nun ,nu, num ;
	printf("请输入两个整型数n/j：\n");
	scanf("%d/%d",&nu ,&nun);

	num= iscommon2(nu ,nun);
	printf("这两个数的最大公约数是%d\n",num);

	return 0;
}
int iscommon(int x,int y)
{
	int t ;
	if(y<x)
	{
		t = y;
		y = x;
		x = t;
	}
	for(int i=x;i>0;i-- )
	{
		if(x % i == 0 && y % i == 0)
		{
			return i;
		}
	}
}
int iscommon2(int x,int y)
{
	int t;
	if(y<x)
	{
		t = y;
		y = x;
		x = t;
	}
	while(1)
	{
		t = y % x;
		if(t == 0)
			return x;
		y=x;
		x=t;
	}
}
