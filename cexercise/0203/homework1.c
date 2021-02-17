//有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中
#include <stdio.h>

int main(void)
{
	int arr[6]={1,3,5,7,9};
	int num , min ;
	int i ,j;
	printf("原来的数组: \n");
	for(  i = 0 ; i < 5 ; i++){
		printf(" %d ",arr[i]);
	}
	printf("\n");
	printf("请输入要插入的整型:\n");
	scanf("%d",&num);
    arr[5] = num ;
	for( i = 1 ; i < 6; i++ )
	{
		min = arr[i];
		for( j = i-1 ; j >= 0 ;j--)
		if(min < arr[j])
		{
			arr[j+1] = arr[j];
		}
		else
			break;
		arr[j+1]= min;
	}
	
	for( i=0;i < 6;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
/*
   int *sortingfun (int *p , num);
   {
   int *




   }*/
