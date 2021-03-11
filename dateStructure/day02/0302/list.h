#ifndef __LIST_H
#define __LIST_H

enum {HEADINSERT, TAILINSERT};//枚举

// 数据结点
typedef struct node_st{
	void *data; // 数据域首地址
	struct node_st *next; //指针域
}node_t;

// 头结点
typedef struct {
	// struct node_st *next;
	node_t head; //头结点变为和数据节点一样的
	int size;  //每个元素的所占字节
	int nmemb; //数据节点个数
}listhead_t;

typedef int (*cmp_t)(const void *data, const void *key);

typedef void (*pri_t)(const void *data);
// 接口
/*
 初始化头结点
 */
int listheadInit(int size, listhead_t **l);
/*开辟头结点结构体空间，data为空 next指向空 size用户指定 numnb为0  *l=开辟头结点 */
/*增*/
int listInsert(listhead_t *l, const void *data, int way);
/*开辟数据节点空间 ，开辟数据节点数据与空间 ，把data复制到数据域
头插：头结点的指针域指向插入的节点new，new的指针域向原来的头结点所指向的 */
//尾插：遍历元素到最后一个为空，new的指针域指向空 ，原来的节点指针域指向new

/*删除 */
int listDelete(listhead_t *l, const void *key, cmp_t cmp);

//	遍历所有数据域运用比较函数找到要删除key，key的前驱节点的指针域域指向key的后驱节点

/*
 遍历
 */
void listTraval(const listhead_t *l, pri_t pri);

void listDestroy(listhead_t *l);

#endif

