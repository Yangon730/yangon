#ifndef __QUUE__
#define __QUUE__
//顺序表的队列实现

typedef struct{
	void *base;
	int front; //队列头元素下标
	int tail;//队尾元素下标
	int size;
	int capacticy;
	
}queue_t;

int queueInit(int size,int capacticy,queue_t **q);

int queueEmpty(const queue_t *q);

int queueFull(const queue_t *q);

int enq(queue_t *q,const void *data);

int deq(queue_t *q,void  *data);

int queueDestory(queue_t *q);

#endif
