// ForStatement.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	for (size_t i = 1; i <= 10; i++)
	{
		for (size_t j = 1; j <= i-1; j++)
		{
			cout << " ";
		}
		for (size_t k = 1; k <= 21-2*i; k++)
		{
			cout << "M";
		}
		cout << endl;
	}
	int n = 27;
	for (size_t i = 1; i <=10; i++)
	{
		for (size_t j = 1; j <=10-i; j++)
		{
			cout << " ";
		}
		for (size_t k = 1; k <=2*i-1; k++)
		{
			cout << char('a' + k - 1);
		}
		cout << "\n";
	}
    return 0;
}

