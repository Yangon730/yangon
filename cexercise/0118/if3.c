#include <stdio.h>
int main(void)
{
	int per,n ;
	int i=0;
	while(i<10){
	printf("请输入一个成绩:\n");
	scanf("%d",&per);
	if(per<0||per>100){
	printf("成绩无效\n");
	continue;
	
	}
	{
  	n = per/ 10;

	switch (n){
	
	case 9 :printf("A\n");
		break;
	case 8 :printf("B\n");
		break;
	
	case 7 :printf("C\n");
		break;
	
	case 6 :printf("D\n");
		break;
	
	default :printf("E\n");
		break;


	}	
	
	}
	i++;
	}
	return 0;
}
