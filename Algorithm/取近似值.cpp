/**
	题目：取近似值
	要求：接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值
	大于等于5，向上取整；反之则向下取整
*/

#include<iostream>
using namespace std;

int main()
{
	float num;
	while (cin >> num)
	{
		cout << int(num + 0.5) << endl;
	}
	return 0;
}