// Code 3-1

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	float a, b, c, d;
	cout << "Please enter the length of the three sides:" << endl;
	cin >> a >> b >> c;
	d = (a + b + c) / 2;
	if (a + b > c && a + c > b && b + c > a) //三角形任意两边之和大于第三边
	{
		if (a == b && b == c) //三条边边长相等
			cout << "Equilateral Triangle" << "," << "area is " << sqrt(3) / 4 * a * a << "," << "perimeter is " << 3 * a << endl;//S△ABC=√3/4a²是等边三角形的面积公式
		else if (a == b || b == c || a == c)
			cout << "Isosceles Triangle" << "," << "area is " << sqrt(d * (d - a) * (d - b) * (d - c)) << "," << "perimeter is " << a + b + c << endl;//面积计算用海伦公式
		else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
			cout << "Right Triangle" << "," << "area is " << sqrt(d * (d - a) * (d - b) * (d - c)) << "," << "perimeter is " << a + b + c << endl;
		else
			cout << "General Triangle" << "," << "area is " << sqrt(d * (d - a) * (d - b) * (d - c)) << "," << "perimeter is " << a + b + c << endl;
	}
	else
		cout << "The three input sides cannot form a triangle" << endl;
	return 0;
}