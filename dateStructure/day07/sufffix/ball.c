//z7球多久顺序一样
#include <stdio.h>
#include <seqstack.h>
#include <lqueue.h>
static int ballseq(queue_t *ball)
{
	queue_t *tmp;
	int cur,next;
	int ret = 1;
	queueInit(sizeof(int),30,&tmp);

	deq(ball,&cur);
	while(!queueEmpty(ball)){
		enq(tmp,&cur);
		deq(ball,&next);
		if(next<cur)
			ret = 0;
		cur == next;
	}
	enq(tmp,&cur);
	while(!queueEmpty(tmp)){
		deq(tmp,&cur);
		enq(ball,&cur);
	}
	queueDestory(tmp);

	return ret;
}

int main(void)
{
	queue_t *ball;
	stack_t *onemin;
	stack_t *fivemin;
	stack_t *onehour;

	int out,pop;
	int days = 0;

	queueInit(sizeof(int),30,&ball);
	stackInit(sizeof(int),4,&onemin);
	stackInit(sizeof(int),11,&onemin);
	stackInit(sizeof(int),11,&onemin);

	for(int i = 1; i <= 27 ; i++){
		enq(ball,&i);
	}
	while(1){
		deq(ball,&out);
		if(!stackisFull(onemin)){
			stackpush(onemin,&pop);
		}else{
			while(!stackisEmtpy(onemin)){
			 stackpop(onemin,&pop);
			 enq(ball,&pop);
		}
			if(!stackisFull(fivemin))
				stackpush(fivemin,&out);
			else {
				while(!stackisEmtpy(fivemin)){
			 		stackpop(fivemin,&pop);
			 		enq(ball,&pop);
				}
				if(!stackisFull(onehour))
					stackpush(fivemin,&out);
				else {
					while(!stackisEmtpy(onehour)){
			 			stackpop(onehour,&pop);
			 			enq(ball,&pop);
				}
					enq(ball,&out);
					days ++;

					printf("day:%d\n",days);
					if(ballseq(ball))
						break;

				}
			} 	
		}
	}
	printf("经过%d天次序变得有序\n",days);
	return 0;
}
