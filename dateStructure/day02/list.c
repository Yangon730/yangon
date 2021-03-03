
#include "linkdelist.h"
#include <stdlib.h>
#include <string.h>

//初始化头文件
int listheadInit(int size ,listhead_t **l)
{
	listhead_t *h;

	h = malloc(sizeof(listhead_t));
	if(NULL == h)
		return -1;

	h->next = NULL;
	h->size = size;
	h->nmenb = 0;

	*l = h;

	return 0;
}

//增
int listheadInsert(listhead_t *l,const void *date ,int way)
{
	node_t *new;
	node_t *p;

	new = malloc(sizeof(node_t));
	if(NULL == new)
		return -1;
	new->date = malloc(l->size);
	if(NULL == new->date){
		free(new);
		return -1;
	}
	memcpy(new->date,date,l->size);
	if(way == HEADINSERT){
		new->next = l->next;
		l->next = new; //头插
	
	}else if(way == TAILINSERT){//尾插
		for (p = l->next ; p->next != NULL; p = p->next)
	    	;
        p->next =new;
		new->next = NULL;
	}
	return 0;
}
//删除
int listDelete(listhead_t *l,const void *key,cmp_t cmp)
{
  	node_t *p;
	node_t *n;
    for( p = l->next;p != NULL ; p = p->next)
	{
		if(cmp(p->date,key) == 0)
		{
			l->next = p->next ;
		
		    return 1;
		}
		if(cmp(p->next->date, key) == 0){
			n = p->next;
			p->next = n->next; 
			free(n);
			return 1;
		}
    }
	return 0;
}
//修改
int listupdate(const listhead_t *l ,void *key ,cmp_t cmp ,void *newdate )
{
  	node_t *p;
	
    for( p = l->next;p != NULL ; p = p->next)
	{ 
		if(cmp(p->date,key) == 0)
		{
		   	memcpy(p->date , newdate , l->size);
			return 1;
		}
    }
}
//遍历
void listTraval(const listhead_t *l,pri_t pri)
{
	node_t *p;

	for(p = l->next;p !=  NULL; p = p->next ){
		pri(p->date);
	}
}
//销毁
void listDestory(listhead_t *l)
{
	node_t *p ,*n ;

	for(p = l->next , n= p->next; ; n = n->next){
		free(p);
		p=n;
		if(p==NULL)
			break;
	}
	
	free(l);
}

