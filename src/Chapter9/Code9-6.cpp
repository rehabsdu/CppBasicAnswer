// Code 9-6

#include <iostream>
#include <string>
using namespace std;

class tempcheck
{
private:
	string Name;
	int age;
	float temp;
	bool fever, isolated;
public:
	tempcheck()
	{
		fever = 0, isolated = 0;
	}
	void setfev()
	{ 
		fever = 1; 
		cout << "体温过高" << endl;
	}
	void setiso()
	{ 
		isolated = 1; 
		cout << "之前的出行可能存在风险" << endl<<endl;
	}
	void print()
	{
		cout <<Name<< "的体温是" <<temp<<"摄氏度"<< endl;
		while (fever)
		{
			setfev(); break;
		}
		while (isolated)
		{
			setiso(); break;
		}
	}
	tempcheck indata()
	{
		cout << "请依次输入您的姓名，年龄与体温" << endl;
		cin >> Name >> age >> temp;
		while (age <= 0 || age >= 120 || temp < 34 || temp > 43)
		{
			cin.clear(); cin.ignore(100, '\n');
			cout << "请仔细检查您的输入信息" << endl << endl;
			cout << "请依次输入您的姓名，年龄与体温" << endl;
			cin >> Name >> age >> temp;
		}
		if (temp > 37.3)
		{
			char mark;
			setfev();
			cout << "近期是否外出，存在请按1，没有外出请按其他键" << endl;
			cin >> mark;
			while (mark == '1')
			{
				setiso();
				mark = 0;
			}
		}
		else {}

		return *this;
	}
};

int main()
{
	tempcheck* stu = new tempcheck[20];
	int i = 0;
	char s = 1;
	loop:
	cout << "录入信息请按0，结束录入请按其他键" << endl;
	cin >> s;
	if(s=='0')
	{
		stu[i] = stu[i].indata();
		i++;
		goto loop;
	}
	else {}
	int j;
	for (j = 0; j < i; j++)
	{
		stu[j].print();
	}
}