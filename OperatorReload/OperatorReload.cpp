// OperatorReload.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MyPoint
{
	int x, y;
public:
	void set(int a, int b)
	{
		x = a, y = b;
	}
	void print()const
	{
		cout << "(" << x << "," << y << ")\n";
	}
	friend MyPoint operator+(const MyPoint& a, const MyPoint& b);
	friend MyPoint add(const MyPoint& a, const MyPoint& b);
};
//作为普通函数是不允许访问私有数据的,但将其在MyPoint类中以friend关键字引导进行函数声明后,编译就会通过

int main()//main函数建议放在最下面,放在最下面会有编译错误,如未定义的标识符,也就是没声明就使用的错误
{
	MyPoint a, b;
	a.set(3, 2);
	b.set(5, 6);
	(a + b).print();
	operator+(a, b).print();
	add(a, b).print();
	return 0;
}

MyPoint operator+(const MyPoint& a, const MyPoint& b)
{
	MyPoint s;
	s.set(a.x + b.x, a.y + b.y);
	return s;
}

MyPoint add(const MyPoint& a, const MyPoint& b)
{
	MyPoint s;
	s.set(a.x + b.x, a.y + b.y);
	return s;
}
//在进行a+b的操作时,实际上是调用了函数operator+(a,b)
//对于双目操作,习惯于将操作符放在两个操作数之间,即表达式的中缀表示法
//所以C++使用了人性化的设计,将a+b转译为对operator+(a,b)的调用
//+是一种操作符,与其他操作符一样,在匹配了某种类型的实参后便可以被编译理解成为确定的行为
//在C++内部已经实现了好几个版本的+操作,因此任何自定义+操作符的行为都是对C++原有+操作的重载
//所以操作符重载只能针对自定义类型,即在操作符定义的参数列表中至少有一个是自定义的类型,因为其他类型之间的操作已经被定义完善了
//例如不能对double进行%,因为本来就是不能%的