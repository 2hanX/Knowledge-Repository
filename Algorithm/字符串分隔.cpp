/**	
	题目：字符串分隔
	要求：连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组； 
		 长度不是8整数倍的字符串请在后面补数字0，空字符串不处理

*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2, tmp;
	while (cin >> str1 >>str2)
	{
		//str1
		while (str1.length() >= 8)
		{
			tmp = str1.substr(0, 8);
			cout << tmp << endl;
			str1 = str1.substr(8);
		}
		if (!str1.empty())
		{
			cout << str1;
			for (int i = 0; i < 8 - str1.length(); i++)
				cout << '0';
		}
		cout << endl;

		//str2
		while (str2.length() >= 8)
		{
			tmp = str2.substr(0, 8);
			cout << tmp << endl;
			str2 = str2.substr(8);
		}
		if (!str2.empty())
		{
			cout << str2;
			for (int i = 0; i < 8 - str2.length(); i++)
				cout << '0';
		}
		cout << endl;
	}
	return 0;
}


