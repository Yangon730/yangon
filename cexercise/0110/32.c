#include <stdio.h>
int main(void)
{
	int a,b,sum ,x;

	for(a=1;a<10;a++){
	 for(b=0;b<10;b++){ 
	    for(x=31;x<100;x++){
		sum =  a * 1000 + a * 100 + b * 10 + b;
        if(sum == x*x)
	     	printf("车牌号是%d\n",x*x);
	   }		
	  }
	 }	

   	return 0;
}
