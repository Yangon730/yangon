#ifndef __TOKENS__
#define __TOKENS__

enum{NUM0,NUM1};

typedef struct{
	int cps;
	int token;
	int brust;	
}tokens;

//初始化令牌通
int tokensInit(int cps , int brust);

//取令牌
int tokensFetch(int td, int tn);//令牌桶描述符 ， 取的令牌数
//还令牌
int returnToken(int td ,int tt);
//销毁
void tokensDestory(int td);

void tokensDestory_all(void);


#endif
