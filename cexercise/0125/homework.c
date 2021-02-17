/*1、有一个字符串开头或结尾含有n个空格（”   abcdefgdddd    ”），欲去掉前后空格，返回一个新字符串。
要求：请自己定义一个接口（函数），并实现功能；*/
#include <stdio.h>

void isbackspace(char *a,int n ,char *b);
int main(void)
{
	char str[] = "   abcdefgdddd    ";
    char strr[] ={};
	
	isbackspace(str ,sizeof(str)/sizeof(*str),strr );
    puts(strr);
	return 0;
}
//去空格接口函数
void isbackspace(char *a,int n ,char *b)
{
	int i,j ;
	char ::
	for( i = 0;i < n ; i++)
	{
		for( j = 0 ; j < n ; j++  ){
			{
				if(a[i] != ' '){
					 m = a[i];
				}
				return b[j];
			}
	}
	}
	
}


























/*2、有一个字符串”1a2b3d4z”,；
要求写一个函数实现如下功能，
功能1：把偶数位字符挑选出来，组成一个字符串1。
功能2：把奇数位字符挑选出来，组成一个字符串2，
功能3：把字符串1和字符串2拼接组成一个新的字符串，返回。*/
/*3、c语言中有一个函数strchr(3)的功能是在字符串中找指定的字符，尝试自己定义一个函数实现其功能*/
/*4、c语言中有一个函数strstr(3)的功能是在字符串中找子串，尝试自己定义一个函数实现其功能*/
/*5、数学中有个杨辉三角的概念，打印杨辉三角的前10行*/

