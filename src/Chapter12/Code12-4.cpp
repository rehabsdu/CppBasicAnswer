// Code 12-4

#include <iostream>
using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	Person(string na, int a)
	{
		name = na;
		age = a;
	}
	string Getname() { return name; }
	int Getage() { return age; }
	void Show()
	{
		cout << '\n' << "姓名 ： " << name << '\n' << "年龄 ： " << age << '\n';
	}
};
class Teacher :virtual public Person
{
	int classhour;
	int classfee;
public:
	Teacher(string na, int a, int ch, int cf) : Person(na, a)
	{
		classhour = ch;
		classfee = cf;
	}
	int Salary()
	{
		return classhour * classfee;
	}
	void ShowTe()
	{
		cout << '\n' << "课时数 ： " << classhour << '\n' << "课时费 ： " << classfee << '\n';
		cout << '\n' << "工资 ： " << Salary() << endl;
	}
};
class Student :virtual public Person
{
	int num;
public:
	Student(string na, int a, int nu) :Person(na, a)
	{
		num = nu;
	}
	int Getnum() { return num; }
	void ShowSt()
	{
		cout << '\n' << "学号 ： " << num << '\n';
	}
};

class Assistant:public Teacher,public Student
{
public:
	Assistant(string n, int a, int ch, int cf, int nu) :Person(n, a), Teacher(n, a, ch, cf), Student(n, a, nu) {};

};
int main()
{
	Assistant zhang("章洋", 23, 35, 50, 56);
	zhang.Show();
	zhang.ShowSt();
	zhang.ShowTe();
}