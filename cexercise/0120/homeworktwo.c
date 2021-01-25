//41个人编好号(1~41)围成一圈，从1号开始数数，数到3则退出游戏，下一个人再从1开始数....最后留下的那个人是几号。
#include <stdio.h>
#define NUM 41
int main(void)
{
	int arr[NUM];
	int id=0,sum =NUM ,count=0;
	for(int j = 0 ; j < NUM;j++)
		arr[j]=1;
	while(sum)
	{
		id++;
		if(id == NUM +1)
			id = 1;
		count += arr[id-1];
		if(count == 3)
		{
			arr[id-1] = count = 0; 
			sum -- ;
		}
	
	}

	printf("最后留下的是第%d人\n",id);
	return 0;
}

