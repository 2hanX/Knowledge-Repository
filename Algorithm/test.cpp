/*
	顺序表的合并
	La=(7,5,3,2)
	Lb=(5,2,8,9)
	合并后
	La=(7,5,3,2,8,9)
*/

#include<iostream>
using namespace std;
#define MAX 10
typedef struct 
{
	int *elem;
	int length;
}sqList;

int initList(sqList &L)
{
	L.elem = new int[MAX];
	if(! L.elem)
		return 0;
	L.length=0;
	return 1;
}

int creList(sqList &L, int n)
{
	for (int i = 0; i < n; ++i)
		cin>>L.elem[i];
	return 1;
}

int locElem(sqList L, int e)
{
	for(int i=0;i<L.length;i++)
		if(L.elem[i] == e)
			return i+1;
	return 0;
}

int insertList(sqList &L, int i, int e)
{
	if(i<1 || i>L.length)
		return 0;
	if(L.length == MAX)
		return 0;
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	L.length++;
	return 1;
}

int getElem(sqList L, int i, int &e)
{
	if(i<1 || i>L.length)
		return 0;
	return L.elem[i-1];
}

void mergeList(sqList La, sqList Lb)
{
	int m = La.length;
	int n = Lb.length;
	int e = 0;
	for(int i=1;i<=n;i++)
	{
		getElem(Lb,i,e);
		if(! locElem(La,e))
			insertList(La,m++,e);
	}
}

void outPut(sqList L)
{
	for (int i = 0; i < L.length; ++i)
		cout<<L.elem[i];
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	sqList La,Lb;
	initList(La);
	initList(Lb);
	creList(La,4);
	outPut(La);
	creList(Lb,3);
	outPut(Lb);
	mergeList(La,Lb);
	outPut(La);
	return 0;
}