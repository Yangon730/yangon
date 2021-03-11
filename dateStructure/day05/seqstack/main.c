#include <stdio.h>

#include "seqstack.h"

int main(void)
{
	stack_t *mystack;
	int p;

	stackInit(sizeof(int), 10, &mystack);

	for(int i=1 ; i<100;i++){
	  if(stackpush(mystack , &i) != 0 )
		  break;
	}
	while(!stackisEmtpy(mystack)){
		stackpop(mystack,&p);
		printf("%d\n",p);
	}
    printf ("******************************");
	stackDstory(mystack);

	return 0;
}
