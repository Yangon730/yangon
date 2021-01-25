/*4. 一个2000以内的整型数，它+100后是一个完全平方数,再加上168又是一个完全平方数,请问该数为多少*/
/*#include <stdio.h>
#include <math.h>
int main(void)
{ 
	double num,num1 ;
	for(int i=1;i<2000;i++){
	 num = sqrt (i+100);
	 num1= sqrt(i+268);
	 if(num == (int)num && num1 == (int)num1){
	 printf("%d\n",i);
	}
	}
	return 0;
 //1. 从键盘输入年号和月号，求这一年的这一月共有多少天。
#include <stdio.h>
int main(void)
{
	int year,month,day,days;
	printf("请输入年月日：\n");
	scanf("%d/%d/%d",&year,&month,&day);
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8\
		   ||month == 10 || month == 12)
		    days = 31;
	else if	 
		(month == 4 || month == 6 || month == 9 || month == 11)
			days =30;
    else if(year % 4 == 0 && year % 100 != 0 || year % 400 ==0)
		    days = 29;
	   else days =28;
    printf("%d\n",days);	   
	return 0;
}
//2. 求某一范围内完数的个数。
如果一个数等于它的因子(因子就是所有可以整除这个数的数)之和，则称该数为“完数”（或“完全数”)。例如，6的因子为1、2、3，而 6=1+2+3，因此6是“完数”。
范围由用户输入，例如输入100就是求100内由多少个完数*/
#include <stdio.h>
int main(void)
{
   int num,i, j;
   int sum=0 ,a=0;
   printf("请输入一个整型：");
   scanf("%d",&num);
   for(i=1;i<num;i++)
   {   
	   sum = 0;
	   for(j=1;j<i;j++){
	   if(i % j == 0){
     	sum=j+sum;}
		}
       if(sum == i){
        a++;
		printf("%d是一个完数\n",i);
	 }
   }
  
	printf("%d中有%d个完数\n",num,a);
	return 0;
}	























