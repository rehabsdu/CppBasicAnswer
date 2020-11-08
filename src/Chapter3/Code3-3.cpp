// Code 3-3

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, j, k, n, index1 = 0, index2 = 0;
	cout << "please input an intger:";
	cin >> n;
	for (i = 2; i <= n / 2; i++)
		if (n % i == 0)
		{
			cout << "no" << endl; 
			break;
		}
	if (i > n / 2)
		cout << "yes" << endl;
	for (i = 6; i <= n; i += 2)
	{
		for (j = 2; j <= i / 2; j++)

		{
			for (k = 2; k <= j / 2; k++)
				if (j % k == 0) break;
			if (k > j / 2) index1 = 1;
			for (k = 2; k <= (i - j) / 2; k++)
				if ((i - j) % k == 0) break;
			if (k > (i - j) / 2) index2 = 1;
			if (index1 == 1 && index2 == 1)
			{
				cout << i << "=" << j << "+" << i - j << setw(3) << "\t";
				index1 = 0; index2 = 0;
			}

		}
		cout << "\n";
	}
	return 0;
}