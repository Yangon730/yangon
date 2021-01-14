#include <stdio.h>
int isleap (int year)
int main(void)
{
	int m,y,i,a,b,c,mdays ;
	int sum=0;

	printf("请输入1990年以后的日期：\n");
	scanf("%d/%d",&y,&m);
	for(i=1990;i<y;i++){
		sum + = 365 + isleap (i);	
	}
	

	{
	for(a=1;a<m;a++){
		if(a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || \
			   a ==	10 || a == 12)
			sum+=31;
		else if( a == 4 || a == 6 || a == 9 || a == 11)
			sum+=30;
		else{
		   	if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			  sum+=29;
			else 
		      sum+=28;
		}

	}
	}
    sum+=1; 
	printf("%d\n",sum);
    b=sum%7;
    printf("%d\n",b);
	{
		
	    if(m == 4 || m == 6 || m == 9 || m == 11)
			mdays = 30;
		else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			mdays=31;
		else{
			 if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			  mdays=29;
			 else 
		      mdays=28;
  	   	}
	
		}	
		printf("      %d月/%d年\n",m,y);
		printf(" 日 一 二 三 四 五 六\n");
        for(c=0;c<b;c++){
		  printf("   ");
		}
		 for(c=1;c<=mdays;c++){
			 printf("%2d",c);
		    if((c+b)%7==0)
			 printf("\n");
			else
		     printf(" ");		
		 }
	printf("\n");
	return 0;
}


//判断润年
int  isleap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}

//判断月的天数
int ismoth(int x  int year  )
{
	int res;
		if(a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || \
				a == 10 || a == 12) 
            res = 31;  
		else if( a == 4 || a == 6 || a == 9 || a == 11)
			res = 30;
		     else
            res+=28+isleap(year);
      return  res;
}
