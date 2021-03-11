#ifndef __LSTACK__
#define __LSTACK__
#include <dflist.h>
	
typedef listhead_t lstack_t ;

//初始化
int lstackinit(int size ,lstack_t **ls);
//是否为空
int lstackisEmpty(lstack_t *ls);

//入栈
int lstackpush(lstack_t *ls ,void *date);


//出栈
int lstackpop(lstack_t *ls,void *date) ;

//销毁
void lstackDestoy(lstack_t *ls);


#endif
