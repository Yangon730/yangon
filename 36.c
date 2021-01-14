#include <stdio.h>
int main(void)
{
 	int g , m , x;
	
	for(g=0;g<34;g++){
	   for(m=0;m<51;m++){
	      for(x=0;x<300;x++){
		     if( g + m + x == 100 && 3*g + 2*m + 1/3*x == 100 \
					 &&  x % 3 == 0){
			 	printf("🐓%d只,母鸡%d只,小鸡%d只。\n",g,m,x);	
			 }
		  }
	   }
	}

	return 0;
}
