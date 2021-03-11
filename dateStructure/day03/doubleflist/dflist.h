#ifndef __DLIST__
#define __DLIST__

enum{HEADLIST,LASTLIST};
//数据节点
typedef struct node_st {
	void *data;//数据域
   struct node_st *next; //后置指针
   struct node_st *last; //前驱指针
}node_t;
//头结点
typedef struct {
	node_t head; 
	int size;  //每个所占的字节
	int nuemb; //个数
}listhead_t;

typedef int (*cmp_t)(const void *data ,const void *key);

typedef void (*pri_t)(const void *data);

//头文件初始化
int dflistheadINit(int size ,listhead_t **l);
/*开辟头节点的空间 指针域为空前驱指针后置指针都指向头结点head，size用户指定 ，numb为0 */

//插入
int dflistInsert(listhead_t *l ,void *data ,int way);
	/* 开辟数据节点空间数据域空间，把新元素复制到数据域
	   头插 新节点的前驱指针指向头节点，后置指针指向原来的头结点的后置指针指向的节点
	   尾插  新节点的后置指针指向头结点，前置指针指向原来头结点的前驱指针
	    n->next->last = n;
		n->last->next = n;
	 */

//遍历
void dflistTaval(listhead_t *l ,pri_t pri);

//查找
static const void *dflistfind(const listhead_t *l ,const void *key , cmp_t  cmp);
/*遍历整个双向循环链表，运用比较函数cmp，找到域key相同的数据域元素 返回数据节点的指针*/
//删除
int dflistdel(listhead_t *l,void *key ,cmp_t cmp);
/*运用查找函数找到key，把它前节点的后驱指针指向他的后节点
 它后元素的前驱指针指向它的前节点*/

//摘除 删掉指定结点的同时获得数据
void *dflistFetch(listhead_t *l ,const void *key ,cmp_t cmp );
/*开辟一个size字节的空间找到要摘除的key，把其数据域中的元素拷贝到新空间，链接前后节点释放key*/
//是否为空
int dflistIsEmpty(const listhead_t *l);

//销毁
void dflistDestroy(listhead_t *l );
#endif
