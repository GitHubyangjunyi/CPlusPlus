// MemberOperators.cpp: 定义控制台应用程序的入口点。
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
	MyPoint operator+(const MyPoint& d)//只有一个参数,该参数并不是第一参数,第一参数是对象本身
	{
		MyPoint s;
		s.set(x + d.x, y + d.y);
		return s;
	}
	friend ostream& operator<<(ostream& o, const MyPoint& d);
};

inline ostream& operator<<(ostream& o, const MyPoint& d)//重载流的<<操作时,返回值也必须是流
{//若<<返回一个非引用型的流,返回时将对cout进行复制,产生一个临时的流,随着<<..<<..重叠操作,会产生性能问题
	return o << "(" << d.x<<"," << d.y << ")\n";//形成流返回,否则cout无法识别自定义的MyPoint类型
}

int main()
{
	MyPoint a, b;
	a.set(3, 2);
	b.set(5, 6);
	a=a.operator+(b);//成员函数调用
	cout << a + b;//这一句包含两个操作符,根据优先级先进行a+b操作,C++将s看作是引导函数(这里是操作符)的对象,随后是函数符号+,在后面是实参b
	//所以也可以写成上面的成员函数调用的样子
	//a+b返回一个MyPoint类型的值,在之前,cout对MyPoint类型是不能理解的,只能理解C++内部数据类型和预定义的string类型,为了让流可以理解MyPoint
	//就必须自定义对MyPoint的流<<操作
    return 0;
}
//操作符也可以作为类中的成员,也就是一种成员函数,这时候,无需使用friend
//成员操作符与普通操作符不同的是,成员操作符声明和定义中省去了第一个参数,因为成员函数总是与对象绑定使用的
//被绑定的对象就是被操作的第一参数,所以单目运算符没有参数,双目运算符有一个参数