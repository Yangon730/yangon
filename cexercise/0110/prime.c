#include  <stdio.h>
int main(void)
{ 
	int prime,i;
	int m=0;
   	for(prime=100;prime<301;prime++){	
    for(i=2;i<prime;i++ ){
     if (prime%i==0)
	      break;
   }
	if(prime==i)
		m++;
	}
	printf("%d",m);
	
	return 0;
}
