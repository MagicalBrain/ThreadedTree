#pragma once
#include <iostream>
#include <fstream>
#include "ThreadedBinaryTree.h"
#include <string.h>

using namespace std;

/*
һ���Ǵ�CMD����graphviz�����ж��������ӻ��Ĳ�����
dot -Tpng ������.dot -o ������.png
*/
void fprint_tree0(ThreadTree t, ofstream* Tree)
{
	if (t != NULL)
	{
		*Tree << t->data << ";" << endl;
		if (t->lchild != NULL)
			* Tree << t->data << "->" << t->lchild->data << ";" << endl;
		if (t->rchild != NULL)
			* Tree << t->data << "->" << t->rchild->data << ";" << endl;

		fprint_tree0(t->lchild, Tree);

		fprint_tree0(t->rchild, Tree);
	}
}

void fprint_tree(ThreadTree t) {
	ofstream Tree;
	Tree.open("������.dot");
	Tree << "digraph G{" << endl;

	fprint_tree0(t, &Tree);
	//rbtree_fprint_tree(t->left, fp);
	//rbtree_fprint_tree(t->right, fp);
	Tree << "}" << endl;
	Tree.close();
	//if (rb_nil == t) return;	
}

void fprint_tree(ThreadTree t, char str[]) {
	ofstream Tree;
	Tree.open(str);
	Tree << "digraph G{" << endl;

	fprint_tree0(t, &Tree);
	Tree << "}" << endl;
	Tree.close();
}


void TestThreadTree()
{
	ThreadTree p, pp;
	InitThTree(p);
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	char* def = "ABD##E##C##";
	char str[] = "asdf";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX###";
	int i = 0, num = 0;
	
	ElemType x = 'Y';

	//����һ��������
	p = CreatThTree(def, i);

	fprint_tree(p);
}