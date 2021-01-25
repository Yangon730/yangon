//回文数
#include <stdio.h>
int isreverse(int n);
int istimes(int t);
int main(void)
{
	int num ,j;
	int sum ,i ;
	printf("请输入一个整型数：");
	scanf("%d",&num);

	for(i=0;i<7;i++)
	{
		if(istimes(num))
		{
			printf("经过%d次计算得到回文数%d.\n",i,num);
			break;
		}
		j= isreverse(num);
		sum=num + j;
		printf("%d+%d=%d\n",num,j,sum);
		num = sum ;
	}
	if(i == 7)
		printf("经过7次没有得到回文数。\n");
	return 0;
}
int isreverse(int n)
{
	int nu=0;
	while(n>0)
	{
		nu=nu*10+n%10;
		n/=10;
	}
	return nu;
}
int istimes(int t)
{
	if(t == isreverse(t))
		return 1;

	return 0;
}
