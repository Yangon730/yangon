#include <stdio.h>

#include "linkdelist.h"
static int  cmpdel(const void *date ,const void *key)
{
	const int *a = date;
    const int *b = key;
	return *a -*b;

}
static void showInt(const void *date)
{
	const int *d = date;

	printf("  %d  ",*d);
}

int main(void)
{   int key = 5 ;
	int k = 9;
	int w = 4;
	int arr[]={3,2,6,4,8,7,9,5};
	listhead_t *head;
	listheadInit(sizeof(int),&head);
	for(int i = 0 ;i < sizeof(arr)/sizeof(*arr);i++)
	{
		listheadInsert(head ,arr+i ,HEADINSERT);
	}
	listTraval(head,showInt);
	printf("\n删除后：\n");
	
    listDelete(head,&key,cmpdel);
	listTraval(head,showInt);
   	printf("\n修改后:\n");
	listupdate(head , &k ,cmpdel ,&w);

	listTraval(head,showInt);
	printf("\n");
	listDestory(head);
	
	return 0;
}

