// FunctionTemplateReferenceArguments.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

//对于引用型形参,由于要求数据形参与数据实参的捆绑(互为别名)
//访问数据形参就是访问数据实参,因此要求数据实参应为左值表达式,不能是常量或字面值,
//常量无法更改,字面值无法取得地址
template<typename T>void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> T const& maxc(T const& a, T const& b)//常量引用型形参,如果把const去掉,将会报错
{
	return a < b ? b : a;
}

template<typename T> T max(T& a, T& b)
{
	return a < b ? b : a;
}

int main()
{
	int i = 3;
	const int ci = 5;
	//swap(i, ci);//错误
	//swap(i, 7);//错误
	//swap<int>(i, 7);//错误
	//swap(ci, 7);//错误
	//swap<const int>(i, 7);
	//因为语句int& b=7;和int& b=ci;
	//在标准C++式不被接受的,所以不能进行数据实参到数据形参的引用初始化
	//或者说不能进行数据实参类型到数据形参类型的匹配
	//即使是显式指定模板类型实参,如第三个错误
	const int cx = 3;//有没有const不影响
	double d = 5.0;
	std::cout << maxc<double>(cx, d) << "\n";//maxc<double>确定函数模板名,使其成为普通函数,服从普通函数的匹配规则,实现隐式转换
	std::cout << maxc(static_cast<double>(cx), d) << "\n";
	//无限定引用
	int x = 10, y = 100;
	std::cout << max(x, y) << "\n";
    return 0;
}

