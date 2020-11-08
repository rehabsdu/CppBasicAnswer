// Code 7-4

#include <iostream>
using namespace std;

//该程序实现了将数组中的n个数按相反顺序存放
void inv(int x[], int n)
{
	int t, i, j, m = (n - 1) / 2;
	for (i = 0; i <= m; i++)
	{
		j = n - 1 - i;
		t = x[i]; 
		x[i] = x[j];  
		x[j] = t;
	}
}

int main()
{
	int a[10] = { 3,7,9,11,0,6,7,5,4,2 };//定义数组
	int len = sizeof(a) / sizeof(a[0]);//计算数组a中数据长度
	inv(a, len);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << '\t';
	}

	return 0;
}