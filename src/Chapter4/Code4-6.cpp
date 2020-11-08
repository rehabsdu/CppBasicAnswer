// Code 4-6

#include <iostream>
using namespace std;
int main()
{
	int i, a[8], n=8, t;
	cout << "Please input scores of eight students" << endl;
	for (i = 0;i < 8;i++)
		cin >> a[i];

	for (int j = 1; j < n; j++)
		for (i = 0; i < n - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}

	cout << "The scores in adjusted order" << endl;
	for (i = 0;i < 8;i++)
		cout << a[i] << '\t';	
	cout << endl;
	return 0;
}