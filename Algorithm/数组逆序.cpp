#include<iostream>
using namespace std;
int main()
{
	int a[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5 / 2; i++)
	{
		int k = a[i];
		a[i] = a[5 - i - 1];
		a[5 - i - 1] = k;
	}
	for (int j = 0; j < 5; j++)
	{
		cout << a[j] << " ";
	}
	return 0;
}



//-------------------------------------
#include<iostream>
using namespace std;
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 0 };
	for (int i = 0; i < 5; i++)
		b[i] = a[5 - i - 1];
	for (int k = 0; k < 5; k++)
		a[k] = b[k];
	for (int j = 0; j < 5; j++)
	{
		cout << a[j] << " ";
	}
	return 0;
}