//顺序表初始化
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

seqlist_t *seqlistInit(int size)
{
	seqlist_t *a;
	a = malloc(sizeof(seqlist_t));
	if(NULL == a)
		return NULL;
    a-> arr = NULL;
	a-> size = size;
	a-> nummb = 0;
	return a;
}

int seqlistInsert(seqlist_t *s ,const void *date)
{
	s->arr  =realloc(s->arr ,(s->nummb+1) * s->size);
    if (s == NULL)
		return -1;
	memcpy((char*)s->arr + s->nummb*s->size , date ,s->size);
	s->nummb ++;
	return 0;
}

void seqlistTravel(const seqlist_t *s ,void (*pri)(const void *date ))
{
	for(int i = 0 ; i< s->nummb ; i++)
		pri((char *)s->arr + i*s->size);
}
void *seqlistFind(const seqlist_t *s,const void *key,cmp_t cmp)
{
  for(int i = 0; i <= s->nummb; i++)
  {
	  if(cmp ((char *)s->arr + i*s->size,key )== 0)
		  return (char *)s->arr+i*s->size;
  }

}
int seqlistDelete( seqlist_t *s,const void *key,cmp_t cmp)
{
	int i;
  	for( i = 0; i <= s->nummb; i++)
  	{
	  	if(cmp ((char *)s->arr + i*s->size,key )== 0){
			memcpy((char *)s->arr + i*s->size , (char *)s->arr+(i+1)*s->size,(s->nummb-i)*s->size);
			break;
			}		
	 	}
	if(i == s->nummb)
		return -1;
	s->nummb--;
	s->arr = realloc(s->arr,s->nummb*s->size);
	return 0;
}

int seqlistUpdate(const seqlist_t *s ,const void *key ,cmp_t cmp,const void *newdate)
{
	int i;
  	for( i = 0; i <= s->nummb; i++)
  	{
	  	if(cmp ((char *)s->arr + i*s->size,key )== 0){
			memcpy((char *)s->arr + i*s->size ,newdate,s->size);
			break;
		}
		if(i == s->nummb)
			return -1;
	}
	return 0;
}

void seqlistDestroy(seqlist_t *s)
{
	free(s->arr);
	s->arr = NULL;
	s->nummb = 0;
	s->size = 0;
}
int seqlistSortInsert(seqlist_t *s, const void *data, cmp_t cmp)
{
	int i ;
  	for( i = 0; i <= s->nummb; i++)
  	{
	  	if(cmp ((char *)s->arr + i*s->size,data )>0)
			break;
	}
	s->arr = realloc (s->arr , (s->nummb +1)*s->size);
	if(s->arr == NULL)
		return -1;
	if(s->nummb > 0)
		memmove((char *)s->arr + (i+1)*s->size ,(char *)s->arr + i*s->size,\
				(s->nummb-i)*s->size);
	memcpy((char *)s->arr + i * s->size , data ,s->size);
	s->nummb ++;

	return 0;
}










