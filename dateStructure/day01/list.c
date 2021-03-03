#include <stdio.h>
#include <stdlib.h>
void haang(char **arr );
#define NUMb  10
int main()
{
	char *arr;
	haang(&arr);
	puts(arr);
	return 0;
}
void haang(char **arr )
{	
	*arr = calloc(NUMb,sizeof(char));
	*arr = "hello";
}
