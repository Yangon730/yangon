#include <string.h>
#include <stdlib.h>

#include "queue.h"

//初始化
int queueInit(int size ,int capacity，queue_t **q)
{
	*q = malloc (sizeof(queue_t));
	if(NULL == *q)
		return -1;
	(*q)->base = calloc(capacity, size);
	if(NULL == (*q)->base)
		return -1;
    (*q)->front = (*q)->tail = 0;
	(*q)->capacity = capacity;
	(*q)->size = size;
	return 0;
}

//为空
int queueEmpty(queue_t *q);
{

	return q->front == q->tail && q->flog == LASTDEQ;
}
//为满
int queueFull(queue_t *q)
{

	return q->front == q->tail && q->flog == LASTENQ; 

}

//入队
int enq(queue_t *q ,void *date)
{
	if(queueFull(q))
		return -1;
	memcpy((char *)q->base + q->tail*size,date,size);
	q->tail = (q->tail+1) % q->capacity ;
	q->flog = LASTENQ;
	return 0;
}

//出队
int deq(queue_t *q ,void *date)
{
	if(queueEmpty(q))
		return -1;
	memcpy(date,(char *)q->base+q->front*q->size);
	q->front = (q->front+1)%q->capacity;
	q->flog = LASTDEQ;
}

//销毁
void queueDestory(queue_t *q);
{
	free(q->base);
	free(q);
}
