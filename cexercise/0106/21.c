#include <stdio.h>
int main(void)
{
/*	int i;
	
	for (i = 0;i < 15;i++){
		printf("真好看❤\n");
	}
	printf("\n");%
*/

/*	int i, sum;
	sum=0;
    for (i=1;i<101;i++){
		sum=sum+i;
	}
	printf("%d\n",sum);
*/
/*	int i ,a;
	a=0;
    for(i=1;i<100;i++){
		if(i % 3 == 0 && i % 5 == 0){
			printf("%d\n",i);
			a++;
		}
	}i
    printf("一共有%d个。\n",a)	    

	int x; 
int	c=0;
    printf("请输入一个整型：\n");
    scanf("%d",&x);
	for(;x!=0;x=x/10){
	c=c*10+x%10;
	printf("%d,",x%10);
	}*/
	int nu=100, i=0;

    while(nu<1000) {
	 if(nu % 10 == 6 && nu % 3==0 && nu % 5 != 0)

	 {
	  printf("%d,", nu);

      i=i+1;}	  
	  nu++;
    }
	

	printf("\n");
    printf("%d\n",i);
	
	return 0;
}
