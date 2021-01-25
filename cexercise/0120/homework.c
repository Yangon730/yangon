//1. 随机产生一个由10个整型元素组成的数组，将数组元素从小到大排序
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 
#define N  10
#define SWA(x,y)\
	do{\
		typeof(x) t ;\
		t = x;  x = y ; y = t ; \
	}while(0)
int main(void)
{
	int arr[N];
	int i,j  ;
	int max , min ;

	srand(getpid());
	for(i=0;i<N;i++)
	{
		arr[i]=rand()%100;
		printf("%d ",arr[i]);
	}
	printf("\n");
	//选择排序
/*	for( i = 0; i<N-1 ; i++ ){
		max = i;
		for(int j=i+1;j<N;j++ ){
			if( arr[j] > arr[max] )
				max = j;
		}
		if(max != i)
			SWA(arr[max],arr[i]);
	}*/
	//直接插入排序
	for(i = 1 ;i < N ; i++){
		min = arr[i];
		for(j =i-1 ; j >= 0 ; j--){
			if(min < arr[j])
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1]=min;
	}
	for( i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}




