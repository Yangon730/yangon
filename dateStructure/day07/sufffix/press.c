//中缀变后缀
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <seqstack.h>
#include <lqueue.h>
static int errornumber = 0;


char *midTolast(const char *p);
int lastRes(const char *p);
int main(int argc ,char *argv[])
{
	if(argc<2)
		return 1;
	char *r = midTolast(argv[1]);
    puts(r);
	printf("%d\n", lastRes(r));
	free(r);
	return 0;
}

static int isDigital(char ch)//判断数字
{
	return ch >= '0' && ch <= '9';

}

static int isOperator(char ch) //加减乘除
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/'; 

}

static int charactorToInt(char ch)//字符转整型
{
 	return ch - '0';
}

static int operatorLevel(char ch) //优先级赋值
{
	int level = 0;
	if(ch == '+'|| ch == '-')
		level = 1;
	else if (ch == '*' || ch == '/')
		level = 2;

	return level;
}

char *midTolast(const char *p)
{
	int len;
	stack_t *s;
	queue_t *q;
	char top;
	char *res =NULL;
	int i;
	
	len = strlen(p);

	stackInit(sizeof(char) , len ,&s); //初始化栈
	queueInit(sizeof(char) , len ,&q);//初始化队列
	
	while(*p){
		if(isDigital(*p)){ 
			enq(q,p);//入队
		}else if(isOperator(*p)){
			while(!stackisEmtpy(s)){
				stackpop(s,&top);

				if(operatorLevel(*p) > operatorLevel(top)){
					stackpush(s,&top);
					break;	
				}
				enq(q,&top);
			}
			stackpush(s,p);
		}else if( *p == '('){
			stackpush(s,p);
		}else if(*p == ')'){
			while(!stackisEmtpy(s)){
				stackpop(s,&top);
				if(top == '(')
					break;
				enq(q,&top);
			}
		}else 
			break;
		p++;
	}
		if(*p != '\0'){
			stackDstory(s);
			queueDestory(q);
			return NULL;
		}
		while (!stackisEmtpy(s)){
			stackpop(s,&top);
			enq(q,&top);
		
		}
		i= 0;
		while(!queueEmpty(q)){
			res = realloc(res,i+1);
		   	deq(q,res+i);
	   		i++;	   
		}
		res = realloc(res ,i+1);
		res[i] = '\0';
		stackDstory(s);
		queueDestory(q);
		
		return res;		
}

static int op2num(int left , int right ,char op)
{
	int res;
	switch(op){
		case '+':
			res = left + right;
			break;
		case '-':
			res = left - right;
			break;
		case '*':
			res = left * right;
			break;
		case '/':
			res = left / right;
			break;
		default:
			break;

	}	
	return res;
}


int lastRes(const char *p)
{
	stack_t *s;
	int left,right;
	int res;
	int push;

	stackInit(sizeof(int),strlen(p),&s);
	while(*p){
		if(isDigital(*p)){
			push = charactorToInt(*p);
			stackpush(s,&push);
		}else{
			stackpop(s,&left);
			stackpop(s,&right);
			res = op2num(left , right, *p);

			stackpush(s,&push);
	   }
		p++;
	}
		stackpop(s,&res);
		if(!stackisEmtpy(s)){
			errornumber =1;
			res =0;
			//exit(1);
			//终止进程

		}
		stackDstory(s);
		return res;



}











