#include <stdio.h>
/*
 指针的作用：
 通过形参改变实参-------》指针
 

 */
int MaxMinarr(int *arr,int n ,int *min );
void swap2num(int *a,int *b);
int main(void)
{
	int num1,num2;
	int str[]={1,5,4,2,8,6,9,7};
	int max ,min;

	num1 = 50 ;
	num2 = 100;

	swap2num(&num1,&num2);
	printf("num1:%d,num2:%d\n",num1,num2);
	max = MaxMinarr(str ,sizeof(str)/sizeof(*str),&min);
	printf("最大值是：%d,最小值是：%d\n",max,min);
	return 0;
}
//两个整型数交换//
void swap2num(int *a,int *b)
{
	int t; 

	t = *a;
	*a = *b;
	*b = t ;

}
//输出最大最小值//
int MaxMinarr(int *arr,int n ,int *min )
{
	int i;
	int maxn ,minn;
	maxn = minn =arr[0];

	for(i=1;i<n;i++)
	{
		if(arr[i]>maxn)
			maxn = arr[i];
		if(arr[i]<minn)
			minn = arr[i];
	}
	*min = minn;
	return maxn;
	}



