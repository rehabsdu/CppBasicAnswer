// Code 4-2

#include <iostream>
using namespace std;
int main()
{
    int i, a[8];
    for (i = 0;i <= 7;i++)
        a[i] = i * i;
    
    for (i = 0;i<=7;i++)
        cout << a[i] << '\t';	
    cout << endl;
    return 0;
}