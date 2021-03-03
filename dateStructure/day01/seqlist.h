#ifndef __SEQLITE_H
#define __SEQLITE_H

//抽象数据类型
//顺序表
typedef struct{
	void *arr;  //存储数据的首地址
	int size;  //每个元素所占字节个数
	int nummb;//结构中拥有成员个数
}seqlist_t;
typedef int (*cmp_t)(const void *date,const void *key);
//接口实现
/*
   初始化顺序表结构
   **/
seqlist_t *seqlistInit(int size);



/*
   增加新元素
 */
int  seqlistInsert(seqlist_t *s ,const void *date);
//遍历
void seqlistTravel(const seqlist_t *s ,void (*pri)(const void *date ));
//查找
void *seqlistFind(const seqlist_t *s,const void*key,cmp_t cmp);
//删除
int seqlistDelete( seqlist_t *s,const void *key,cmp_t cmp);
//修改
int seqlistUpdate(const seqlist_t *s ,const void *key ,cmp_t cmp,const void *newdate);
//销毁
void seqlistDestroy(seqlist_t *s);
//插入有序
int seqlistSortInsert(seqlist_t *s, const void *data, cmp_t cmp);    
#endif
