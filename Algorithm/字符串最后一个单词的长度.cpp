/**	
	题目：字符串最后一个单词的长度
	要求：计算字符串最后一个单词的长度，单词以空格隔开

	解答：使用动态数组，输入 Ctrl+Z 结束输入
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string input;
	vector<string>arr;
	while (cin >> input)
	{
		arr.push_back(input);
	}
	cout << arr[arr.size() - 1].length() << endl;
	return 0;
}
