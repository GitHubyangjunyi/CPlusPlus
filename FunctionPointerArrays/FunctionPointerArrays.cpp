// FunctionPointerArrays.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef void (*MenuFun)();//定义函数指针类型,如果该语句前面没有typedef则后面部分就是一个函数指针定义
//正因为有了typedef,所以MenuFun就是函数指针类型名,但其本身并不是函数指针

void f1()
{
	cout << "Good\n";
}

void f2()
{
	cout << "Better\n";
}

void f3()
{
	cout << "Best\n";
}

int main()
{
	MenuFun fun[] = { f1,f2,f3 };
	for (int choice = 1; choice ; )
	{
		cout << "1----Good\n"
			<< "2----Better\n"
			<< "3----Best\n"
			<< "0----Exit\n"
			<< "Enter your choice\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			fun[0]();
			break;
		case 2:
			fun[1]();
			break;
		case 3:
			fun[2]();
			break;
		case 0:
			return 0;
		default:cout << "Wrong key!!!!\n";
			break;
		}
	}
}

