//字符串插入
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void insert(char *s, char *t, int i);
int main()
{
	char arr[]="helloword";
	char str[]= "nihao";
    int h = 6;
	insert(arr,str,h);
	puts(arr);
	return 0;
}
void insert(char *s, char *t, int i)
{
	int len = strlen(s);
	int leno = strlen(t);
	char *p = s;
	char *q = (char *)calloc(len–i+1,sizeof(char));
	memcpy(q ,s+i ,len - i);
	memcpy(p,s,i);
	memcpy(p+i,t,leno);
	memcpy(p+i+leno,q ,len-i) ;

}

