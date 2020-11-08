// Code 5-4

#include<iostream>
using namespace std;

int main()
{
	int m;
	int n;
	int r;
	cout << "运算矩阵A和矩阵B相乘" << endl;
	cout << "请输入矩阵A的行数和列数：" << endl;
	cout << "矩阵A的行数：";
	cin >> m;
	cout << "矩阵A的列数：";
	cin >> n;
	cout << "矩阵B的列数：";
	cin >> r;
	cout << endl;

	//取m的地址赋值给指针x
	int *x = &m;
	int *y = &n;
	int *z = &r;

	//把变量m赋值给地址x对应的值
	*x = m;
	*y = n;
	int **a = new int*[*y];
	for (int i = 0; i < *x; i++) 
	{
		*(a + i) = new int[*x];
	}

	int **b = new int*[*z];
	for (int i = 0; i < *y; i++) 
	{
		*(b + i) = new int[*y];
	}

	int **c = new int*[*z];
	for (int i = 0; i < *x; i++) 
	{
		*(c + i) = new int[*x];
	}

	for (int i = 0; i < *x; i++) 
	{
		for (int j = 0; j < *z; j++) 
		{
			*(*(c + i) + j) = 0;
		}
	}

	cout << "请输入矩阵A:" << endl;
	for (int i = 0; i < *x; i++) 
	{
		for (int j = 0; j < *y; j++) 
		{
			cin >> *(*(a + i) + j);
		}
	}

	cout << "请输入矩阵B:" << endl;

	for (int i = 0; i < *y; i++) 
	{
		for (int j = 0; j < *z; j++)
		{
			cin >> *(*(b + i) + j);
		}
	}

	for (int i = 0; i < *x; i++) 
	{
		for (int j = 0; j < *z; j++) 
		{
			for (int k = 0; k < *y; k++) 
			{
				*(*(c + i) + j) = *(*(c + i) + j) + (*(*(a + i) + k)**(*(b + k) + j));
			}
		}
	}

	cout << "矩阵A乘以矩阵B的结果：" << endl;
	for (int i = 0; i < *x; i++)
	{
		for (int j = 0; j < *z; j++)
		{
			cout << *(*(c + i) + j) << "\t";
		}
		cout << endl << endl;
	}

	return 0;
}