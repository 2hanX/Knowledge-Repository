#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef struct
{
	char no[20];
	char name[50];
	float price;
}Book;
typedef struct
{
	Book *elem;
	int length;
}SqList;
int main()
{
	SqList L;
	L.length = 2;
	L.elem[0].name = "hello";
	cout << L.elem[0].name<< endl;
	return 0;
}