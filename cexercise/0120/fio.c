#include <stdio.h>
int issum (int n);
int main (void)
{
	int sum ;
	for(int i=1 ;i< 20 ;i++)
		sum=issum(i);
	return 0;
}
int issum (int n)
{

   return issum(n-1)+issum(n);
}

