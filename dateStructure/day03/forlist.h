#ifndef __FORLIST__
#define __FORLIST__
enum {HEADINSERT , TAILINSERT};

//数据节点
typedef node_t{
  	struct  node_st *next;
  	void*  data;
}node_t;

//头结点
typedef {
 	node_t  head;
	int size;
	int numb;
}listhead_t;
typedef int (*cmp_t)(const void *data ,const void *key);
typedef void (*pri_t)(const listhead_t *data);
//接口初始化
/*初始化头节点*/
int forlistheadInit(int size  listhead_t **l);


//增
int forlistheadsert(listhead_t *l , const void *data,int way) ;

//遍历
void forlistTraval(const  listhead_t *l,pri_t cmp);

//删除
int forlistDEl(listhead_t *l,const void *key ,cmp_p cmp);

//销毁
void forlistDestroy(listhead_t *l);

#endif
