#include <stdio.h>
int main(void)
{ 
	int y , m ,d ,i;
	int sum=0;
	printf("请输入年/月/日：");
	scanf("%d/%d/%d",&y,&m,&d);
	if(d > 31 || m > 12 ||d < 0 || m < 0 || y <0)
		printf("此日期不合法");
	
	
	{
    for(i=1;i<m;i++)
		if(i ==  1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		sum +=31;
		else if( i == 4 || i == 6 || i == 9 || i == 11)
			sum+=30;
	    else
			if(y%4==0&&y%100!=0||y%400==0)
			    sum+=29;
			else 
				sum+=28;
	}
	sum+=d;
	printf("%d/%d/%d是这一年的%d天。\n",y,m,d,sum);	
	return 0;
}












