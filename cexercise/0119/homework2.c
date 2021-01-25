//判断给定的整型数是否是素数
#include<stdio.h>
int isprime(int n);
int main(void)
{
	int num;
	printf("请输入一个整型：");
	scanf("%d",&num);
	
	if(isprime(num)){
		printf("%d是一个素数\n",num);
	}  
	else{
		printf("%d不是一个素数\n",num);
	}
	return 0;
}
int isprime(int n)
{
	for(int i = 2 ; i < n ;i++){
		if(n % i == 0){
		   return 0 ;
		}
	    if(i == n)
		   return 1 ;
	}
}

