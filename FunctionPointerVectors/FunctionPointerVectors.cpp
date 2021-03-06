// FunctionPointerVectors.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

typedef void(*MenuFun)();//定义函数指针类型,如果该语句前面没有typedef则后面部分就是一个函数指针定义
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
	vector<MenuFun> fun(3);//使用向量发挥向量的优势
	fun[0] = f1, fun[1] = f2, fun[2] = f3;
	for (int choice = 1; choice; )
	{
		cout << "1----Good\n"
			<< "2----Better\n"
			<< "3----Best\n"
			<< "0----Exit\n"
			<< "Enter your choice\n";
		cin >> choice;
		if (choice>0&&choice<4)
		{
			fun[choice - 1]();
		}
		else if (choice==0)
		{
			return 0;
		}
		else
		{
			cout << "Wrong key!!!!\n";
		}
	}
}

