/**	
	题目：明明的随机数（数的排序和去重）
	要求：Input Param
		 n               输入随机数的个数
		inputArray      n个随机整数组成的数组
		eturn Value
		OutputArray    输出处理后的随机整数

*/


#include<iostream>
using namespace std;

int main()
{
	int N, n;
	while (cin >> N)
	{
		int arr[1001] = { 0 };
		while (N--)
		{
			cin >> n;
			arr[n] = 1;
		}
		for (int i = 0; i < 1001; i++)
			if (arr[i])
				cout << i << endl;
	}
	return 0;
}


