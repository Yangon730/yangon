#include <stdio.h>
int main(void)
{
    int year;
  
    printf("请输入一个年份：\n");
    scanf("%d",&year);

    if(year%400 == 0)
    printf("这是闰年。\n");
    else if(year%4 == 0&&year%100 != 0)
    printf("这是闰年。\n");
    else printf("这不是闰年。\n");
    return 0;
}
