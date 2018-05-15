// ComputationExpressing.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	//逗号表达式,其值为最后一个表达式的值
	int a, b;
	int d = (a = 2, b = a + 5, a*b);
	cout << d;
	//左值与右值
	//左值与右值是相对于赋值表达式而言的,左值是能出现在赋值表达式左边的表达式,左值表达式不但具有空间实体,还有读写访问权
	//右值是能出现在赋值表达式左右边的表达式,可以是不占据内存空间的临时量或字面量,还可以是不具有写入权的实体
	int x = 3;
	const int y = 5;
	a = y + 2;
	//y = a + 2;//y拥有空间但是无写入权,不能做左值
    return 0;
}

