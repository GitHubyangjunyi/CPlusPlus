// ConditionalExpressions.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int x = 0;
	int a=0, b=0;
	if (x)
	{
		a = 1;
	}
	else
	{
		b = 1;
	}
	(x ? a : b) = 1;//它是C++中唯一的三元运算符
	cout << a<<"\n";
	cout << b<<"\n";
	x ? a : b = 1;
	cout << a<<"\n";
	cout << b<<"\n";
    return 0;
}

