#include <stdio.h>
int main( )
{
	int i;
	int j=0;
	char b[]="";
	char a[]="ab   cc\t  dd";
    for(i = 0;a[i] != '\0';i++){
		if(a[i] == ' '||a[i] == '\t')
              continue;
		  	b[j]=a[i];
			j++;
		}
	
    
	b[j] ='\0';
	puts(b);
	return 0;
}
