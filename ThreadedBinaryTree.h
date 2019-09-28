#pragma once
#include <iostream>

using namespace std;

#define ElemType char

typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;


void InThread(ThreadTree& p, ThreadTree& pre)
/*��������Զ������������ĵݹ��㷨*/
{
	if (p != NULL)
	{
		InThread(p->lchild, pre);
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}

		//InThread(p->rchild, pre);
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}



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


ThreadTree FirstNode(ThreadTree p)
/*���������������������������µĵ�һ���ڵ�*/
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

ThreadTree NextNode(ThreadTree p)
/*�����������������иýڵ������������µĺ�̽ڵ�*/
{
	if (p->rtag == 0)
		return FirstNode(p->rchild);
	else
		return p->rchild;
//	return p;
}

void InOrder(ThreadNode* T)
/*��������㷨*/
{
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		cout << p->data;//visit(p);���ʲ�������
}

void InitThTree(ThreadTree& T)
{
	//BiTree p;
	T = (ThreadTree)malloc(sizeof(ThreadNode));
	T->data = NULL;
	T->lchild = NULL;
	T->rchild = NULL;
	T->ltag = 0;
	T->rtag = 0;
}


ThreadTree MakeThTree(ElemType e, ThreadTree L, ThreadTree R)
{
	ThreadTree p = (ThreadTree)malloc(sizeof(ThreadNode));
	if (NULL == p)
		return NULL;
	p->data = e;
	p->lchild = L;
	p->rchild = R;
	p->ltag = 0;
	p->rtag = 0;
	return p;
}


ThreadTree CreatThTree(char* defBT, int& i)
//����������������������defBTΪ��������,iΪdefBT��λ��
{
	ThreadTree T;
	ElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//����
	else
	{
		T = MakeThTree(ch, NULL, NULL);
		T->lchild = CreatThTree(defBT, i);
		T->rchild = CreatThTree(defBT, i);

	}
	return T;
}
