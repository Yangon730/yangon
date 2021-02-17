/*海滩上有一堆桃子，五只猴子来分。第一只猴子把这堆桃子平均分为五份，多了一个，这只 猴子把多的一个扔入海中，拿走了一份。第二只猴子把剩下的桃子又平均分成五份，又多了 一个，它同样把多的一个扔入海中，拿走了一份，第三、第四、第五只猴子都是这样做的， 问海滩上原来最少有多少个桃子？*/
/*#include <stdio.h>
  int main(void)
  {
  int i ,sum ;
  for(i = 1 ;i < 6;i++)
  {
  su =  i*5+1;
  }


  return 0;
  }*/
#include <stdio.h>

int main()
{
	int i;
	int j=1;//第五只猴子分的桃子
	int n;//桃子数
	while(1)
	{
		n=4*j;
		for(i=0;i<5;)
		{
			if(n%4!=0)
                             
				break;
			else
			{
				n=(n/4)*5+1;
				i++;
			}
		}
		j++;
		if(i==5)
			break;
	}

	printf("最少有%d个桃子\n",n);
	return 0;
}
/*{
  int i,m,j=0,k,count;
  for(i=4;i<10000;i+=4)
  { count=0;
  m=i;
  for(k=0;k<5;k++)
  {
  j=i/4*5+1;
  i=j;
  if(j%4==0)
  count++;
  else break;
  }
  i=m;
  if(count==4)
  {
  printf("原有桃子%d个\n",j);
  break;
  }
  }
  return 0;
  } 
 */















