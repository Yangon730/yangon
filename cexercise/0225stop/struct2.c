/*定义一个动物结构体包括 月龄颜色名字
  接口函数 ，求出结构体年龄最大的动物*/
#include <stdio.h>
#include <string.h>
#define NAMESIZE  5
struct anmial{
	char color[NAMESIZE];
	char name[NAMESIZE];
	int  month;
};
int maxmonth(struct anmial *p);
int main()
{
	int max;
	struct anmial arr[3]; 
	struct anmial *q= arr; 
    printf("请输入颜色名字月龄:\n");
	for(int i=0; i < 3 ; i++  ){
		scanf("%s%s%d",arr[i].color,arr[i].name,&arr[i].month);
	}
	for(int i = 0; i<3; i++){
    	printf("%s,%s,%d\n",arr[i].color,arr[i].name,arr[i].month);
	}
    max =  maxmonth(q);
    printf("%s,%s,%d\n",arr[max].color,arr[max].name,arr[max].month);
	return 0;
}
int maxmonth(struct anmial *p)
{ 
	int i , n=0;

	for( i = 0 ;i<3; i++){
		if(p[i].month>p[n].month )
			n=i;
	}
	return n;
}
