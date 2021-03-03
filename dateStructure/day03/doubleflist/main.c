#include <stdio.h>

#include "dflist.h"

static void showInt(const void *data)
{
	const int *d = data;

	printf("  %d  ",*d);
}
static int  cmpInt(const void *data ,const void*key)
{
	const int *a =key;
	const int *b =data;
	
	return *a - *b;
}

int main()
{
	int arr[]= { 1 , 5 , 4 , 8 ,7 ,6 ,9};
	int key = 8;
	int t = 7;
	
	listhead_t *head; 

    dflistheadINit(sizeof(int),&head);

	for(int i = 0 ; i<sizeof(arr)/sizeof(*arr);i++){
		dflistInsert(head,arr+i,LASTLIST);
	}

	dflistTaval(head ,showInt);
	printf("\n删除后\n");

	dflistdel(head, &key,cmpInt);
	dflistTaval(head ,showInt);
	
	printf("\n摘除的数%d\n",*(int *)dflistFetch(head,&t,cmpInt));
	
	printf("摘除后\n");
	dflistTaval(head ,showInt);
	printf("\n");

	if(dflistIsEmpty(head))
		printf("非空\n");
	else
		printf("空\n");
	dflistDestroy(head);
//	dflistTaval(head ,showInt);	
	return 0;
}
