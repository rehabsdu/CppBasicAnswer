// Code 2-4

#include <iostream>
using namespace std;

const int BOUND = INT32_MAX / 10;

int main()
{
	int a;
	while (cin >> a) {
		cout << (a > BOUND ? -1 : a) << endl;
	}
	return 0;
}