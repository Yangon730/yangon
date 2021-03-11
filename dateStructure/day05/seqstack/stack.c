#include <string.h>
#include <stdlib.h>

#include "seqstack.h"

int stackInit(int size ,int capacity , stack_t **s)
{
	*s = malloc(sizeof(stack_t));
    if((*s) == NULL){
		return -1;
	}
	(*s)->base = (*s)->top = calloc(capacity,size); 
	
	if((*s)->base == NULL){
		free(*s);
		return -1;
	}
	(*s)->capacity = capacity;
	(*s)->size = size;
	return 0;
}	

//是否为空
int stackisEmtpy(const  stack_t *s)
{

	return s->top == s->base;

}

int stackisFull(const stack_t *s)
{

	return ((char *)s->top - (char *)s->base) / s->size == s->capacity;

}

int stackpush(stack_t *s,const void *data)
{
	if(stackisFull(s))
		return -1;

	memcpy(s->top ,data , s->size);

	s->top = (char *)s->top +s->size ;
	return 0;
}

int stackpop(stack_t *s,void *data)
{
	if(stackisEmtpy(s))
		return -1;

	s->top =(char *)s->top - s->size;
	memcpy(data ,s->top ,s->size);

	return 0;

}

void stackDstory(stack_t *s)
{
	free(s->base);
	free(s);
}
