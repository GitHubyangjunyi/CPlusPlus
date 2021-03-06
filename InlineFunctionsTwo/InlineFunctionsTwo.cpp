// InlineFunctionsTwo.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


inline bool isnumber(char);//内联声明
//内联声明必须在函数调用前,因为内联函数的代码在程序运行时是直接嵌在调用处执行的,不影响链接
//在编译时确定代码,如果将声明处的inline放到函数定义处,编译并不会认为那是内联函数,对待isnumber就像普通函数一样
//产生该函数的调用代码并进行链接

int main()
{
	char c;
	while (cin >> c && c != '\n')
	{
		if (isnumber(c))//反复调用小函数
		{
			cout << "you enter a digit\n";
		}
		else
		{
			cout << "you enter a non-digit\n";
		}
	}
	return 0;
}

bool isnumber(char ch)//inline bool isnumber(char ch)//如果声明时没有使用inline,而在定义处使用,编译不认为这是内联函数
{
	return ch >= '0'&&ch <= '9' ? 1 : 0;
}
//在内联函数中不能含有复杂的控制语句,比如switch/while
//如果内联函数有这些语句,编译器将无视内联声明
//递归函数属于复杂函数,也不能用来内联
//编程时函数虽然打上内联标记,却并不是总被编译成内联方式