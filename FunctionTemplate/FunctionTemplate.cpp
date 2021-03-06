// FunctionTemplate.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//using namespace std;//不使用这一命名空间是因为这一命名空间下已经由swap函数模板存在,会引起冲突

//void swap(int& a,int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void swap(int a, int b)//测试两个函数同时存在时的情况,不能同时存在
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void swap(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}

//鉴于函数重载还有一定冗余性,或者说麻烦
//通用交换函数定义
//void swap(Type& a, Type& b)
//{
//	Type temp = a;
//	a = b;
//	b = temp;
//}

template<typename T> void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

double add(double a, double b)
{
	return  a + b;
}

int main()
{
	int a = 10, b = 100;
	//swap(&a, &b);错误实参列表
	swap(a, b);
	std::cout << "a=" << a << "\n";
	std::cout << "b=" << b << "\n";
	//苛刻测试
	double d = 5.0;
	swap(a, b);//参数匹配
	std::cout << "苛刻测试" << "\n";
	std::cout << "a=" << a << "\n";
	std::cout << "b=" << b << "\n";
	double x = add(a, d);//普通函数调用,自动隐式转换实现合法调用
	std::cout << "x=" << x << "\n";
	std::cout << "d=" << d << "\n";
	//swap(a, d);//错误,模板参数没有隐式转换,必须精确匹配
	//swap(static_cast<double>(a), d);//错误
	//临时强制转换也不行,传递引用能改变实参数值,不能直接改变实参类型,类型性质不一致,存储空间大小不一致,更多详细信息参阅FunctionTemplateReferenceArgumentsConst项目
	swap(d, x);
	std::cout << "x=" << x << "\n";
	std::cout << "d=" << d << "\n";
    return 0;
}
//template<类型参数表> 返回类型 函数模板名(数据参数列表)
//{
//	函数模板定义体
//}
//类型参数表描述函数模板"函数模板名"的模板形式参数,模板形参是类型形式的,可以是基本数据类型,也可以是类类型
//每个模板形参都必须加上前缀class或typename
//函数模板不是函数,它是以具体的类型为实参来生成函数体的模板
//函数模板不是函数,它是以具体的类型为实参来生成函数体的模板
//函数模板不是函数,它是以具体的类型为实参来生成函数体的模板
//函数模板定义被编译时不会产生任何执行代码,第一次使用函数模板时,会触发编译器产生一个对应函数模板的函数体定义
//根据数据实参的类型->匹配数据形参的类型->确认模板实参->推得模板形参的过程称为数据实参的演绎
//以函数模板名为函数名的调用,以数据实参推演函数模板实参,进而生成模板函数定义的过程称为函数模板的实体化
//模板函数并不是重载函数,其函数名称各不相同,swap<int>就不同于swap<double>
//模板函数并不是重载函数,其函数名称各不相同,swap<int>就不同于swap<double>
//模板函数并不是重载函数,其函数名称各不相同,swap<int>就不同于swap<double>
//一个函数模板生成的都是不同名称的模板函数,模板实参不同,则生成的模板函数也不同
//一个函数模板所反映的是不同函数的函数族群,它们因类型实参不同而不同
//模板函数调用是寻求函数模板的类型参数匹配,类型实参与类型形参的匹配规则
//与函数的数据实参类型与数据形参类型匹配规则不同,类型实参与类型形参匹配规则更为苛刻