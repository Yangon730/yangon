#ifndef _LIST_H
#define _LIST_H
enum {HEADINSERT,TAILINSERT};
//数据结点
typedef struct node_st{
	void *date; //数据域首地址
	struct node_st *next;
}node_t;

//头结点
typedef struct {
	struct node_st *next;
	int size ;
	int nmenb;
}listhead_t;
//
typedef int(*cmp_t)(const void *date ,const void *key);

typedef void (*pri_t)(const void *date);

//接口
/*
 初始化头结点
 */
int listheadInit(int size ,listhead_t **l);

/*
 增
 */
int listheadInsert(listhead_t *l,const void *date ,int way);


/*
 删除
 */
int listDelete(listhead_t *l,const void *key,cmp_t cmp);

/*
 遍历
 */
void listTraval(const listhead_t *l,pri_t pri);
/*
 修改
 */
int listupdate(const listhead_t *l ,void *key ,cmp_t cmp ,void *wa );
/*
 销毁
 */
void listDestory(listhead_t *l);

#endif
