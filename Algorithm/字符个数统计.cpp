/**
	题目：字符个数统计
	要求：编写一个函数，计算字符串含有的不同字符的个数。字符在ASCII码范围内（0~127），不在范围内的不做统计
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{	
	string str;
	int num = 0;
	cin >> str;
	int arr[128] = { 0 };
	for (char c:str)
	{
		if (c >= 0 && c <= 127)
			arr[c] = 1;
		continue;
	}
	for (int i = 0; i < 128; i++)
	{
		if (arr[i])
			num++;
	}
	cout << num << endl;
	return 0;
}