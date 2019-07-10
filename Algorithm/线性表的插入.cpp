#include<iostream>
using namespace std;
#define MAX 10
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define EleType int
#define Status int

typedef struct
{
	EleType *elem;
	int length;
}SqList;

Status initList(SqList &L)
{
	L.elem = new EleType[MAX];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}

Status insertL(SqList &L, int i, EleType m)
{
	if ((i < 1) || (i > L.length+1))
		return ERROR;
	if (L.length == MAX)
		return ERROR;
	for (int j = L.length - 1; j >=  i - 1; j--)
		L.elem[j+1] = L.elem[j];
	L.elem[i - 1] = m;
	L.length++;
	return OK;
}

void outPut(SqList L)
{
	for (int i = 0; i < L.length; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}
int main()
{
	SqList L;
	initList(L);
	L.length = MAX-2;
	for (int i = 0; i < 9; i++)
		L.elem[i] = i + 2;
	outPut(L);
	insertL(L, 3, 89);
	outPut(L);
	return 0;
}