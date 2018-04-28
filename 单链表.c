/*
���ܣ�������Ĳ�������ʼ�����������ݡ�ɾ�����ݵ�
�����ߣ����㾲
�汾��Version1.0
����ʱ�䣺2018-3-28 11:16
*/
#include <stdio.h>
#include<stdlib.h>

//���嵥�����в�������������
typedef int ElemType;

//���嵥������ÿһ��������ʽ
typedef struct LNode
{
	ElemType data;//����������

	struct LNode *next;//����ָ����

}LNode,*LinkList;

//��ʼ��������

LNode *InitLinkList()
{
	LNode *head;//ͷ����ָ��

	head=(LNode*)malloc(sizeof(LNode));

	if(head==NULL)  return NULL;//����ʧ��

	head->next=NULL;

	return head;

}

//�����������n������

int InputLinkList(LNode *head,int n)
{

	LNode *p;
	LNode *s;//ר�ż�¼�����ɽ��ĵ�ַ
	int i=1;

	p=head;//pָ��ָʾ�����ͷ�����Է�����������
	
	while(i<=n)
	{
		s=(LNode *)malloc(sizeof(LNode));
		
		if(s==NULL)  return -1;//��ַ���䲻�ɹ�

		scanf("%d",&s->data);

		s->next=NULL;

		p->next=s;

		p=p->next;

		i++;
	}
	return 1;

}

//��������ָ��λ���������

int InsertLinkList(LNode *head,int i,ElemType e)
{
	LNode *p;
	LNode *s;

	int j;//��������¼���������ݵ�ǰһ��λ��

	p=head;
	j=0;

	while(p!=NULL&&j<i-1)
	{
		p=p->next;

		j++;
	}
	//�жϲ�����λ���Ƿ�Ϸ�
	if(j>i-1||p==NULL)  return -1;

	s=(LNode*)malloc(sizeof(LNode));

	if(s==NULL)  return 0;//����ڵ�ռ�ʧ��

	s->data=e;

	s->next=p->next;

	p->next=s;

	return 1;

}

//��ʾ�����е�����
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

//ɾ�����ݣ�����ɾ���ģ�������ɾ��λ�ò��Ϸ���

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
//ɾ��������ָ��λ�õ�����Ԫ����ɾ������һ��ָ��������ؽ��
int	DeleteLinkList(LNode *head,int i,ElemType *e)
{
	LNode *p;//ָ���ɾ������ǰ�����
	LNode *q;//ָ���ɾ���ڵ�
	
	int j;

	p=head;
	
	j=0;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;

		j++;
	}
	//�ж�ɾ�����λ���Ƿ�Ϸ�
	if(j>i-1||p==NULL) return -1;

	q=p->next;

	p->next=q->next;//or p->next=p->next->next;

	*e=q->data;

	free(q);
	return 1;
}

//�޸�����
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
	//�ж��޸ĵ��λ���Ƿ�Ϸ�
	if(j>i-1||p==NULL) return -1;
	p=p->next;
	p->data=e;
	
	return 1;
}

//����Ĳ���
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
		printf("�������ʼ��ʧ��\n");
	}
	else
	{
		printf("�������ʼ���ɹ�\n");
	}
	printf("������Ҫ�����������ݵĸ���:");

	scanf("%d",&n);

	printf("������Ҫ������������:");

	InputLinkList(head,n);

	printf("��������Ҫ�����λ�ã�");
	scanf("%d",&i);
	printf("��������Ҫ��������ݣ�");
	scanf("%d",&loc);
	InsertLinkList(head,i,loc);
	OutputLinkList(head);

	printf("��������Ҫɾ����λ�ã�");
	scanf("%d",&a);
	DeleteLinkList(head,a,&e);
	printf("\nɾ���������ǣ�%d",e);

	printf("\n��������Ҫ�޸ĵ�λ�ã�");
	scanf("%d",&b);
	printf("��������Ҫ�޸ĵ����ݣ�");
	scanf("%d",&c);
	UpdateLinkList(head,b,c);

	printf("��������Ҫ���ҵ�����:");
	scanf("%d",&e);
	d=LocateLinkList(head,e);
	printf("���ҵ�Ԫ��λ���ǣ�%d",d);

	printf("\n��ǰ�����е�����Ϊ:");

	OutputLinkList(head);

	return 0;
}