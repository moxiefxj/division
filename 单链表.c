/*
功能：单链表的操作：初始化、插入数据、删除数据等
开发者：冯筱静
版本：Version1.0
开发时间：2018-3-28 11:16
*/
#include <stdio.h>
#include<stdlib.h>

//定义单链表中操作的数据类型
typedef int ElemType;

//定义单链表中每一个结点的形式
typedef struct LNode
{
	ElemType data;//结点的数据域

	struct LNode *next;//结点的指针域

}LNode,*LinkList;

//初始化单链表

LNode *InitLinkList()
{
	LNode *head;//头结点的指针

	head=(LNode*)malloc(sizeof(LNode));

	if(head==NULL)  return NULL;//分配失败

	head->next=NULL;

	return head;

}

//向链表中添加n个数据

int InputLinkList(LNode *head,int n)
{

	LNode *p;
	LNode *s;//专门记录新生成结点的地址
	int i=1;

	p=head;//p指针指示链表的头部，以方便输入数据
	
	while(i<=n)
	{
		s=(LNode *)malloc(sizeof(LNode));
		
		if(s==NULL)  return -1;//地址分配不成功

		scanf("%d",&s->data);

		s->next=NULL;

		p->next=s;

		p=p->next;

		i++;
	}
	return 1;

}

//向链表中指定位置添加数据

int InsertLinkList(LNode *head,int i,ElemType e)
{
	LNode *p;
	LNode *s;

	int j;//计数，记录带插入数据的前一个位置

	p=head;
	j=0;

	while(p!=NULL&&j<i-1)
	{
		p=p->next;

		j++;
	}
	//判断插入点的位置是否合法
	if(j>i-1||p==NULL)  return -1;

	s=(LNode*)malloc(sizeof(LNode));

	if(s==NULL)  return 0;//分配节点空间失败

	s->data=e;

	s->next=p->next;

	p->next=s;

	return 1;

}

//显示链表中的数据
void OutputLinkList(LNode *head)
{
	LNode *p;

	p=head->next;

	while(p!=NULL)
	{
		printf("%d ",p->data);

		p=p->next;
	}
}

//删除数据（不能删除的：空链，删除位置不合法）

/*int DeleteLinkList(LNode *head,int i)
{
	LNode *p;
	LNode *q;
	int j;
	p=head;
	q=head;
	for(j=1;j<i;j++)
	{
		p=p->next;
	}
	q=p->next;
	p->next=q->next;
	return 1;
}*/
//删除链表中指定位置的数据元数，删除数由一个指针变量带回结果
int	DeleteLinkList(LNode *head,int i,ElemType *e)
{
	LNode *p;//指向待删除结点的前驱结点
	LNode *q;//指向待删除节点
	
	int j;

	p=head;
	
	j=0;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;

		j++;
	}
	//判断删除点的位置是否合法
	if(j>i-1||p==NULL) return -1;

	q=p->next;

	p->next=q->next;//or p->next=p->next->next;

	*e=q->data;

	free(q);
	return 1;
}

//修改数据
int UpdateLinkList(LNode *head,int i,ElemType e)
{
	LNode *p;
	int j=0;
	p=head;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;

		j++;
	}
	//判断修改点的位置是否合法
	if(j>i-1||p==NULL) return -1;
	p=p->next;
	p->data=e;
	
	return 1;
}

//链表的查找
int LocateLinkList(LNode *head,ElemType e)
{
	int i=1;
	LNode *p;
	p=head;
	while(p!=NULL&&p->data!=e)
	{
		p=p->next;
		i++;
	}
	if(p==NULL) return -1;
	return i;
}

int main()
{
	LNode *head;

	int flag;

	int n,i,loc,a,b,c,d;

	ElemType e;

	head=InitLinkList();

	if(head==NULL)
	{
		printf("单链表初始化失败\n");
	}
	else
	{
		printf("单链表初始化成功\n");
	}
	printf("请输入要构建链表数据的个数:");

	scanf("%d",&n);

	printf("请输入要构建链表数据:");

	InputLinkList(head,n);

	printf("请输入需要插入的位置：");
	scanf("%d",&i);
	printf("请输入需要插入的数据：");
	scanf("%d",&loc);
	InsertLinkList(head,i,loc);
	OutputLinkList(head);

	printf("请输入需要删除的位置：");
	scanf("%d",&a);
	DeleteLinkList(head,a,&e);
	printf("\n删除的数据是：%d",e);

	printf("\n请输入需要修改的位置：");
	scanf("%d",&b);
	printf("请输入需要修改的数据：");
	scanf("%d",&c);
	UpdateLinkList(head,b,c);

	printf("请输入需要查找的数据:");
	scanf("%d",&e);
	d=LocateLinkList(head,e);
	printf("查找的元素位置是：%d",d);

	printf("\n当前链表中的数据为:");

	OutputLinkList(head);

	return 0;
}