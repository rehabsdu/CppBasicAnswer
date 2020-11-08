// Code 3-4

#include <iostream>
using namespace std;

int main()
{
	int m, n, r;
	cout << "Please enter two integers:" << endl;
	cin >> m >> n;
	r = m % n;

    while (r != 0) {
        m = n;
        n = r;
        r = m % n;
    }
    cout << "The greatest common divisor is " << n << endl;
    return 0;
}