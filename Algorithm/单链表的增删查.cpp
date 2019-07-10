#include<iostream>
using namespace std;
#define ElemType int
#define Status int
#define OK 1
#define ERROR 0

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

Status  initLink(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}

void getElem(LinkList L, int i)
{
	LNode *p;
	p = new LNode;
	p = L->next;
	int j = 1;
	while (p && j<i)
	{	
		p = p->next;
		j++;
	}
	if (!p || j > i)
		exit(ERROR);
	cout << p->data << endl;
}

LNode *locateElem(LinkList L, ElemType e)
{
	LNode *p = new LNode;
	p = L->next;
	while (p&&p->data != e)
		p = p->next;
	cout << p << endl;
}

Status insertLink(LinkList &L, int i, ElemType e)
{
	LNode *p = new LNode;
	p = L;
	int j = 0;
	while (p && (j<i-1))
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode *s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status deleLink(LinkList &L, int i)
{
	LNode *p = new LNode;
	p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)
		return ERROR;
	LNode *q = new LNode;
	q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}


void createList(LinkList &L, int n)
{
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		LNode *p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void outPut(LinkList L)
{
	LNode *p = new LNode;
	p = L->next;
	while (p)
	{
		cout << p->data<<" ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	LinkList L;
	initLink(L);
	createList(L, 7);
	outPut(L);
	insertLink(L, 2, 89);
	outPut(L);
	deleLink(L, 2);
	outPut(L);
	getElem(L, 6);
	return 0;
}