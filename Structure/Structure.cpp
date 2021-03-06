// Structure.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

//函数定义体的花括号外是没有分号的,而类定义体外是有分号的,这是C语言的历史原因
//class的机制是在struct基础上改建的,必须与struct对应
//事实上C++也将struct纳入类机制中,也就是说struct也可以像class那样包含成员函数
//struct与class的区别仅仅在于关键字和默认的访问控制不同
//struct默认访问控制符是public,而class默认是private
//类的方法可以在类定义内定义,也可以在类定义外定义
//只要是在类定义内中的成员函数,就默认声明内联
//也就是说该成员函数处于被编译自动安排到最佳运行性能的状态,所以为了获得最佳性能,应尽量将成员函数写入类的定义中
//另一方面,将成员函数写入类的定义中就会使得类定义体的大小不可预见,且成员函数能否内联还要看编译器安排
//对于不符合内联要求的,必要的开销还是要的,所以成员函数在内在外要有所考量,如下
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
	bool isLeapYear();
	void print();
	MyDate();
	~MyDate();
};

inline bool MyDate::isLeapYear()//显示内联
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void MyDate::print()//函数体较为复杂,定义在外面
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
//从这开始看
struct Date
{
	int year;
	int month;
	int day;
};

void print(Date);
bool isLeapYear(Date d);

int main()
{
	Date d;
	d.year = 2000;
	d.month = 12;
	d.day = 6;
	if (isLeapYear(d))
	{
		print(d);
	}
	//////////MyDate类的测试//////////
	MyDate md;
	md.set(2000,6,12);
	if (md.isLeapYear())
	{
		md.print();
	}
    return 0;
}

void print(Date s)
{
	cout.setf('0');
	cout << setw(4) << s.year << '-' << setw(2) << s.month << '-' << setw(2) << s.day << '\n';
	cout.setf(' ');
}

bool isLeapYear(Date d)
{
	return (d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0);
}
//同样是isLeapYear和print函数,成员函数无需提供日期类参数,而普通函数需要日期类参数
//成员函数在调用时捆绑了对象,其实已经含有对象参数了.而普通函数调用时不捆绑对象,为了得到对象信息,需要明确传递对象参数
//普通操作符重载和成员操作符重载的区别也在这里