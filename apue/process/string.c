#include <stdio.h>
#include <string.h>

static char *sum(char *src ,char *dest);
int main()
{
	char src[] = "helloword";
	char dest[] = "";
	puts(sum(src,dest));

	return 0;
}

static char *sum(char *src ,char *dest)
{
	int i;
	for (i = 0; src[i] != '\0'; i++){
		dest[i] = src[i];
	
	}
	dest[i] = '\0';

	return dest;
}
