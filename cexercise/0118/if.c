#include <stdio.h>
int main(void)
{
 	int x;
	int a;
	int b;
	int c;
	scanf("%d,%d,%d",&a,&b,&c);

	if(a<b){
    x=a;		
	a=b;
	b=x;
	} if(a<c){
	x=a;
	a=c;
	c=x;
	} if(b<c){
	x=b;
	b=c;
	c=x;
	}
   printf("a:%d,b:%d,c:%d\n",a,b,c);

	return 0;
}
