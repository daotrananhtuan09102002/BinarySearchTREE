#include <iostream>
using namespace std;

struct node
{
	int key;
	node* pLeft;
	node* pRight;
};

typedef node* TREE;

void CreateTREE(TREE& T)
{
	T = NULL;
}

void AddNode(TREE& T, int x)
{
	if (T)
	{
		if (T->key == x) return;
		if (T->key > x)
			AddNode(T->pLeft, x);
		else if (T->key < x)
			AddNode(T->pRight, x);
	}
	else
	{
		T = new node;
		T->key = x;
		T->pLeft = T->pRight = NULL;
	}
}

void input(TREE& T)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		AddNode(T, x);
	}
}

void Replace(TREE& p, TREE& T)
{
	if (T->pLeft)
		Replace(p, T->pLeft);
	else
	{
		p->key = T->key;
		p = T;
		T = T->pRight;
	}
}

void DeleteNode(TREE& T, int x)
{
	if (T)
	{
		if (T->key > x)
			DeleteNode(T->pLeft, x);
		else if (T->key < x)
			DeleteNode(T->pRight, x);
		else
		{
			node* p = T;
			if (T->pLeft == NULL)
				T = T->pRight;
			else if (T->pRight == NULL)
				T = T->pLeft;
			else
				Replace(p, T->pRight);
			delete p;
		}
	}
}

void LNR(TREE T)
{
	if (T)
	{
		LNR(T->pLeft);
		cout << T->key << " ";
		LNR(T->pRight);
	}
}

int DemBacCuaMotSo(TREE T, int x)
{
	while (T)
	{
		if (T->key > x)
			T = T->pLeft;
		else if (T->key < x)
			T = T->pRight;
		else
		{
			if (T->pLeft == NULL && T->pRight == NULL) return 0;
			else if (T->pLeft == NULL || T->pRight == NULL) return 1;
			return 2;
		}
	}
	return 0;
}

int DemMucCuaMotSo(TREE T, int x)
{
	node* p = T;
	int count = 0;
	while (p)
	{
		if (p->key > x)
			p = p->pLeft;
		else if (p->key < x)
			p = p->pRight;
		else
			return count;
		count++;
	}
	return -1;
}

void DemDoCao(TREE T, int flag, int& count)
{
	if (T)
	{
		DemDoCao(T->pLeft, flag + 1, count);
		if (flag > count)
			count = flag;
		DemDoCao(T->pRight, flag + 1, count);
	}
}

void DuyetTheoMuc(TREE T, int flag, int deep)
{
	if (T)
	{
		DuyetTheoMuc(T->pLeft, flag + 1, deep);
		if (flag == deep) cout << T->key << " ";
		DuyetTheoMuc(T->pRight, flag + 1, deep);
	}
}

int main()
{
	TREE T;
	CreateTREE(T);
	input(T);
	LNR(T);
	cout << endl;
	DeleteNode(T, 6);
	LNR(T);
	return 0;
}