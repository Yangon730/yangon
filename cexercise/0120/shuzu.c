//定义数组随机产生，交换最大最小
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define N   10
int main(void)
{
	int arr[N] = {};//定义
	int i ;
	int max ,min;
	//srand(time(NULL));
	srand(getpid());
	//赋值
	for(i = 0;i < N;i++)
	{
		arr[i] =rand()%100;
		printf("%d ",arr[10]);
		}
	printf("\n");
	//遍历
	max = min = 0;
	for (i = 1; i < N; i++) {
		if (arr[i] > arr[max]) {
			max = i; 
		}
		if (arr[i] < arr[min])
			min = i;
	}
	i = arr[max];
	arr[max] = arr[min];
	arr[min] = i;

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
