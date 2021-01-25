//定义一个能存储10个学生成绩的数组，打印成绩分布
#include <stdio.h>
int isplay(int x);
#define TEN 10
#define ELE 11
int main()
{
	int a[TEN],count[ELE];
	int n ;

	for(int i=0;i<ELE;i++)
		count[i] = 0;
	for(int i=0;i<TEN;i++)
	{ 
		printf("请输入第%d个学生的成绩：",i+1);
		scanf("%d",&a[i]);
	
	switch(a[i]/10)
	{
		case 10: count[10]++;break;
		case  9: count[9]++;break;
		case  8: count[8]++;break;
		case  7: count[7]++;break;
		case  6: count[6]++;break;
		case  5: count[5]++;break;
		case  4: count[4]++;break;
		case  3: count[3]++;break;
		case  2: count[2]++;break;
		case  1: count[1]++;break;
		case  0: count[0]++;break;
	}
	}

	printf("100: ");
	isplay(count[TEN]);
	printf("\n");
	for(int i = TEN; i>0;i--)
	{
		printf("%d0~%d9: ",i-1,i-1);
		isplay(count[i]);
		printf("\n");
	}
	return 0;
}
int isplay(int x)
{
	for(int i = x ;i>0;i--)
		printf("*");

}














