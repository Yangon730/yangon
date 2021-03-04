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

	
	h->head.next = &h->head;
	h->head.last = &h->head;
	h->size = size;
	h->nuemb = 0;

	*l = h;
	return 0;

}
/*将新的节点插入到两个结点之间 */
static void nodeInsert(node_t *n , node_t *la ,node_t *nt)
{
	n->next = nt;
	n->last = la;
	la->next = n;
	nt->last = n;
}
//插入
int dflistInsert(listhead_t *l ,void *data ,int way)
{
	node_t *n;
	
	
	n = malloc(sizeof(node_t)+l->size);
	if(n == NULL)
		return -1;
	
	
    
	memcpy(n->data,data,l->size);
	if (way == HEADLIST )
		nodeInsert(n,&l->head,l->head.next);
	else if (way == LASTLIST)
		nodeInsert(n,l->head.last,&l->head);
	else {
	
		free(n);
		return -1;
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
	 node_t *cur;

	for(cur = l->head.next; cur != &l->head ;cur = cur->next){
		if(cmp(cur->data,key) == 0){
			return cur;
		
		}
	}
	return NULL;
}

static void nodeDelete(node_t *p)
{
	p->last->next = p->next;
	p->next->last = p->last;

    
	free(p);

}
//删除
int dflistdel(listhead_t *l,void *key ,cmp_t cmp)
{
	
	node_t *p= (node_t *)dflistfind(l,key,cmp);
	if(p == NULL)
		return -1;
	nodeDelete(p);

	return 0;
}
//摘除 删掉指定结点的同时获得数据
int dflistFetch(listhead_t *l ,const void *key ,cmp_t cmp,void *data)
{
	
	node_t *p= (node_t *)dflistfind(l,key,cmp);
    
	if(NULL == p)
		return -1;

    memcpy (data,p->data,l->size);
	
	nodeDelete(p);
    return 0;

}

//是否为空
int dflistIsEmpty(const listhead_t *l)
{
/*	int i=0;
	node_t *p;
	for( p = l->head.next ;p != &l->head ; p = p->next)
		i++;
	if(i == 0)
		return 0;
	return 1;*/
	return l->head.next == &l->head && l->head.last == &l->head;

}


//销毁
void dflistDestroy(listhead_t *l )
{
	node_t *p ;
	if(!dflistIsEmpty(l)){
		for(p = (l->head.next)->next; ;p= p->next){
			nodeDelete(p->next);
			if(p == &l->head)
				break;
		}
	}
	free(l);	
}









