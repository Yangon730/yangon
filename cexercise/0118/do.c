#include <stdio.h>
int main(void)
{
	int a=0;
 /*	do{
		printf("请输入一个整型：");
		scanf("%d",&a);
	}while(a<=0||a>=100);

	printf("%d",a);*/
LOOP:
	if(a<10){
	printf("%d",a);
	a++;
	
    goto LOOP;
	}


	return 0;
}
