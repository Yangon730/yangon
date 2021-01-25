//99乘法表
#include <stdio.h>
int main (void)
{
	int i ,b ,a;
	for(i=1;i<10;i++){
		for(a=1;a<i;a++)
			printf("        ");
			for(b=a;b<10;b++){
				printf("%dx%d=%2d  ",a,b,a*b);
			}
			printf("\n");
	}


	return 0;
}
#if 0
#include <stdio.h>
int main (void)
{   
	int year,month,day;
	int sumdays=0;
	printf("请输入年月日：");
	scanf("%d,%d,%d",&year,&month,&day);
	for(int i = 1;i < month ; i++){
  		if( i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || \
		 i == 10 || i == 12 )
			sumdays += 31;
		else if( i == 4 || i == 6 || i == 9 || i == 11 )
			sumdays += 30;
        else if( i==2 ){
		     if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				 sumdays += 29;
			 else
				 sumdays += 28;
		}
	}
    sumdays= sumdays + day;
	printf("这是这一年的%d天。\n",sumday);
	return 0;
}
#endif
