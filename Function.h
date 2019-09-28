#pragma once
#include <iostream>
#include "ThreadedBinaryTree.h"

using namespace std;

bool func18(ThreadTree T,ElemType x)
{	
	if (T == NULL)
		return false;
	ThreadTree p = FirstNode(T);
	while (p)
	{
		if (p->data == x)
		{
			if (p->rchild)
			{
				if (p->rtag == 0)
				{
					cout << p->rchild->data << endl;
					return true;
				}
			}
			if (p->lchild)
			{
				if (p->ltag == 1 && p->lchild->ltag == 0)
				{
					cout << p->lchild->lchild->data << endl;
					return true;
				}
			}
			return false;
		}
		p = NextNode(p);
	}
}
