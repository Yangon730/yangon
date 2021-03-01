//
#include <stdio.h>

int str_cmp( const char *src,const char *dst)
{
     for(int i = 0 ; src[i] != '\0' || dst[i] != '\0'; i++ )
     { 
          if(src[i] != dst[i] )
          return src[i] - dst[i];     
     } 
     return 0;
}
int main()
{
	char arr[] = "hello";
 	char str[] = "heakkbg";
    printf("%d\n",str_cmp(arr,str));	
	return 0;
}
