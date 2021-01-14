#include <stdio.h>
int main(void)
{
 int var;
 printf("请输入一个整数：\n");
 scanf("%d",&var);
   if (var==0 )
   { printf("%d它非奇非偶数\n",var);}
   else if( var%2==0)
   { printf("%d它是一个偶数\n",var);}
   else
   {printf("%d它是一个奇数\n",var);} 
   printf("请输入一个整数：\n");
 scanf("%d",&var); 
}
