#include <string.h>
#include <stdlib.h>

#include "dflist.h"

//头结点初始化
int dflistheadINit(int size ,listhead_t **l)
{
	listhead_t *h;
	h = malloc (sizeof(listhead_t));
	if(NULL == h)
		return -1;

	h->head.data =NULL;
	h->head.next = &h->head;
	h->head.last = &h->head;
	h->size = size;
	h->nuemb = 0;

	*l = h;
	return 0;

}

//插入
int dflistInsert(listhead_t *l ,void *data ,int way)
{
	node_t *n;
	
	
	n = malloc(sizeof(node_t));
	if(n == NULL)
		return -1;
	n->data = malloc(sizeof(l->size));
	if(NULL == n->data){
		free(n);
		return -1;
	}
    
	memcpy(n->data,data,l->size);
	if (way == HEADLIST ){
		n->last = &l->head;
		n->next = l->head.next;
	    l->head.next  = n;
	}else if (way == LASTLIST)
	{
		n->next = &l->head;
		n->last = l->head.last;
		n->last->next = n;
		n->next->last = n;
	}
	return 0;
}

//遍历
void dflistTaval(listhead_t *l ,pri_t pri)
{
	node_t *p ;
	for(p = l->head.next ;p != &l->head ; p = p->next)
		pri(p->data);
}

//查找
static const void *dflistfind(const listhead_t *l ,const void *key , cmp_t  cmp)
{
	const node_t *p ,*cur;

	for(p = &l->head ,cur = p->next; cur != &l->head ;p=cur ,cur = cur->next){
		if(cmp(cur->data,key) == 0)
			return p;
		
	}
	return NULL;
}

//删除
int dflistdel(listhead_t *l,void *key ,cmp_t cmp)
{
	
	node_t *p= (node_t *)dflistfind(l,key,cmp);
	if(p == NULL)
		return -1;

	p->last->next = p->next;
	p->next->last = p->last;

	free(p);
	return 0;	
}

//摘除 删掉指定结点的同时获得数据
void *dflistFetch(listhead_t *l ,const void *key ,cmp_t cmp)
{
	void *c;
	c = malloc (l->size); 
	
	node_t *p= (node_t *)dflistfind(l,key,cmp);
    
    memcpy (c,p->data,l->size);
	
	p->last->next = p->next;
	p->next->last = p->last;

	free(p);
    return c;

}

//是否为空
int dflistIsEmpty(const listhead_t *l)
{
	int i=0;
	node_t *p;
	for( p = l->head.next ;p != &l->head ; p = p->next)
		i++;
	if(i == 0)
		return 0;
	return 1;

}

//销毁
void dflistDestroy(listhead_t *l )
{
	node_t *p , *q;

	for(p = l->head.next , q = p->next; ;q = q->next){
		free(p);
		p = q ;
		if(p->data == NULL)
			break;
	}
	free(l);	
}









