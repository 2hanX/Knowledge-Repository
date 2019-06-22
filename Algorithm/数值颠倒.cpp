/**
	题目：数值颠倒
	要求：输入一个整数，将这个整数以字符串的形式逆序输出。程序不考虑负数的情况，若数值含有0，则逆序形式也含有0，如输入为100，输出为001
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		string str = to_string(num);
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}



//-------------------------------


#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		string str = to_string(num);
		for (int i = str.length()-1; i >= 0; i--)
		{
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}



//-------------------------------


#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int num;
	stack<char> ch_stack;
	while (cin >> num)
	{
		string str = to_string(num);
		for(char s:str)
			ch_stack.push(s);
		while (!ch_stack.empty())
		{
			cout << ch_stack.top();
			ch_stack.pop();
		}
		cout << endl;
	}
	return 0;
}