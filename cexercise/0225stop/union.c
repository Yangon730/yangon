//共用体 ---->联合体
#include <stdio.h>
/*union test_un {
  int a;
  char b;
  };*/
int main()
{
	//union test_un t;
	//小端存储：低字节存储低地址，高字节存储高地址
	//大端存储：低字节存储高地址，高字节存储低地址
	int b = 0x12345678;
	int *a = &b;
	printf("%#x\n",*a);
	printf("%#x\n",*c);//16进制格式输出；
	return 0;
}
