#include <stdlib.h>
#include <string.h>

#include "forlist.h"

//初始化

int forlistheadInit(int size  listhead_t **l)
{
	listhead_t *h;

	h =malloc(sizeof(listhead_t));

	h->head.next = NULL;
	h->head.data =NULL;
	h->size = size;
	h->numb = 0;

	*l = h;
	return 0;
}

//增
int forlistheadsert(listhead_t *l , const void *data,int way)
{
	node_t *new;
	node_t *p;

	new = malloc(sizeof(node_t));
	
	if(new == NULL ) //判断开辟空间是否为空
		return -1;
	new->data  =malloc(l->size);
    
	if(NULL == new->data){
		free(new);
		return -1;
	}
	memcpy(new->date,date,l->size);
	if()







}

//遍历
void forlistTraval(const  listhead_t *l,pri_t cmp);

