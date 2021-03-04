#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int gArray[4] = {1,2};
	int *ptr = (int *)malloc(30);
	void *pv =malloc(10);

	printf(	" %ld ",sizeof(gArray));
	printf(	" %ld ",sizeof(ptr));
	printf(	" %ld ",sizeof(*ptr));
	printf(	" %ld\n ",sizeof(*pv));
	
	return 0;
}
