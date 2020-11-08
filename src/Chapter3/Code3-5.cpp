// Code 3-5

#include <iostream>
using namespace std;
int main()
{
    int i = 1, d = 1;
    float s = 0;
    while ((float)i <= 1e06)
    {
        s += (float)d / (i * 2 - 1);
        d = -d;
        i++;
    }
    cout << "PI = " << s * 4 << endl;
    return 0;
}