// SwitchStatement.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char a;
	cin >> a;
	switch (a)//括号中的表达式只能是整形/字符型或枚举型
	{
	case 'A':cout << "A";
		break;
	case 'B':cout << "B";
		break;
	case 'C':cout << "C";
		break;
	case 'D':cout << "D";
		break;
	default:
		break;
	}
    return 0;
}

