/*
 字符串大写字母变小写，小写变大写
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *swapestring(const char *p);

int main (void)
{
	char *str = swapestring("abcdeFGHI");
	puts(str);

	free(str);
	str = NULL;

	return 0;
}
char *swapestring(const char *p)
{
	char *res;
	size_t size;
	int i;
	size = strlen(p)+1;

	res = malloc(size);
	if(res == NULL ){
		printf("开辟不成功\n");
		return NULL;
	}
	memset(res,0,size);

	for(i = 0; p[i] ; i++)
	{
		if(p[i]>='A' && p[i]<='Z'){
			res[i]=p[i]+('a' - 'A');
		}
		if(p[i] <= 'z'&& p[i] >= 'a')
			res[i]=p[i]-('a' - 'A');
	}
	return res;
}
