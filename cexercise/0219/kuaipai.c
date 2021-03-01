//快排，找标兵
#include <stdio,h>
int main(void)
{


	return ;
}
static swap(int *arr ,int oneindex ,int twoindex)
{
	int t;
    t = arr[oneindex] ;
	arr[oneindex]= arr[twoindex];
	arr[twoindex] = t; 
}
/*1.找标兵，确定位置
 2.分区*/
int partition(int *arr, int low, int high)
{
	int k ;
	k = arr[low];
	while(low<hight)
	{
		while(arr[high] <= k && low < high)
			high--;

		if(low < high)//high 下标元素小于标兵
		{
			swap(arr,low,high);
		
		}
	    while(arr[low] >= k&& low < high)
			low++;
		if(low >= hight)
			break;
		swape(arr ,low ,high);
	}
	arr[low] = k;
	
	}



}
