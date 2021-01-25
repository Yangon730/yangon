#include <stdio.h>
int isperfectNumber(int num);
int main(void)
{
	int ret;
	for(int i=1;i<2000;i++){
	ret=isperfectNumber(i);
	if(ret){
	printf("%d是一个完数。\n",i);
	}
	}
	return 0;
}


int isperfectNumber(int num)
{
	int sum=0;
	for(int i=1;i<num;i++){
		if(num%i == 0)
			sum+=i;
	}
	if(sum == num)
		return 1;
	else 
		return 0;
	
}
