// Code 7-6

#include <iostream>
using namespace std;

int fib(int n);//函数的声明

int main()
{
    int n;
    cout << "Please input n : ";
    cin >> n;
    cout << "fib(" << n << ") = " << fib(n) << endl;

    return 0;
}

int fib(int n)//函数的定义
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 2) + fib(n - 1);
}