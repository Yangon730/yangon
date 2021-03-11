#include <stdio.h>
#include "lqueue.h"

int main(void)
{
	queue_t *me;
	int n;

	queueInit(sizeof(int),10,&me);//初始化

     for(int i = 1; i<100;i++)
	 {
	 	if(enq(me,&i) != 0 )
			break;
	 }
	 
	 while(!queueEmpty(me))
	 {
	 	deq(me,&n);
		printf("%-4d",n);
	 }

	 queueDestory(me);
	 return 0;



}
