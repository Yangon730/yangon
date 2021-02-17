#include <stdio.h>
int main (void)
{
	char str[]="good moring";
	char *p = str;

	printf("%c\n",*p++); //g
	printf("%c\n",(*p)++);// o   o++ = p ;  "gpod moring"
	printf("%c\n",*(p++));// p   还是取第二个
	printf("%c\n",*++p);//d
	printf("%c\n",++*p); //e

	return 0;
}
