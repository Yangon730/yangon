//顺序表的栈
#ifndef __SSTACK__
#define __SSTACK__

typedef struct {
	void *top;//栈顶
	void *base;//栈底
	int capacity; //个数
	int size;//每个的字节

}stack_t;

//初始化
int stackInit(int size ,int capacity , stack_t **s); 
/*开辟结构体空间，栈顶栈底开辟用户指定的size和cap        */

//是否为空
int stackisEmtpy(const  stack_t *s);
//栈顶等于栈底

//是否为满
//栈顶-栈底除去size=个数
int stackisFull(const stack_t *s);

//入栈
int stackpush(stack_t *s,const void *data);
//判断是否为满,复制data到栈顶，栈顶强转char *加size字节

int stackpop(stack_t *s,void *data);
//判断是否为空栈顶减去size字节把栈顶元素复制到data

void stackDstory(stack_t *s);


#endif
