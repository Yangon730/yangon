#ifndef __DLIST__
#define __DLIST__

enum{HEADLIST,LASTLIST};
//数据节点
typedef struct node_st {
	void *data;
   struct node_st *next;
   struct node_st *last;   
}node_t;
//头结点
typedef struct {
	node_t head;
	int size;
	int nuemb;
}listhead_t;

typedef int (*cmp_t)(const void *data ,const void *key);

typedef void (*pri_t)(const void *data);

//头文件初始化
int dflistheadINit(int size ,listhead_t **l);

//插入
int dflistInsert(listhead_t *l ,void *data ,int way);

//遍历
void dflistTaval(listhead_t *l ,pri_t pri);

//查找
static const void *dflistfind(const listhead_t *l ,const void *key , cmp_t  cmp);

//删除
int dflistdel(listhead_t *l,void *key ,cmp_t cmp);

//摘除 删掉指定结点的同时获得数据
void *dflistFetch(listhead_t *l ,const void *key ,cmp_t cmp );

//是否为空
int dflistIsEmpty(const listhead_t *l);

//销毁
void dflistDestroy(listhead_t *l );
#endif
