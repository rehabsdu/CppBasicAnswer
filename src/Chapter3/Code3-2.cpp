// Code 3-2

#include<iostream>
using namespace std;

int main()
{
    char i, j;        
    cout << "Please enter the first letter:" << endl;
    cin >> i;    
    switch (i)
    {
    case 'm':
        cout << "monday" << endl;
        break;
    case 'w':
        cout << "wendesday" << endl;
        break;

    case 'f':
        cout << "friday" << endl;
        break;
    case 't':
        cout << "Please enter the next letter:" << endl;
        cin >> j;              
        {cout << "tuesday" << endl; break; }
        if (j == 'h')
        {
            cout << "thursday" << endl; break;
        }
    case 's':
        cout << "Please enter the next letter:" << endl;
        cin >> j;
        if (j == 'a')
        {
            cout << "satursday" << endl; break;
        }
        if (j == 'u')
        {
            cout << "sunday" << endl; break;
        }
    default:
        cout << "error" << endl;; break;
    }
    return 0;
}