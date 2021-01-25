#include <stdio.h>
int main(void)
{
	int i; 
 	for(i=1;i<11;i++){
	 if(i==5){	  
      printf("小明肚子疼了！\n");
	  break;
	  }
		 printf("这是第%d次运球。\n",i);
	}

	int a,n;
    int sum=0;
	scanf("%d",&n);
	for(a=1;a<n+1;a++){
     if(a%2 == 0){
	  continue;
	 }
    sum=i+sum;
    printf("%d+",a);
	}
    printf("\b=%d",sum);
	return 0;
}
