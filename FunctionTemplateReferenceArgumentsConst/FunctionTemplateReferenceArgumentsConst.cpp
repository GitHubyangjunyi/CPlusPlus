// FunctionTemplateReferenceArgumentsConst.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//对于常量引用型参数,可以通过显式模板类型指定来规定调用代码
//对于调用中的几个数据实参类型不同,而数据形参类型却要求相同时
//用显式模板类型指定的方法是必要的,否则模板参数将拒绝匹配

template<typename T> T const& max(T const& a, T const& b)//(T const& a, T const& b)常量引用型类型
{
	return a < b ? b : a;
}
//常量引用型参数,即在引用型参数前加上const,其数据形参值不允许改变,因而不会改变数据实参的值
//注意:数据形参值不允许改变,因而不会改变数据实参的值

int main()
{
	int a = 3;
	double d = 5.0;
	cout << max<double>(a, d) << "\n";//max<double>确定函数模板名,使其成为普通函数,服从普通函数的匹配规则,实现隐式转换
	cout << max(static_cast<double>(a), d) << "\n";
	cout << max((double)a, d) << "\n";
    return 0;
}
//显式模板类型指定可以显示指定模板的类型实参,从而也就规定了数据形参的类型,免去数据实参的演绎,同时也给出了函数模板名
//虽然前提是能够实现隐式转换,但如果是下面这样的调用,再怎么显式指定模板类型实参,也不能通过编译
//因为指针&a不能隐式转换为double
//max<double>(&a,d)//错误
//当然还可以预先将数据实参转换成预料的数据实参演绎所需要的类型
//cout << max(static_cast<double>(a), d) << "\n";