// FunctionTemplateOverloading.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
//using namespace std;

//在max函数模板中,其数据参数进行了operator<运算,但并不是一切数据类型都拥有operator<运算
//当max模板接受的类型不具有operator<运算操作时,该类型的对象就不适合调用max模板
//于是就得重载max函数或max模板
//例如,求两个C串的较大串,一般使用库函数调用来完成的,若根据下面的max函数模板
//调用max("hello", "good");此时两个字符串将被演绎成char*类型
//也就是指针a指向第一个C串,指针b指向第二个C串,这是只是两个指针在比较大小,不能真实反映两个字串的大小
template<typename T> T const& max(T const& a, T const& b)//常量引用型类型
{
	return a < b ? b : a;
}
//为了安全地用好通用模板,由照顾到某种特殊用法,比较折衷的方法就是要为特殊类型重载max函数模板
//对于C串的情况,可以重载另一个函数实现<比较,该操作可以调用strcmp来完成
//设这两个字符串为str1/str2,若str1==str2则返回零,若str1<str2,则返回负数,若str1>str2,则返回正数
const char* const& max(const char* const& a, const char* const& b)//该函数不是模板
{
	return std::strcmp(a, b) < 0 ? b : a;
}
//模板机制规定,如果一个调用既匹配普通函数,又匹配模板函数,则先匹配普通函数
//接下去的问题是,如果是任何指针所指向的实体的max操作,那就需要间接访问之后再进行比较
//因此在下面的调用中
void f(int* ix, int* iy, double* dx, double* dy)
{
	int* ip = max(ix, iy);
	double* dp = max(dx, dy);
}

template<typename T> T* const& maxx(T* const& a, T* const& b)//常量引用型类型
{
	return *a < *b ? b : a;
}


int main()
{
	int x = 10, y = 1000;
	std::string str1 = "xxxxxx";
	std::string str2 = "yyy";
	std::cout << max(x, y) << "\n";//结果与实际相符
	std::cout << max(str1, str2) << "\n";//结果与实际不符
	std::cout << *maxx(&x, &y) << "\n";//结果与实际相符
	std::cout << *maxx(&str1, &str2) << "\n";//结果与实际不符
	//std::cout << max(str1, str2);//错误匹配
    return 0;
}