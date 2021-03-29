#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>

#include "tokens.h"
#define   TBSIZE  1024

int flag = NUM0;

tokens *tbf[TBSIZE] = {};

static void alarm_handler(int s)
{
	alarm(1);
	for(int td = 0 ; td < TBSIZE ; td++){
		if( NULL != tbf[td]){
			tbf[td]->token += tbf[td]->cps;
			if(tbf[td]->token > tbf[td]->brust)
				tbf[td]->token = tbf[td]->brust;
		}
	}
}

int tokensInit(int cps , int brust)
{
	int td;
	for(td = 0 ; td < TBSIZE ; td++){
		if(NULL == tbf[td]){
			tbf[td] = malloc(sizeof(tokens));
			if(NULL == tbf[td])
				return -1;
			tbf[td]->cps = cps;
		   	tbf[td]->brust = brust;
			tbf[td]->token = 0;
			if(flag == NUM0){
				flag = NUM1;
				signal(SIGALRM , alarm_handler);
				alarm(1);
			}
			break;	
		}
	}
	return td;
}

int tokensFetch(int td, int tn)//令牌桶描述符 ， 取的令牌数
{
	int tmp;
	while(tbf[td]->token < tbf[td]->cps)
		pause();
	if(tbf[td]->token < tn)
	{
		tmp = tbf[td]->token;
		tbf[td]->token = 0;
		return tmp;
	}
	tbf[td]->token -= tn;
	return tn;
}
int returnToken(int td ,int tt)
{
	if(td >= TBSIZE || td < 0)
		return -1;
	tbf[td]->token += tt;
	if(tbf[td]->token > tbf[td]->brust)
		tbf[td]->token = tbf[td]->brust;
	return 0;
}

void tokensDestory(int td)
{
	free(tbf[td]);
	tbf[td] = NULL;
}
void tokensDestory_all(void)
{
	for(int i = 0 ; i < TBSIZE ; i++ )
	{
		free(tbf[i]);
		tbf[i] = NULL;
	}
}


