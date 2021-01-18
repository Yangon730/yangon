#include <stdio.h>
int main(void)
{
	int per,n;
	printf("请输入一个成绩:\n");
	scanf("%d",&per);
	if(per<0||per>100){
	printf("成绩无效\n");
	}
  	n = per % 10;

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
	return 0;
}
