#ifndef __QUEUE_H
#define __QUEUE_H
enum {LASTDEQ,LASTENQ};

typedef  struct{
	void *base;//数据域首地址
	int front;//对头元素
	int tail;//队尾元素
	int size; //每个的字节
	int capacity;//个数
	int flog;//判断标志
}queue_t;

//初始化
int queueInit(int size ,int capacity，queue_t **q);
/*开辟结构体空间，数据域空间 ，size和cap用户指定  tail 和front为0 */
//为空
int queueEmpty(queue_t *q);
/*对头等于队尾，且判断标志成立    */
//为满
int queueFull(queue_t *q);
//同为空，但判断标志不同

//入队
int enq(queue_t *q ,void *date);
/*把data复制到数据域队尾size字节处 加判断标志 */
//出队
int deq(queue_t *q ,void *date);
 /*  把数据域队头size字节复制到data ，加判断标志 */
//销毁
void queueDestory(queue_t *q);
#endif 
