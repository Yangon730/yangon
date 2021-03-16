//树的实现copy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAMESIZE 32

typedef struct stu_st{
	int id;
	char name[NAMESIZE];
}stu_st;

typedef struct node_st{
	stu_st data;
	struct node_st *left;
	struct node_st *right;
}node_st;

//插入
static int treeInsert(node_st **root ,const stu_st *data)
{
	node_st *new;
	if(*root == NULL){
		new = malloc(sizeof(*new));
		if(NULL == new)
			return -1;
		memcpy(&new->data , data ,sizeof(stu_st));
		new->left = new->right = NULL;
		*root = new;
		return 0;
	}

	if(data->id <= (*root)->data.id)
		return treeInsert(&(*root)->left,data);
	else
		return treeInsert(&(*root)->right,data);
}
//遍历
static void treeMid(const node_st *root)
{
	if(root == NULL)
		return;
	treeMid(root->left);
	printf("%d %s\n",root->data.id,root->data.name);
	treeMid(root->right);
}
//释放
static void treedestory(node_st **root)
{
	if(*root == NULL)
		return ;
	treedestory(&(*root)->left);
	treedestory(&(*root)->right);
	printf("%d %swill be destory \n",(*root)->data.id,(*root)->data.name);
	free(*root);
}

static void _draw(node_st *root,int level)
{
	if(root == NULL)
		return ;
	_draw(root->right,level+1);
	for(int i=0;i<level;i++)
		printf("        ");
	printf("%d %s\n",root->data.id,root->data.name);
	_draw(root->left,level+1);

}
//画树 
static void treeDraw(node_st *root)
{
	_draw(root,0);
}
int main(void)
{
	node_st *t;
	stu_st stu;
	int ids[]={5,8,7,6,8,9,2,3,1};

	for(int i=0;i <sizeof(ids)/sizeof(*ids);i++)
	{
		stu.id = ids[i];
		snprintf(stu.name,NAMESIZE,"stu%d",ids[i]);

		treeInsert(&t,&stu);
		
	}
	
	treeMid(t);
	treeDraw(t);
	treedestory(&t);
	return 0;
}
