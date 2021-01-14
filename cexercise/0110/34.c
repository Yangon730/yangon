//完全平方数

#include <stdio.h>
int main(void)
{
	int b , a;
    printf("这些完全平方数分别是\n");
	for(a=100;a<201;a++){
	   for(b=10;b<15;b++){
	    if(b*b==a){

	      printf("%d,",a);
	   }
	 }
	}
	printf("\n");
	return 0;
}
