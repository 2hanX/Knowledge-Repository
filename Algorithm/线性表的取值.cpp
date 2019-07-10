#include<iostream>
using namespace std;
#define MAXSIZE 10
#define ElemType int
#define Status int
#define OVERFLOW -1
#define OK 1
#define ERROR 0

typedef struct
{
	ElemType *elem;
	int length;
}SqList;
Status InitList(SqList &L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}

Status GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return e;
}

int main()
{
	SqList L;
	InitList(L);
	L.length = MAXSIZE;
	int num = 1;
	for(int i=0;i<L.length;i++)
	{
		L.elem[i] = num;
		num += 2;
	}
	ElemType e;
	int value = GetElem(L, 4, e);
	cout << value << endl;
	return 0;
}