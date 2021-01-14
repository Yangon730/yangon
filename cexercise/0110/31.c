//500换钞票：
#include <stdio.h>
int main(void)
{
	int a,b,c,d;
	int i=0;

	for(a=1;a<11;a++){
	   for(b=1;b<26;b++){
	      for(c=1;c<50;c++){
		     for(d=1;d<100;d++){
			    if(50 * a + 25 * b + 10 * c + 5 * d == 500){
				  printf( "50需要%d张，20需要%d张，10需要%d张，\
						  5需要%d张，一共%d张。\n",a,b,c,d,a+b+c+d);
				  i++;   
				}
			 }
		  }
	   }
	}
    printf("一共有%d种方法\n",i);
	return 0;
}
