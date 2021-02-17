/*定义一个接口函数，功能是返回一个能容纳10个整型元素的数组，
再定义一个能向数组里插入新元素和一个能遍历数组的函数*/\
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  N  10
int *array()
{
	static  int  p[N] = {0};
	return p;
}
int *arraytow(int *p , int m)
{
	for (int j = 0 ; j < N ; j++)
	{
		p[j] = m;
		break;
	}
	return p;
}
int seearray(int *p)
{
	for(int i = 0 ; i<N ; i++)
	{
		printf(" %d ",p[i] );
	}
    printf("\n");
}
int main(void)
{
	int *arr;
	int m;
	arr = array();
	printf("请输入要插入的数:\n");
	scanf("%d",&m);
	arr = arraytow(arr,m);
	seearray(arr);
	return 0;
}

