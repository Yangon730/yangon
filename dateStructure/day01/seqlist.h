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
seqlist_t *seqlistInit(int size);//
//开辟结构体空间
//首地址指向空 size用户指定 成员个数为0
/*
   增加新元素
 */
int  seqlistInsert(seqlist_t *s ,const void *date);
//开辟存储数据的空间，把date复制到接下来的地址空间arr+numb*size，然后numb++
//

//遍历
void seqlistTravel(const seqlist_t *s ,void (*pri)(const void *date ));
//for循环遍历打印函数打印

//查找
void *seqlistFind(const seqlist_t *s,const void*key,cmp_t cmp);
//遍历整个顺序表，运用比较函数cmp 找到与key相同的数据

//删除
int seqlistDelete( seqlist_t *s,const void *key,cmp_t cmp);
//遍历整个顺序表，运用比较函数cmp找到删除的key，把key以后的数据复制到key的位置
//number减少，缩小arr空间；

//修改
int seqlistUpdate(const seqlist_t *s ,const void *key ,cmp_t cmp,const void *newdate);
/*找到key，把新元素复制到key的位置 */

//销毁
void seqlistDestroy(seqlist_t *s);

//插入有序
int seqlistSortInsert(seqlist_t *s, const void *data, cmp_t cmp);    
#endif
