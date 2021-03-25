#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf  env;

int sum2num(int a,int b)
{
	int c;
	if( b == 0)
		longjmp(env,1);	//跳转到输入位置
	printf("%d\n",c);
	return a / b;
}

int main(void)
{
	int m, n ;
	if(setjmp(env) == 0){
		printf("请输入两个整型数:\n");
	}else{
		printf("请重新输入:\n");
	}
	scanf("%d %d",&m , &n);
	printf("%d\n" , sum2num(m,n));

	exit(0);
}
