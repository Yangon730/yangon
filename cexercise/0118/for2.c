#include <stdio.h>
int main(void)
{
/*	int num,a,i ;
	int num2=0;
	printf("请输入一个整型数：");
   	scanf("%d",&num);	

   	for(i=0;;i++){
      if(num==0){
	  break;
	  }
	 a = num % 10;	
     num2 = num2*10+a;
	 num = num/10;
	}
	printf("%d\n",num2);*/
    int i,x,y,z;
	for(i=100;i<1000;i++){
	 x=i/100;  	
	 y=i/10%10;
	 z=i%10;
	if(i==x*x*x+y*y*y+z*z*z){
	printf("%d\n",i);
	
	}
		
	}

	return 0;
}
