#include<stdio.h>
int  isperyear(int y);
int monthdays (int m,int y);
int main(void)
{
	int year,month,day;
	int sumdays = 0;
	printf("请输入年/月/日：");
	scanf("%d/%d/%d",&year,&month,&day);

	sumdays = monthdays(month,year)+day;
	printf("这是这一年的%d天。\n",sumdays);

	return 0;
}
int  isperyear(int y)
{
	if( y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
	  return 1;
	}
	  return 0;
}
int monthdays (int m,int y)
{
   	int sum = 0;
	for(int i=1; i<m;i++ ){
	if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 \
			|| i == 10 || i == 12)
		sum += 31;
	else if(i == 4 || i == 6 || i == 9 || i == 11)
		sum += 30;
    else if(isperyear(y))
		     sum += 29;
		 else
			 sum += 28;
	}
    return sum;
} 
