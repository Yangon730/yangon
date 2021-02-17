//const 
/*
 常量指针
 指针常量
 */
#include <stdio.h>
int main()
{
	char str[] = "hello everyone";
   	const char *p =str;//	常量的指针   read--only *p
	char const *m =str; //同上
	char *const q = str; //指针的常量  read --only  q
	
	str[0] = 'm';
	puts(str);
//	*p = 'm';
	*q = 'l';
	puts(str);
	//q++;	
	 p++;
	return 0;

}
