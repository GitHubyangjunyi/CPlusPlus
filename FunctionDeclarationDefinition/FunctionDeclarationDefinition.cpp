// FunctionDeclarationDefinition.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void sphere();

int main()
{
	sphere();
    return 0;
}

void sphere() {
	std::cout << "Please input radius:";
	cout << "Please input radius:";
	double radius;
	//程序中使用了using namespace std;,使得后面的名称如果没有现场定义,则会自动到std名空间去找
	cin >> radius;
	if (radius<0)
	{
		return;
	}
	cout << "The result is:"<<radius*radius*3.14;
}