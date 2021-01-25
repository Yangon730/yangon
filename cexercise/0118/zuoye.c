/*#include <stdio.h>
int main(void)
{
	int a,c,sum;
	char b;
	scanf("%d%c%d",&a,&b,&c);
    if((int)b==43){
		sum=a+c;
		printf("%d+%d=%d\n",a,c,sum);
	}

    if((int)b==42){
		sum=a*c;
		printf("%d*%d=%d\n",a,c,sum);
	}

    if((int)b==45){
		sum=a-c;
		printf("%d-%d=%d\n",a,c,sum);
	}
    if((int)b==47){
		sum=a/c;
		printf("%d/%d=%d\n",a,c,sum);
	}

	int num ,i;
	int a=0;
    printf("请输入一个四位整型数:");
	scanf("%d",&num);
    i=num/10%10;
	for(num;num>0;num/=10){
		if(i == num%10)
			a++;
            
	}

	printf("十位出现%d次\n",a);

   	int i,j,n,x ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{  
		if(i<=n){
		for(j=n;j>i;j--){
        	printf(" ");
		}
	 	for(x=1;x<i*2-1;x++){
			printf("*");
		}
      }else{for(j=1;j<i-n;j++){
        printf(" ");
      }    
	   for(x=n*2-2;x>(i-n)*2-1;x--){
			printf(" ");
	   }
	}
	}*/


#include<stdio.h>
/*#include<stdlib.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1-n;i<=n-1;i++)
	{
		for(j=0;j<abs(i);j++)
			printf(" ");
		for(j=0;j<2*(n-abs(i))-1;j++)
			printf("*");
		printf("\n");
	}*/
int main(void)
{
	int row;
	printf("请输入行数：");
	scanf("%d",&row);
    for(int i=0;i<row;i++){
		for(int j=0;j<row-i-1;j++)
		printf("  ");
		for(int j=0;j<2*i+1;j++)
  		printf("* ");
		printf("\n");
	}
	for(int i= row-2;i>=0;i--){
		for(int j=0;j<row-i-1;j++)
		printf("  ");
		for(int j=0;j<2*i+1;j++)
		printf("* ");
		printf("\n");
	}

	return 0;
}

