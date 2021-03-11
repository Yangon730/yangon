#include <stdlib.h>
#include "lstack.h"


//初始化
int  lstackinit(int size ,lstack_t **ls)
{

	return dflistheadINit(size,ls);

}
//是否为空
int lstackisEmpty(lstack_t *ls)
{

	return dflistIsEmpty(ls);

}

//入栈
int lstackpush(lstack_t *ls , void *data)
{

	return dflistInsert(ls,data,HEADLIST);

}

static int alawayCmp(const void *data ,const void *key)
{
	return 0;

}


//出栈
int lstackpop(lstack_t *ls,void *date) 
{
	return  dflistFetch(ls,NULL,alawayCmp,date);

}

//销毁
void lstackDestoy(lstack_t *ls)

{

	return dflistDestroy(ls);
}

