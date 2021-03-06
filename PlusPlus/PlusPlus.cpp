// PlusPlus.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;

class MyTime
{
	int hour, minute, second;
public:
	void set(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	friend MyTime& operator++(MyTime& a);
	friend MyTime operator++(MyTime& a,int);
	friend ostream& operator<<(ostream& o, const MyTime& t);
};

MyTime& operator++(MyTime& a)//前增量操作符
{
	if (!(a.second=(a.second+1)%60)&&!(a.minute=(a.minute+1)%60))
	{
		a.hour = (a.hour + 1) % 24;
	}
	return a;
}

MyTime operator++(MyTime& a, int)//后增量操作符,其中第二个参数int不能改成int a
{
	MyTime t(a);
	if (!(a.second = (a.second + 1) % 60) && !(a.minute = (a.minute + 1) % 60))
	{
		a.hour = (a.hour + 1) % 24;
	}
	return t;
}

ostream& operator<<(ostream& o, const MyTime& t)
{
	o << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.minute << ":" << setw(2) << t.second << "\n";
	return o << setw(2) << t.second << "\n" << setfill(' ');
}

int main()
{
	MyTime t;
	t.set(11, 59, 58);
	cout << t++;
	cout << ++t;
	//临时代码测试
	//begin
	int x = 1, y = 1, z = 1, w = 1;
	(++x)++;
	cout << x;
	//(y++)++;//错误,原因如下
	cout << y;
	++(++z);
	cout << z;
	//++(w++);//错误,原因如下
	cout << w;
	//end
    return 0;
}
//增量操作符有前增量和后增量之区别
//重载增量操作符时,虽然操作符相同,但是功能不同,应有前后的差别,所以反映在参数类型或个数或次序上
//其次为了反映操作的本质,返回类型的表现也可以不同
//一个整型变量的前增量操作的结果与变量值是一致的,而且前增量的操作的结果是左值,操作可以连贯
//而后增量操作的结果是增量之前的变量值,它是临时变量,当表达式计算完成后,该变量立刻消失,所以变量最终值是与后增量结果错位的
//所以前增量操作数与返回值是同一个变量,在反映对象的前增量操作时,要求参数为对象的引用,返回的还是该对象参数的引用
//后增量操作符重载,同样要求参数为对象的引用,因为在调用的上下文中,实参将发生变化,而返回则为临时对象,所以为非引用的对象值
//但因为两个操作符声明的参数相同,所以得做一个技术处理,让函数参数列表不同