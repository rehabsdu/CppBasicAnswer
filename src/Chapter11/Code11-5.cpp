// Code 11-5

#include <iostream>
#include <string>
using namespace std;

class Person
{
	int num;
	string name;
	string gender;
public:
	Person(int n, string na, string g)
	{
		num = n; 
		name = na; 
		gender = g;
	}
	int Getnum() { return num; }
	string Getname() { return name; }
	string Getgender() { return gender; }
	void Show()
	{
		cout << '\n' <<"姓名: " << name << '\n' << "编号: " << num << '\n'  << "性别: " << gender << '\n';
	}
};
class Teacher:public Person
{
	string department;
	string title;
public:
	Teacher(int n, string na, string g, string d, string t) : Person(n, na, g)
	{
		department = d;
		title = t;
	}
	void ShowTe()
	{
		Show();
		cout << "部门: " << department << '\n' << "职称: " << title << '\n';
	}

};
class Student :public Person
{
	int gradenum;
	int score;
public:
	Student(int n, string na, string g, int gn, int s) :Person(n, na, g)
	{
		gradenum = gn;
		score = s;
	}
	void showSt()
	{
		Show();
		cout << "年级号: " << gradenum << '\n' << "分数: " << score << '\n';
	}
};

int main()
{
	Teacher chen(15, "陈枫", "女", "英语", "教授");
	Student wang(58, "王明", "男", 2, 95);
	chen.ShowTe();
	wang.showSt();
}