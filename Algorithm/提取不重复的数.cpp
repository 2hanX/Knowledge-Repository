/**
	题目：提取不重复的数
	要求：输入一个 int 型整数，按从右向左的阅读顺序返回一个不含重复数字的新的整数
*/

#include<iostream>
using namespace std;

int main()
{	
	int n;
	while (cin >> n)
	{
		int num = 0;
		int arr[10] = { 0 };
		while (n)
		{
			if (arr[n % 10] == 0)
			{
				arr[n % 10]++;
				num = num * 10 + n % 10;
			}
			n /= 10;
		}
		cout << num << endl;
	}
	return 0;
}