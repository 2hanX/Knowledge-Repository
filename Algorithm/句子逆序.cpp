/**
	题目：句子逆序
	要求：将一个英文语句以单词为单位逆序排放，所有单词之间用一个空格隔开，语句中除了英文字母外不再包含其他字符
	输入："I am a boy"
	输出："boy a am I"
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string sentence;
	char Enter;
	stack<string> ch_stack;
	while ((cin >> sentence).get(Enter))
	{
		ch_stack.push(sentence);
		if (Enter == '\n')
			break;
	}
	while (!ch_stack.empty())
	{
		cout << ch_stack.top() << " ";
		ch_stack.pop();
	}
	cout << endl;
	return 0;
}



//----------------------------


#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string sentence;
	vector<string> vs;
	while (cin >> sentence)
		vs.push_back(sentence);
	for (int i = vs.size() - 1; i > 0; i--)
	{
		cout << vs[i] << " ";
	}
	cout << vs[0] << endl;
	return 0;
}