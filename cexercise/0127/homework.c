#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *addnumber(int *p ,int b)
{
  	int *res = NULL;
	int i;
	size_t size ;
	size = strlen(*p)+1;
    res = calloc(size+1 ,sizeof(int) );
    







}
int main(void)
{
	int  *ret;
	int n , i ,a;
	printf("输入数组的元素个数:\n");
	scanf("%d",&n);
    ret = malloc(sizeof(char)*n);	
	for(i = 0 ; i < n ;i++){
	printf("输入数: \n ");
	scanf("%d",& a);
    ret[i] = a;
	}

	printf("请输入要添加的数:\n");

	return 0;
}
