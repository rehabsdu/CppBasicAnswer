// Code 7-5

#include <iostream>
using namespace std;

//该程序实现了将数组中的n个数按相反顺序存放
void  inv(int* x, int n)
{
	int* p, t, * i, * j, m = (n - 1) / 2;
	i = x; j = x + n - 1; p = x + m;
	for (; i <= p; i++, j--)
	{
		t = *i;  
		*i = *j; 
		*j = t;
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