// PointersForcibleAccess.cpp: 定义控制台应用程序的入口点。
//指针的强行访问

#include "stdafx.h"
#include <iostream>
using namespace std;

int a = 5;
int b = 6;

int main()
{
	int* ap = (int*)4202660;
	*ap = 8;
	cout << a << endl;
	cout << int(&b) << endl;
    return 0;
}
//该程序不可移植,运行结果也不可重复