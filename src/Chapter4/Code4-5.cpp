// Code 4-5

#include <iostream>
using namespace std;
int main()
{
    float  x[100], sum = 0, ave, a;
    int n = 0, i;
    cout << "Input score\n";
    cin >> a;
    while (a >= 0)
    {
        x[n] = a;
        sum += a;
        n++;
        cin >> a;
    }
    ave = sum / n;
    cout << "ave = "<< ave << endl;
    for (i = 0; i < n;i++)
        if (x[i] < ave)
            cout << "x[" << i << "] = " << x[i] << endl;
    return 0;
}
