/**	
	题目：计算字符个数
	要求：接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数，不区分大小写
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	char key;
	cin >> str >> key;
	int cnt = 0;
	for (char a:str)
	{
		if (key >= 'a' && key <= 'z')
		{
			if (a == key || a == key - 32)
				cnt++;
		}
		else if (key >= 'A' && key <= 'Z')
		{
			if (a == key || a == key + 32)
				cnt++;
		}
		else if (a == key)
					cnt++;
	}
	cout << cnt << endl;
	return 0;
}


