//去空格
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *backspace(const  char *p);

int main(void)
{
	char str[]="    hello word      ";
	
	char *ret = backspace(str);
	puts(ret);

	free(ret);
	ret = NULL;//重新释放了free（NULL）


	return 0;
}
char *backspace(const  char *p)
{
	char *ret ;
//	char *new;
	size_t size;
	int i,j;

	size = strlen(p)+1;
//	ret = malloc(size);
	ret = calloc(size ,sizeof(char));//个数和每个的字节；
	if(ret == NULL){
		return NULL;
	}

//	memset(ret , 0 ,size); 
    i=j=0;
	for(;p[i];i++){
		if(p[i] != ' '){
			ret[j] =p[i];
			j++;
		}
	}
	if(j+1<size){
		//开辟空间太大
//		new  = malloc(j+1);
//		strcpy(new , ret);
//		free(ret);
	
		ret = realloc(ret ,j+1);
		//realloc(NULL,size)---->malloc(size)
		//realloc(ptr , 0)------>free(ptr)
	
	}
	return ret;
}

