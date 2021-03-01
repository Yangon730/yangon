//strcpy 实现
#include <stdio.h>
char *strcpy(char * strDEST,const char * strSRC)
{
    int i;
    for (i = 0 ; strSRC[i] != '\0'; i++)
       strDEST[i] = strSRC[i] ;
    strDEST[i] = '\0'; 
    return strDEST;
}
int main()
{
    char arr[] ="hello word";
    char dest[]= "";
	strcpy(dest , arr);
    puts(dest);
  
    return 0;
}
