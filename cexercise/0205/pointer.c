//指针复习
/*
#include <stdio.h>
char *mystrcpy(char *dest ,char *str)
{
	int i;
	for(i = 0 ;str[i];*//*str[i] != '\0' *//* i++ ){
		dest[i] = str [i];
	}
	dest[i]='\0';
	return dest;
}
int main(void)
{
	char str1[12]="hello word";
	mystrcpy(str1,"henan");
	printf("%s\n",str1);

	return 0;
}
*/
//int *p  p称为指针  int * 的变量
/*
#include  <stdio.h>
int main(void)
{
	char str[] = "hello word";
	char *p = str;
	int arr[] = {1,2,3,4,5,6};
	int *q = arr ;
   	printf("%ld\n",sizeof(p));	
    
	printf("%p\n",p);//%p打印地址
	printf("%p\n",p+1); // char *指针加1------sizeof(char)
 	
	while(*p){//遍历
		printf("%c", *p); //> p --->char *   (*p) -->取一个字节
		p++;
	}
	printf("\n");

   	printf("%ld\n",sizeof(q));	
	printf("%p\n",q);
	printf("%p\n",q+1);
	printf("%d\n",*q);
	return 0;
}
*/
/*
	指针的作用：
	1.通过形参改变实参---》指针




//两个整型数的交换
#include <stdio.h>
int swapetnum(int *a, int *b)
{ 
	int t;
	t  = *a; // t = num1;
	*a = *b;  // nun1 = num2;
    *b = t; // num2 = t;
}
//将给定数组的最大最小值返回 
//  参数的回填
int maxminarr(int *arr ,int n ,int *min)//只有指针变量可以存地址
{
	int i;
	int minn , maxn;
	minn = maxn =arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i] > maxn)
			maxn = arr[i];
		if(arr[i] < minn)
			minn = arr[i];
	}
	*min = minn;
	return maxn;
}
int main(void)
{
	int max ,min;
	int arr[] = {9,2,3,4,5,67,2};
	int	num1 = 100;
	int	num2 = 50;
	swapetnum(&num1 ,&num2);
	printf("%d , %d\n",num1 ,num2);
	max	= maxminarr(arr, sizeof(arr)/sizeof(*arr), &min);
	printf("最大值：%d,最小值%d \n",max,min);
	return 0;
}*/



/*
#include <stdio.h>
int mian(void)
{
 	// 指针只能存地址
	char str[] = "good morning";
	char *p = str;

	printf("%c\n",*p++);//'g'
	printf("%c\n",(*p)++);//'o'    "gpod ,morning"
	printf("%c\n",*(p++));//'p'    *p   p++
	printf("%c\n",*++p);//'d'
	printf("%c\n",++*p);//'e'     *p = d   d++ = e
	return 0; 
}
*/
//#include <stdio.h>
/*
   指针的常量
   常量的指针
 */
/*
int main()
{
	char str[] = "hello everyone";
	//指针指向的是常量（*p），指针所指向的地址空间内容是只读的
	const char *p =str ;//指针的常量  const 修饰的东西不一样 *p q----->read-only 
//	char  const *p = str; //同上
	char * const q =str ;//常量的指针
//	str[0] = 'm';
   // *p  = 'h'; //不成立
	*q = 'r'; 
	printf("%s\n",str);
    p++;
    //   q++;	//不成立
	return 0;
}*/
/*堆空间的使用     
  手册在第三章
	malloc(3)
	calloc(3)
	realloc(2)
	free(1)
void *万能指针类型
void *可以存储任意类型的变量地址，但没有步长，指针不能加减 + - 也不能取 *

memset(3);//存储空间的初始化
memcpy(3);//存储空间复制 memcpy(p,q,8)  从q的8个字节复制到p位置
重叠会覆盖  用memove

memmove(3);//同上  申请空间在复制

2.数组指针和指针数组
3.函数指针
*//*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *test(const char *p)
{*//*
//	char str[100] = {};
//	return str; //局部变量的生存周期仅限在本函数内
	char *ret = NULL;
	//char *new;
	size_t size ;
	size = strlen(p)+1;*/
/*	ret = malloc(size);
	//空间中的内容是随机的
	memset(ret , 0 , size);//把开辟的ret全部填为o
	ret = calloc(size,sizeof(char));//总字节：size x 1 char为一字节已经初始化为0；
	int i ,j; 
	i = j = 0;
	for(; p[i] ;i++)
	{
		if(p[i] != ' ')
		{
			ret[j] = p[i];
			j++;
		}
	}//不包括' '字符串长度j+'\0'1
	if(j+1<size)  //开辟的空间太大了
	{
	 ret = realloc(ret,j+1);//把ret变为j+1个字节；*/
	 //realloc(NULL,size) ------>malloc(size);
	 //realloc(ptr,0) -------->free(ptr);
	/*	new=malloc(j+1);
		strcpy(new,ret);
		free(ret);*/
/*	}
	return ret;
}
int main(void)
{
	char *str = "    hello word    ";
    char *ret = test(str); 
	printf("%s\n",ret);
	free(ret);
	ret = NULL;//重复释放free(NULL);   //形成良好习惯
	return 0;
}*/
//定义一个函数，将给定的字符串中的大写字母变为小写字母，小写变大写，返回
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *swapeabc(const char *p)
{
	int i;
	char *ret;
	size_t size;
	size = strlen(p+1);
	ret = calloc (size,sizeof(char));
	if(ret == NULL)
	{
		return NULL;
	}
	for(i=0 ; p[i]; i++)
	{
		if(p[i] >= 'a' &&p[i] <= 'z')
		{
			ret[i] = p[i] - ('a'- 'A');
		}
		if(p[i] >= 'A' && p[i] <= 'Z')
		{
			ret[i] = p[i] + ('a' - 'A');
		}
	}
	return ret;
}
int main(void)
{
	char *str = "abcdEFGH";
	char *res;
	res = swapeabc(str);
    puts(res);
	free(res);
	res = NULL;
}*/
//数组指针
/*
#include <stdio.h>
int main (void)
{
	int arr[2][3]= {1,2,3,4,5,6};
	
	//arr --- >arr[0] arr[1]
    //arr[]0 ----> {1,2,3}
	//arr ---- > &arr[0]------>int *[3]
	int (*p)[3] =arr;//数组指针   //一定要加(*p) []优先级高

	printf("%p\n",p);
	printf("%p\n",p+1);

	printf("%d\n",p[1][2]);
	return 0;
}*/
//指针数组
#include <stdio.h>
//int main(void)
	//main函数是有参数的
int main (int argc ,char **argv/*  *argc[]  */ )

{
#if 0
	char *arr[4] = {"hello" , "word" ,"good","aftertoon" };
	for(int i ; i < 4; i++ ){
		printf("%s\n",arr[i]);
	}
     // arr --char **  //二级指针
	char **p = arr ;//二级指针
#endif
	for (int i = 0; i < argc; i++){
	 	puts(argv[i]);
	}

}




























































