/**
	题目：质数因子
	要求：输入一个正整数，按照从小到大的顺序输出它的所有质数的因子,最后一个数后面也要有空格
	案例：180的质素因子为 2 2 3 3 5
*/

#include<iostream>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		while (num != 1)
		{
			for (int i = 2; i <= num; i++)
			{
				if (num %i == 0)
				{
					num /= i;
					cout << i << ' ';
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}