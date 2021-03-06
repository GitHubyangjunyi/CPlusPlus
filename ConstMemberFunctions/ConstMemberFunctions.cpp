// ConstMemberFunctions.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

//调用成员函数可以使用
//objectName.memberFunctionName(parameters);
//如果对象是以对象指针间接访问形式操作的,则对象与成员函数就用双字符的箭头->
//objectPointer->memberFunctionName(parameters);
//或者将对象指针的间接访问形式用括号括起来
//(*objectPointer).memberFunctionName(parameters);

class MyDate
{
	int year, month, day;
public:
	void set(int y, int m, int d)//使用默认内联
	{
		year = y;
		month = m;
		day = d;
	}
	bool isLeapYear()const;//常成员函数声明
	void print()const;
	MyDate();
	~MyDate();
};

inline bool MyDate::isLeapYear()const//显示内联常成员函数
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void MyDate::print()const//函数体较为复杂,定义在外面的常成员函数
{
	cout.setf('0');
	cout << setw(4) << year << '-' << setw(2) << month << '-' << setw(2) << day << '\n';
	cout.setf(' ');
}

MyDate::MyDate()
{
}

MyDate::~MyDate()
{
}

int main()
{
	MyDate* dp = new MyDate();
	dp->set(2000, 6, 12);
	if (dp->isLeapYear())
	{
		(*dp).print();
	}
	return 0;
}

