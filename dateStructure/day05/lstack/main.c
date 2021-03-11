#include <stdio.h>
#include <dflist.h>
#include "lstack.h"
int main()
{
	lstack_t *me;
	int n;

	lstackinit(sizeof(int),&me);

	for(int i =1 ;i<10;i++){
		lstackpush(me,&i);
	}
	while(!lstackisEmpty(me)){
		lstackpop(me ,&n);
		printf("%d\n",n);
	
	}

	lstackDestoy(me);

	return 0;

}
