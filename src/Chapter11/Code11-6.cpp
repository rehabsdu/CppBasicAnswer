// Code 11-6

#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

class Circle
{
	double radius;
public:
	Circle(double r) 
	{
		radius = r;
	}
	double Getperimeter()
	{
		return 2 * M_PI * radius;
	}
	double Getarea()
	{
		return M_PI * pow(radius, 2);
	}
	double Getvolume()
	{
		return M_PI * pow(radius, 3);
	}
	void ShowCircle()
	{
		cout << "Circle : " << '\n';
		cout << "radius = " << radius << '\n' << "perimeter = " << Getperimeter() << '\n';
		cout << "area = " << Getarea() << '\n' << "volume = " << Getvolume() << '\n';
	}
};

class Cylinder : public Circle
{
	double height;
public: 
		Cylinder(double r,double h):Circle(r)
		{
			height = h;
		}
		double GetvolumeCy()
		{
			return Getarea() * height;
		}
		void ShowCylinder()
		{
			cout <<'\n'<< "The volume of this cylinder is : " << Getvolume() << endl;
		}
};

int main()
{
	Circle ci(5);
	Cylinder cy(4, 5);
	ci.ShowCircle();
	cy.ShowCylinder();
	return 0;
}