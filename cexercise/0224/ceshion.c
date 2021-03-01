//字符串长度
#include <stdio.h>
int strcmp(const char *src,const char *dst)
{
	while(*src != '\0' && *dst != '\0')
		++src, ++dst;
	if(*src == *dst)
		return 0;
	else if(*src == '\0')
		return -1;
	else
		return 1;
}
int main()
{
	char arr[] = "hello";
	char str[] = "heakkbg";
	printf("%d\n",strcmp(arr,str));
	return 0;
}

