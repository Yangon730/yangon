#ifndef _LLIST_H
#define _LLIST_H

//数据节点
typedef struct node_st{
	void *data;//数据域地址
	struct node_st *prev;//前驱指针
	struct node_st *next;//后继指针
}node_st；

//头结点

typedef struct{
	struct node_st node;
	int number;
	int size;
}llisthead_t;

typedef (*pri_t)(const void *data);

//头结点初始化
int llistheadINit(int size;llisthead_t **list);

//插入
int llistInsert(llisthead_t *list,const void *data,int way);

//遍历
void llistTraval(const llisthead_t *list,pri_t pri);

//删除
int llistDelete(llisthead_t *list,const void *dar<F12  )
