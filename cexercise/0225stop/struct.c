//结构体；
#include <stdio.h>
#include <string.h>
#define NAMESIZE  32
// 类型 struct stu_st  新建
struct stu_st{
	int age;
	char name[NAMESIZE];
	float score;
};
int main()
{
	struct stu_st *p; 
	struct stu_st arr[3];
	p=arr;
	for(int i = 0;i < 3; i++ )
	{
		arr[i].age=20+i;
		scanf("%s",arr[i].name);//读入
		//	snprintf(arr[i].name,NAMESIZE,"HELLO%d",i+1); 打印
		arr[i].score= 100 - i;
	}

	/*	printf("%d,%s,%f\n",stu2.age,stu2.name,stu2.score);

		stu.age = 19 ;
		strcpy(stu.name,"hello");//第三种
		stu.score = 10.9;
	 */	for(int i = 0 ;i< 3;i++){
		 printf("%d,%s,%f\n",arr[i].age , arr[i].name , arr[i].score); //第一种打印

		 printf("%d,%s,%f\n",(p+i)->age ,(p+i)->name ,(p+i)->score);//第二种打印
	 }
	 return 0;
}
