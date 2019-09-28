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
/*中序遍历对二叉树线索化的递归算法*/
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
/*利用中序遍历建立线索二叉树*/
{
	ThreadTree pre = NULL;
	if (T != NULL)
	//非空才进行线索化
	{
		InThread(T, pre);	//	递归线索化
		pre->rchild = NULL;	//处理遍历的最后一结点
		pre->rtag = 1;
	}
}


ThreadTree FirstNode(ThreadTree p)
/*求中序线索二叉树中中序序列下的第一个节点*/
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

ThreadTree NextNode(ThreadTree p)
/*求中序线索二叉树中该节点在中序序列下的后继节点*/
{
	if (p->rtag == 0)
		return FirstNode(p->rchild);
	else
		return p->rchild;
//	return p;
}

void InOrder(ThreadNode* T)
/*中序遍历算法*/
{
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		cout << p->data;//visit(p);访问操作函数
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
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标
{
	ThreadTree T;
	ElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//空树
	else
	{
		T = MakeThTree(ch, NULL, NULL);
		T->lchild = CreatThTree(defBT, i);
		T->rchild = CreatThTree(defBT, i);

	}
	return T;
}
