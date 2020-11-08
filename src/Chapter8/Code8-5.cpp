// Code 8-5

#include <iostream>
#include <math.h>
using namespace std;

class rectangle
{
    
private:
    int x1, y1, x2, y2;
public:
    rectangle(int a, int b, int m, int n)
    {
        x1 = a; y1 = b; x2 = m; y2 = n;
    }
    int getarea()
    {
        return abs((x2-x1)*(y1-y2));
    }
    
};

int main()
{
    rectangle rect1(2, 6, 8, 4);
    cout << rect1.getarea() << endl;
    
    return 0;
}