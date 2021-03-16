//树的实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME 32

typedef struct stu_st{
	int id;
	char name[NAME];
}stu_st;
typedef struct node_st{
	stu_st   data;
    struct node_st *left;
    struct node_st *right;
}node_st;


//插入新节点
static int treeInit(node_st **root, const stu_st *data)
{
	node_st *new;

	if(*root == NULL){
		new = malloc(sizeof(*new));
		if(NULL==new)
			return -1;
		memcpy(&(new)->data,data,sizeof(stu_st));
		new->left = new->right = NULL;
		*root = new;
		return 0;
	}
	if(data->id <= (*root)->data.id)
		return treeInit(&(*root)->left,data);
	else 
		return treeInit(&(*root)->right,data);
	
}
//中序遍历
static void treeMid(const node_st *root)
{
	if(root == NULL)
		return ;
	treeMid(root->left);
	printf("%d  %s\n" , root->data.id ,root->data.name);
	treeMid(root->right);

}
//释放
static void treeDestory(node_st **root)
{
	if(*root == NULL)
		return  ;
	treeDestory(&(*root)->left);
	treeDestory(&(*root)->right);
	printf("%d  %s wil be destory\n",(*root)->data.id,(*root)->data.name);
	free(*root);
	*root = NULL ;

}
//画树
static void _draw(node_st *root ,int level)
{
	if(root == NULL)
		return ;
	_draw(root->right,level+1);
	for(int i=0;i < level ;i++ )
		printf("        ");
	printf("%d %s\n",root->data.id,root->data.name);
	_draw(root->left,level+1);
}
static void treeDraw(node_st *root)
{
	_draw(root,0);
}
//查找
static node_st **_deletefind(node_st **root , int id)
{
	if(*root == NULL)
		return NULL;
	if((*root)->data.id == id)
		return root;
	if((*root)->data.id >= id)
	  	return _deletefind(&(*root)->left,id);
	else
		return _deletefind(&(*root)->right,id);	
}
//找到最大的数
static node_st *treemax(node_st *root)
{
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return root;
	return treemax(root->right);
	

}

//删除
static int treedel(node_st **root,int id)
{
	node_st **find = _deletefind(root,id);
	node_st *left,*right;
	if(find == NULL)
		return -1;
	left = (*find)->left;
	right = (*find)->right;
	(*find)->left = (*find)->right =NULL;
	free(*find);
	if(left != NULL){
	   *find = left;
		if(right != NULL)
			treemax(left)->right = right;
	}
	else
		*find = right;
			
	return 0;

}
//计算节点个数
static int sumtree(node_st *root)
{   
	if(root == NULL)
		return 0;
	return 1+sumtree(root->left)+sumtree(root->right);
}
//构建平衡二叉树
/*static void treebalance(node_st **root)
{
	int val;
	if(*root =NULL)
		return ;
	while(1){
		val = sumtree((*root)->left) -sumtree((*root)->right);
		if(val>1)
			treerightturn(root);
		else if(val<-1)
			treeleftturn(root);
		else
			break;
	}
	treebalance(&(*root)->left);
	treebalance(&(*root)->right);
}
*/
static node_st *treemin(const node_st *root)
{
	if(root == NULL)
		return NULL;
	if(root->left == NULL)
		return (node_st *)root;
	return treemin(root->left);
	
}


static void treerightturn(node_st **root)
{
	node_st *l,*cur;
	cur = *root;
	
	l=cur->left;
	*root = l;

	cur->left = NULL;
	treemax(l)->right = cur;
}
static void treeleftturn(node_st **root)
{
	node_st *r,*cur;
	
	cur = *root;
	r = cur->right;

	*root = r;
	cur->right = NULL;
	treemin(r)->left = cur;
}

//构建平衡二叉树
static void treebalance(node_st **root)
{
	int val;
	if(*root == NULL)
		return ;
	while(1){
		val = sumtree((*root)->left) -sumtree((*root)->right);
		if(val>1)
			treerightturn(root);
		else if(val<-1)
			treeleftturn(root);
		else
			break;
	}
	treebalance(&(*root)->left);
	treebalance(&(*root)->right);
}
int main(void)
{
	stu_st stu;
	node_st *t=NULL;
	int ids[]={1,2,3,4,5,6,7,8,9};
	int key = 4;
	
	for(int i=0;i<sizeof(ids)/sizeof(*ids) ; i++){
		stu.id = ids[i];
		snprintf(stu.name , NAME , "stu%d",ids[i]);
		treeInit(&t , &stu);
	}
	treeMid(t);
	treeDraw(t);
#if 0
	printf("******************************************\n");
	treedel(&t,key);
	treeDraw(t);
	printf("**********************************\n");
	
	printf("%d\n",sumtree(t));
#endif
	treebalance(&t);
	
	treeDraw(t);

	treeDestory(&t);
	return 0;
}

