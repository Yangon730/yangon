#include <stdio.h>
char *str_cpy(char *a ,char *b)
{
	int i;
	for (i = 0 ; a[i] != '\0' ;i++ ){
		b[i] = a[i];
	}
	b[i] = '\0';
	return b;
}
int main(  )
{
	char str[] = "good moring";
	char str2[] = {};
	str_cpy(str,str2);
	puts(str2);
	return 0;
}
