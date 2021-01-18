#include <stdio.h>
int main(void)
{
	int a=10;
    int b=30;
  
   /* ++a;
	printf("a:%d\n",a);
	--a;
	printf("a:%d\n",a);
	c=a+++b;
	printf("a:%d,b:%d,c:%d\n",a,b,c);
	c=++a-b;

	printf("a:%d,b:%d,c:%d\n",a,b,c);
	c=a---b;
	printf("a:%d,b:%d,c:%d\n",a,b,c);
	c=--a-b;
 
	printf("a:%d,b:%d,c:%d\n",a,b,c);
	c=a-- - --b;
	printf("a:%d,b:%d,c:%d\n",a,b,c);



   	b = a << 1;//0000 1010    0001 0100
    c = a >> 1;//0000 0101
	printf("b:%d,c:%d\n",b,c);
    a=-10;
	   
   	b = a << 1; //1111 0110  1110 1100  0001  0100
    c = a >> 1;// 
	printf("b:%d,c:%d\n",b,c);
*/
	a=a^b;
	b=a^b;
	a=a^b;
	printf("a:%d,b:%d\n",a,b);





























	return 0;
}
