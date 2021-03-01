//枚举  ，给初始值按顺序 不按从一开始；
#include <stdio.h>
/*
#define READ 1
#define REA  2
#define REAb 3
#define REAc 4
#define REAa 5
*/
enum {READ ,REA ,REAb =11 ,REAa  };
int main (void)
{

printf("%d ,%d ,%d ,%d \n" , READ ,REA ,REAb ,REAa);
	return 0;
}
