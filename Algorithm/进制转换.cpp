/**
	题目：进制转换
	要求：接受一个十六进制的数值字符串，输出该数值的十进制字符串（多组同时输入）
*/

#include<iostream>
using namespace std;

int main()
{
	int a;
	while (cin >> hex >> a)
	{
		cout << a << endl;
	}
	return 0;
}

//-------------------------------------


#include<iostream>
#include<string>

using namespace std;

int fun(string str)
{
	int ans = 0;
	for (char c : str)
	{
		if (c >= '0' && c <= '9')
			ans = ans * 16 + c - '0';
		else if (c >= 'a' && c <= 'f')
			ans = ans * 16 + c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			ans = ans * 16 + c - 'A' + 10;
	}
	return ans;
}


int main()
{
	string str;
	while (cin >> str)
	{
		cout << fun(str) << endl;
	}
	return 0;
}

//-------------------------------------


#include<stdio.h>
int main()
{
	int a;
	while (scanf("%x", &a) != EOF)
	{
		printf("%d\n", a);
	}
	return 0;
}