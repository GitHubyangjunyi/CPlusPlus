// FunctionTemplateOverloadingTwo.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//using namespace std;

template<typename T> T const& max(T const& a, T const& b)//常量引用型类型
{
	return a < b ? b : a;
}

template<typename T> T* const& max(T* const& a, T* const& b)//常量引用型类型
{
	return *a < *b ? b : a;
}

const char* const& max(const char* const& a, const char* const& b)//该函数不是模板
{
	return std::strcmp(a, b) < 0 ? b : a;
}

int main()
{
	int ia = 3, ib = 7;
	std::string str1 = "hello";
	std::string str2 = "hell";
	std::cout << *max(&ia, &ib) << "\n";//匹配第二个模板
	//cout << max(str1, str2) << "\n";//匹配max函数(书上错误?),匹配第一个模板
	max(str1, str2);//匹配max函数(书上错误?),匹配第一个模板
	std::cout << max(ia, ib) << "\n";//匹配第一个模板
    return 0;
}
//有逻辑错误未排除