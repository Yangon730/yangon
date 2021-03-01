/*结构体中存储自动按顺序最大空间补全*/

#include <stdio.h>
typedef struct usernum{
    char var1;
	int  var2;
	char var3;
}test1;
typedef struct hsjds{
 	char var;
	int var1 ; // int  之后 long，前面char 为四
    long var3;
	char var2;
}test;
int func(int x);
int main()

{
	int y =9998;
	printf("%ld\n",sizeof(test1));
	printf("%ld\n",sizeof(test));
    int num = func(y);
	printf("%d\n",num);
	return 0;
}
int func(int x)
{
	int countx=0 ; 
	while(x)
	{
		countx++;
		x= x&(x-1);
		printf("%d\n",x);
		break;
	}	
	return countx;
}
