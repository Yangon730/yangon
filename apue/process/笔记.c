#include<stdio.h>
#include<stdlib.h>

int quanju = 1; //全局变量，存初始化数据段（.data）
int quanju2; //全局变量，未初始化，存未初始化数据段（bss），bss段数据都为0，所以实际上quanju2被初始化为0了，称为非显式初始化，上边的是显式初始化
//.data bss 都是数据段，区别只在初始化
int main()
{
	int jubu; //局部变量，存栈，（还存函数返回值，函数参数）；

	int *dui = malloc(sizeof(int)); //开空间(还有calloc，realloc)， 存堆

	static int jintai;//静态变量，存数据段,初始化存.data, 未初始化存dss

	/*动态库生成：gcc -fPIC -shared -o(设置生成文件的名，这里用来设置动态库名) lib动态库名.so  需封装的.c 文件
	  例：gcc -fPIC -shared -o libmystack.so asdfggh.c 
	  动态库在需要的时候再连接，静态库直接把库里函数全编译到可执行文件，文件大，不用连接
	 动态库需要设置路径，系统先在本目录里找，找不到去～/.bashrc里找（新动态库路径存这里边vim ~/.bashrc,存完还得source ～/.bashrc,不然存不上）。
	 动态库链接：gcc 用到了库的某文件.c -l库名 （例：-lmystack）-L路径
	 例：gcc asdf.c -lmystack -L./
	 */
}
