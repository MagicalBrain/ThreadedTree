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

void InThread(ThreadTree &p,ThreadTree &pre)
/*中序遍历对二叉树线索化的递归算法*/
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
/*求中序线索二叉树中中序序列下的第一个节点*/
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

ThreadTree NextNode(ThreadTree p)
/*求中序线索二叉树中中序序列下的第一个节点*/
{
	if (p->rtag == 0)
		return FirstNode(p->rchild);
	else
		return p->rchild;
	return p;
}

void InOrder(ThreadNode* T)//asd
/*中序遍历算法*/
{
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		//visit(p);访问操作函数
}