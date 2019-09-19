#pragma once
#include <iostream>

using namespace std;

#define ElemType int

typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;

void CreateInThread(ThreadTree& T)
/*�������������������������*/
{
	ThreadTree pre = NULL;
	if (T != NULL)
		//�ǿղŽ���������
	{
		InThread(T, pre);	//	�ݹ�������
		pre->rchild = NULL;	//������������һ���
		pre->rtag = 1;
	}
}

void InThread(ThreadTree &p,ThreadTree &pre)
/*��������Զ������������ĵݹ��㷨*/
{
	if (p == NULL)
	{
		InThread(p->lchild, pre);
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}

		//InThread(p->rchild, pre);
		if (pre != NULL && pre->lchild == NULL)
		{
			p->rchild = pre;
			p->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}

ThreadTree FirstNode(ThreadTree p)
/*���������������������������µĵ�һ���ڵ�*/
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

ThreadTree NextNode(ThreadTree p)
/*���������������������������µĵ�һ���ڵ�*/
{
	if (p->rtag == 0)
		return FirstNode(p->rchild);
	else
		return p->rchild;
	return p;
}

void InOrder(ThreadNode* T)//asd
/*��������㷨*/
{
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		//visit(p);���ʲ�������
}