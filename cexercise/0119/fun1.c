#include <stdio.h>
int isyear	(int year);
int ismonthdays(int month,int year);
int main(void)
{
	int m ,y;
	int sum;
   	scanf ("%d/%d",&y,&m);	
    sum = ismonthdays(m,y);

    printf("%d",sum);

	return 0;
}
int ismonthdays(int month , int year)
{
	int sumdays;
	switch(month){
		case 2 : 
			return 28+isyear(year);
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10 :
		case 12 :
			return 31;
		case 4 :
		case 6 :
		case 9 :
		case 11 :
			return 30;
	}
	return (sumdays);
}
int isyear	(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
