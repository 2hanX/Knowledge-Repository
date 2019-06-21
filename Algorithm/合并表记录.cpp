/**
	题目：合并表记录
	要求：数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出
	思路：数组/结构体
*/

#include<iostream>
using namespace std;

int main()
{
	int key_value[10] = { 0 };
	int key, value, num, i;
	cin >> num;
	for (i = 0; i < num; i++)
	{
		cin >> key >> value;
		key_value[key] += value;
	}
	for (i = 0; i < 10; i++)
	{
		if (key_value[i] != 0)
			cout << i << " " << key_value[i] << endl;
	}
	return 0;
}



---------------------------------
/**
	题目：合并表记录
	要求：数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出
	思路：STL中的map
*/

#include<iostream>
#include<map>
using namespace std;

int main()
{	
	int cnt, index, value;
	while (cin >> cnt)
	{
		map<int, int> union_table;
		while (cin >> index >> value)
		{
			if (union_table.find(index) != union_table.end())
				union_table[index] += value;
			else
				union_table.insert(make_pair(index, value));
			cnt--;
			if (cnt == 0)
				break;
		}
		for (auto it = union_table.begin(); it != union_table.end(); it++)
			cout << it->first << " " << it->second << endl;
	}
	return 0;
}