#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "seqlist.h"
#define NAMESIZE 32
struct stu_st{
	char name[NAMESIZE];
	int age;
};
static int Intcmp(const void *date ,const void *key)
{
	const struct stu_st *d = date;
	const int  *k = key;
	return d->age - *k;
}


static int namecmp(const void *date ,const void *key)
{
	const struct stu_st *d = date;
	const char *k = key;
	return strcmp(d->name , k);
}


static int agecmp(const void *date ,const void *newdate)
{
	const struct stu_st *d = date;
	const struct stu_st *new = newdate;
	return new->age - d->age;
}
static void showstu(const void *date)
{
	const struct stu_st *d = date;
	printf ("%s %d  ",d->name,d->age);
}
int main(void)
{
	seqlist_t *mylist;
//	struct stu_st *f;
	struct stu_st s;
  //  char *delname;
	mylist = seqlistInit(sizeof(struct stu_st));

	srand(getpid());
	for (int i = 0 ; i<20 ;i+=2){
		s.age= 20 + rand() % 10;
		snprintf(s.name,NAMESIZE,"stu%d",i);
		seqlistInsert(mylist,&s);
//有错  seqlistSortInsert(mylist, &s.age ,agecmp);
//		printf("111111111111111\n")	;
	}

	seqlistTravel(mylist , showstu);
	printf ("\n");
/*	int i = 22;
	//查找
	f=(seqlistFind(mylist,&i,Intcmp));
	if(f=NULL)
		printf("没有值为%d的数\n",i);
	else
		printf("找到了%s\n",f->name);

	//删除
	delname = "stu16";
	seqlistDelete(mylist ,delname ,namecmp);
	printf("删除后：\n");
	
	seqlistTravel(mylist , showstu);
	printf ("\n");
	//修改
	/*    int a=28;
		  int b=15;
		  seqlistUpdate(mylist,&a,Intcmp,&b);
		  printf("修改后:\n");
		  seqlistTravel(mylist , showstu);
		  printf ("\n");*/
	//销毁*/
//	seqlistDestroy(mylist);
//	seqlistTravel(mylist , showstu);
	return 0;
}
