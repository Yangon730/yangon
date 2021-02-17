#include <stdio.h>
int main(void)
{
	char str[]="hello world";
	char *p =str;//变量p ，类型是char *
	int arr[5]= {1,2,3,4,5};
   	int *q = arr ;
	
	printf("char *:%ld\n",sizeof(p));	

	printf("%p\n",p);
	printf("%p\n",p+1);//char *指针加1 ----》sizeof（char）
	while(*p){
		printf("%c",*p);
		p++;
	}
	printf("\n");

	printf("int *:%ld\n",sizeof(q));
	printf("%p\n",q);
	printf("%p\n",q+1);
	printf("%d\n",*q);

	return 0;
}
